#include "xbe_loader.h"
#include <cstdio>
#include <cstring>
#include <x86_config.h>

// XBE header offsets
static constexpr uint32_t XBE_MAGIC          = 0x48454258; // "XBEH" little-endian
static constexpr size_t   XBE_OFF_BASE_ADDR  = 0x0104;
static constexpr size_t   XBE_OFF_NUM_SECTS  = 0x011C;
static constexpr size_t   XBE_OFF_SECT_HDRS  = 0x0120;

// XBE section header layout (56 bytes)
struct XbeSectionHeader
{
    uint32_t flags;
    uint32_t virtualAddr;
    uint32_t virtualSize;
    uint32_t rawAddr;       // file offset
    uint32_t rawSize;
    uint32_t sectionNameAddr;
    uint32_t sectionNameRefCount;
    uint32_t headSharedRefCountAddr;
    uint32_t tailSharedRefCountAddr;
    uint8_t  digest[20];
};
static_assert(sizeof(XbeSectionHeader) == 56);

template<typename T>
static T ReadAt(FILE* f, size_t offset)
{
    T val{};
    fseek(f, static_cast<long>(offset), SEEK_SET);
    fread(&val, sizeof(T), 1, f);
    return val;
}

bool LoadXbeImage(const char* xbePath, uint8_t* guestBase)
{
    FILE* f = fopen(xbePath, "rb");
    if (!f)
    {
        fprintf(stderr, "[XBE] Cannot open: %s\n", xbePath);
        return false;
    }

    // Verify magic
    uint32_t magic = ReadAt<uint32_t>(f, 0);
    if (magic != XBE_MAGIC)
    {
        fprintf(stderr, "[XBE] Bad magic: 0x%08X (expected 0x%08X)\n", magic, XBE_MAGIC);
        fclose(f);
        return false;
    }

    uint32_t baseAddr    = ReadAt<uint32_t>(f, XBE_OFF_BASE_ADDR);
    uint32_t numSections = ReadAt<uint32_t>(f, XBE_OFF_NUM_SECTS);
    uint32_t sectHdrsVA  = ReadAt<uint32_t>(f, XBE_OFF_SECT_HDRS);

    // Section headers are in the header area, so file offset = VA - base
    uint32_t sectHdrsFileOff = sectHdrsVA - baseAddr;

    fprintf(stdout, "[XBE] Base address: 0x%08X\n", baseAddr);
    fprintf(stdout, "[XBE] Sections: %u\n", numSections);

    if (numSections > 256)
    {
        fprintf(stderr, "[XBE] Unreasonable section count: %u\n", numSections);
        fclose(f);
        return false;
    }

    // Load the XBE header into guest memory at the base address first.
    // Some programs reference the XBE header for imports or TLS.
    {
        uint32_t headerSize = ReadAt<uint32_t>(f, 0x0108);
        if (headerSize > 0 && headerSize <= 0x10000 &&
            baseAddr + headerSize <= X86_RAM_SIZE)
        {
            fseek(f, 0, SEEK_SET);
            fread(guestBase + baseAddr, 1, headerSize, f);
            fprintf(stdout, "[XBE]   Header: %u bytes loaded at guest 0x%06X\n",
                    headerSize, baseAddr);
        }
    }

    // Load each section (overwrites any overlapping header data).
    for (uint32_t i = 0; i < numSections; i++)
    {
        XbeSectionHeader sh{};
        fseek(f, static_cast<long>(sectHdrsFileOff + i * sizeof(sh)), SEEK_SET);
        fread(&sh, sizeof(sh), 1, f);

        // Section virtual addresses are absolute Xbox addresses.
        // The recompiled code uses them directly as guest memory offsets.
        uint32_t guestOffset = sh.virtualAddr;

        // Sanity checks
        if (guestOffset + sh.virtualSize > X86_RAM_SIZE)
        {
            fprintf(stderr, "[XBE] Section %u: VA 0x%08X + size 0x%X exceeds guest RAM, skipping.\n",
                    i, sh.virtualAddr, sh.virtualSize);
            continue;
        }

        // Zero-fill the virtual range first (handles BSS-style padding)
        memset(guestBase + guestOffset, 0, sh.virtualSize);

        // Copy raw data from file
        uint32_t copySize = sh.rawSize;
        if (copySize > sh.virtualSize)
            copySize = sh.virtualSize;

        if (copySize > 0 && sh.rawAddr > 0)
        {
            fseek(f, static_cast<long>(sh.rawAddr), SEEK_SET);
            size_t read = fread(guestBase + guestOffset, 1, copySize, f);
            if (read != copySize)
            {
                fprintf(stderr, "[XBE] Section %u: short read (%zu / %u bytes)\n",
                        i, read, copySize);
            }
        }

        fprintf(stdout, "[XBE]   Section %u: VA 0x%08X  VSize 0x%06X  RawOff 0x%06X  RawSize 0x%06X\n",
                i, sh.virtualAddr, sh.virtualSize, sh.rawAddr, sh.rawSize);
    }

    fclose(f);
    fprintf(stdout, "[XBE] Image loaded successfully.\n\n");
    return true;
}

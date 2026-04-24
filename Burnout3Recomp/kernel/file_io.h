#pragma once

#include <cstdint>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <mutex>
#include <string>
#include <string_view>
#include <vector>
#include "xdm.h"

// ---------------------------------------------------------------------------
// NTSTATUS codes (prefixed to avoid Windows header conflicts)
// ---------------------------------------------------------------------------
static constexpr uint32_t X_STATUS_SUCCESS                = 0x00000000;
static constexpr uint32_t X_STATUS_BUFFER_OVERFLOW        = 0x80000005;
static constexpr uint32_t X_STATUS_NO_MORE_FILES          = 0x80000006;
static constexpr uint32_t X_STATUS_INVALID_HANDLE         = 0xC0000008;
static constexpr uint32_t X_STATUS_INVALID_PARAMETER      = 0xC000000D;
static constexpr uint32_t X_STATUS_NO_SUCH_FILE           = 0xC000000F;
static constexpr uint32_t X_STATUS_END_OF_FILE            = 0xC0000011;
static constexpr uint32_t X_STATUS_OBJECT_NAME_NOT_FOUND  = 0xC0000034;
static constexpr uint32_t X_STATUS_OBJECT_PATH_NOT_FOUND  = 0xC000003A;
static constexpr uint32_t X_STATUS_NOT_IMPLEMENTED        = 0xC0000002;

// ---------------------------------------------------------------------------
// FILE_INFORMATION_CLASS (subset used by OG Xbox titles)
// ---------------------------------------------------------------------------
enum XboxFileInformationClass : uint32_t
{
    FileDirectoryInformation        = 1,
    FileBasicInformation            = 4,
    FileStandardInformation         = 5,
    FilePositionInformation         = 14,
    FileNetworkOpenInformation      = 34,
};

// ---------------------------------------------------------------------------
// NT CreateDisposition values (prefixed to avoid Windows header conflicts)
// ---------------------------------------------------------------------------
static constexpr uint32_t X_FILE_SUPERSEDE    = 0;
static constexpr uint32_t X_FILE_OPEN         = 1;
static constexpr uint32_t X_FILE_CREATE       = 2;
static constexpr uint32_t X_FILE_OPEN_IF      = 3;
static constexpr uint32_t X_FILE_OVERWRITE    = 4;
static constexpr uint32_t X_FILE_OVERWRITE_IF = 5;

// ---------------------------------------------------------------------------
// NT CreateOptions flags
// ---------------------------------------------------------------------------
static constexpr uint32_t X_FILE_DIRECTORY_FILE = 0x00000001;

// ---------------------------------------------------------------------------
// DesiredAccess flags
// ---------------------------------------------------------------------------
static constexpr uint32_t XBOX_GENERIC_READ    = 0x80000000;
static constexpr uint32_t XBOX_GENERIC_WRITE   = 0x40000000;
static constexpr uint32_t XBOX_FILE_READ_DATA  = 0x00000001;
static constexpr uint32_t XBOX_FILE_WRITE_DATA = 0x00000002;
static constexpr uint32_t XBOX_FILE_APPEND_DATA = 0x00000004;

// ---------------------------------------------------------------------------
// Guest structures (OG Xbox, little-endian, x86)
// ---------------------------------------------------------------------------
// These are read directly from guest memory via raw pointer casts.

#pragma pack(push, 1)

struct XBOX_ANSI_STRING
{
    uint16_t Length;
    uint16_t MaximumLength;
    uint32_t Buffer; // guest pointer
};

struct XBOX_OBJECT_ATTRIBUTES
{
    uint32_t RootDirectory; // HANDLE (guest)
    uint32_t ObjectName;    // guest pointer to XBOX_ANSI_STRING
    uint32_t Attributes;
};

struct XBOX_IO_STATUS_BLOCK
{
    uint32_t Status;      // NTSTATUS or Pointer
    uint32_t Information; // bytes transferred, etc.
};

struct XBOX_FILE_BASIC_INFORMATION
{
    int64_t  CreationTime;
    int64_t  LastAccessTime;
    int64_t  LastWriteTime;
    int64_t  ChangeTime;
    uint32_t FileAttributes;
};

struct XBOX_FILE_STANDARD_INFORMATION
{
    int64_t  AllocationSize;
    int64_t  EndOfFile;
    uint32_t NumberOfLinks;
    uint8_t  DeletePending;
    uint8_t  Directory;
};

struct XBOX_FILE_POSITION_INFORMATION
{
    int64_t CurrentByteOffset;
};

struct XBOX_FILE_NETWORK_OPEN_INFORMATION
{
    int64_t  CreationTime;
    int64_t  LastAccessTime;
    int64_t  LastWriteTime;
    int64_t  ChangeTime;
    int64_t  AllocationSize;
    int64_t  EndOfFile;
    uint32_t FileAttributes;
};

struct XBOX_FILE_DIRECTORY_INFORMATION
{
    uint32_t NextEntryOffset;
    uint32_t FileIndex;
    int64_t  CreationTime;
    int64_t  LastAccessTime;
    int64_t  LastWriteTime;
    int64_t  ChangeTime;
    int64_t  EndOfFile;
    int64_t  AllocationSize;
    uint32_t FileAttributes;
    uint32_t FileNameLength;
    // char FileName[1]; // variable length, follows immediately
};

#pragma pack(pop)

// File attribute flags.
static constexpr uint32_t XBOX_FILE_ATTRIBUTE_READONLY  = 0x00000001;
static constexpr uint32_t XBOX_FILE_ATTRIBUTE_DIRECTORY = 0x00000010;
static constexpr uint32_t XBOX_FILE_ATTRIBUTE_NORMAL    = 0x00000080;

// ---------------------------------------------------------------------------
// FileHandle — wraps a std::fstream for NtCreateFile / NtReadFile / etc.
// ---------------------------------------------------------------------------

struct FileHandle final : KernelObject
{
    std::fstream stream;
    std::filesystem::path hostPath;
    bool isDirectory = false;

    // For NtQueryDirectoryFile enumeration
    std::vector<std::filesystem::directory_entry> dirEntries;
    size_t dirEnumIndex = 0;
    bool dirEnumDone = false;

    bool Wait(uint32_t /*timeoutMs*/) override { return true; }

#ifdef _WIN32
    HANDLE GetNativeHandle() override { return INVALID_HANDLE_VALUE; }
#endif
};

// ---------------------------------------------------------------------------
// Xbox path → host path translation
// ---------------------------------------------------------------------------
// OG Xbox uses paths like:
//   \Device\CdRom0\maps\map01.wad      →  <gameDir>/maps/map01.wad
//   \??\D:\maps\map01.wad              →  <gameDir>/maps/map01.wad
//   D:\maps\map01.wad                  →  <gameDir>/maps/map01.wad
//   \Device\Harddisk0\Partition1\...   →  system partition (stub)
//   T:\...                             →  <gameDir>/TDATA/...
//   Z:\...                             →  <gameDir>/ZDATA/...
//
// The "game directory" is the directory containing default.xbe.

inline std::filesystem::path g_gameDirectory;

inline void SetGameDirectory(const std::filesystem::path& xbePath)
{
    g_gameDirectory = std::filesystem::absolute(xbePath).parent_path();
}

inline std::filesystem::path TranslateXboxPath(const std::string_view& xboxPath)
{
    std::string path(xboxPath);

    // Strip common Xbox NT-style prefixes.
    // \??\D:\ or \??\d:\ 
    if (path.starts_with("\\??\\") && path.size() > 6 && path[5] == ':' && path[6] == '\\')
    {
        char drive = static_cast<char>(std::toupper(static_cast<unsigned char>(path[4])));
        std::string rest = path.substr(7);
        if (drive == 'D')
            return g_gameDirectory / rest;
        if (drive == 'T')
            return g_gameDirectory / "TDATA" / rest;
        if (drive == 'U')
            return g_gameDirectory / "UDATA" / rest;
        if (drive == 'Z')
            return g_gameDirectory / "ZDATA" / rest;
    }

    // \Device\CdRom0\ → game directory
    if (path.starts_with("\\Device\\CdRom0\\"))
    {
        std::string rest = path.substr(15);
        return g_gameDirectory / rest;
    }
    // \Device\CdRom0 (no trailing slash)
    if (path == "\\Device\\CdRom0")
        return g_gameDirectory;

    // \Device\Harddisk0\Partition1\ → TDATA (title persistent data)
    if (path.starts_with("\\Device\\Harddisk0\\Partition1\\"))
    {
        // Remove common "DEVKIT\" or "UDATA\" sub-paths if present
        std::string rest = path.substr(29);
        return g_gameDirectory / "TDATA" / rest;
    }

    // Drive letters: D:\..., T:\..., etc.
    if (path.size() >= 3 && path[1] == ':' && (path[2] == '\\' || path[2] == '/'))
    {
        char drive = static_cast<char>(std::toupper(static_cast<unsigned char>(path[0])));
        std::string rest = path.substr(3);
        if (drive == 'D')
            return g_gameDirectory / rest;
        if (drive == 'T')
            return g_gameDirectory / "TDATA" / rest;
        if (drive == 'U')
            return g_gameDirectory / "UDATA" / rest;
        if (drive == 'Z')
            return g_gameDirectory / "ZDATA" / rest;
    }

    // Bare drive letter "D:" with no trailing slash
    if (path.size() == 2 && path[1] == ':')
    {
        char drive = static_cast<char>(std::toupper(static_cast<unsigned char>(path[0])));
        if (drive == 'D')
            return g_gameDirectory;
        if (drive == 'T')
            return g_gameDirectory / "TDATA";
        if (drive == 'U')
            return g_gameDirectory / "UDATA";
        if (drive == 'Z')
            return g_gameDirectory / "ZDATA";
    }

    // Fallback: treat as relative to game directory.
    return g_gameDirectory / path;
}

// ---------------------------------------------------------------------------
// Helper: read an ANSI_STRING from guest memory and return its contents.
// ---------------------------------------------------------------------------
inline std::string ReadGuestAnsiString(uint8_t* base, uint32_t ansiStringAddr)
{
    if (!ansiStringAddr) return {};
    auto* str = reinterpret_cast<const XBOX_ANSI_STRING*>(base + ansiStringAddr);
    if (!str->Buffer || !str->Length) return {};
    const char* buf = reinterpret_cast<const char*>(base + str->Buffer);
    return std::string(buf, str->Length);
}

// ---------------------------------------------------------------------------
// Helper: read object name from OBJECT_ATTRIBUTES.
// ---------------------------------------------------------------------------
inline std::string ReadObjectName(uint8_t* base, uint32_t objAttrAddr)
{
    if (!objAttrAddr) return {};
    auto* oa = reinterpret_cast<const XBOX_OBJECT_ATTRIBUTES*>(base + objAttrAddr);
    return ReadGuestAnsiString(base, oa->ObjectName);
}

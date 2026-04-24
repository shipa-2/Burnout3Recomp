#pragma once

#include <cstdint>

// Load the data sections of an XBE file into guest memory.
// Returns true on success.
bool LoadXbeImage(const char* xbePath, uint8_t* guestBase);

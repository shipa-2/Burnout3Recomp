cmake_minimum_required(VERSION 3.20)

project(Quake2Recomp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the recompiled game code library.
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../Quake2RecompLib
                 ${CMAKE_CURRENT_BINARY_DIR}/Quake2RecompLib)

# Add o1heap allocator from thirdparty.
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/o1heap
                 ${CMAKE_CURRENT_BINARY_DIR}/o1heap)

# Add SDL2 for audio output.
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/SDL
                 ${CMAKE_CURRENT_BINARY_DIR}/SDL2)

add_executable(Quake2Recomp
    main.cpp
    hle_xapi.cpp
    hle_d3d.cpp
    hle_dsound.cpp
    hle_xinput.cpp
    kernel/memory.cpp
    kernel/heap.cpp
    kernel/imports.cpp
    kernel/xbe_loader.cpp
)

# Include the wrapper's own headers and the recompiled lib's public headers.
target_include_directories(Quake2Recomp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Quake2RecompLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/stb
    ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/SDL/include
)

# Link against the recompiled game code library and o1heap allocator.
target_link_libraries(Quake2Recomp PRIVATE Quake2RecompLib o1heap SDL2-static)

# Link XInput for controller support.
if(WIN32)
    target_link_libraries(Quake2Recomp PRIVATE xinput)
endif()

# Allow HLE overrides (e.g. hle_xapi.cpp) to replace functions from the
# static library by accepting multiple definitions.  The exe's .obj files
# are linked first so they take priority.
if(MSVC)
    target_link_options(Quake2Recomp PRIVATE /FORCE:MULTIPLE)
    # Disable LTCG to avoid "Generating Code..." hang with massive recomp files.
    string(REPLACE "/GL" "" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    target_compile_options(Quake2Recomp PRIVATE /GL-)
    target_link_options(Quake2Recomp PRIVATE /LTCG:OFF)
else()
    target_link_options(Quake2Recomp PRIVATE -Wl,--allow-multiple-definition)
endif()

# Platform-specific settings.
if(WIN32)
    target_compile_definitions(Quake2Recomp PRIVATE
        WIN32_LEAN_AND_MEAN
        NOMINMAX
    )
endif()

if(MSVC)
    # Suppress warnings from generated code.
    target_compile_options(Quake2Recomp PRIVATE /W3 /wd4244 /wd4267)
    # Console subsystem.
    set_target_properties(Quake2Recomp PROPERTIES
        WIN32_EXECUTABLE FALSE
    )
else()
    target_compile_options(Quake2Recomp PRIVATE
        -Wall -Wno-switch -Wno-unused-variable -Wno-unused-function
    )
endif()

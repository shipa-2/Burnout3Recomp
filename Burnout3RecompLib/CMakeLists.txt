cmake_minimum_required(VERSION 3.20)

project(Burnout3RecompLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB RECOMP_SOURCES "x86_recomp.*.cpp")

add_library(Burnout3RecompLib STATIC
    x86_func_mapping.cpp
    ${RECOMP_SOURCES}
)

target_include_directories(Burnout3RecompLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Disable Whole Program Optimization (LTCG) and heavy optimization for the
# massive recomp files — /O2 on multi-MB generated code takes 30+ minutes.
# The hot code is in the exe (hle_d3d.cpp), not here.
if(MSVC)
    set_target_properties(Burnout3RecompLib PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION OFF
    )
    # Strip /O2 and /GL from Release flags for this target directory.
    string(REPLACE "/O2" "/O1" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    string(REPLACE "/GL" "" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    string(REPLACE "/O2" "/O1" CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
    target_compile_options(Burnout3RecompLib PRIVATE /GL-)
    target_link_options(Burnout3RecompLib PRIVATE /LTCG:OFF)
endif()

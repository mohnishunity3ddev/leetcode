cmake_minimum_required(VERSION 3.22.0)

project(leetcode CXX C)

set(EXTERN_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/external)

set(CMAKE_CXX_STANDARD 23) # this does nothing for MSVC, use target_compile_options below
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Definitions
if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_definitions(-DNOMINMAX)
endif()
option(USE_DEBUG "Enter debug mode" OFF)
if (USE_DEBUG)
  add_definitions(-DDEBUG)
endif()

set(CMAKE_BUILD_TYPE Debug)
include_directories(common)

# Include Common SharedUtils
add_subdirectory(common)
add_subdirectory(src)

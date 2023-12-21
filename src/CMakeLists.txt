cmake_minimum_required(VERSION 3.22.0)

project(leetcode)

add_executable(leetcode main.cpp)

if (MSVC)
    message("Using MSVC")
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    message("Using clang")

    # Find clang executable and set it as compiler
    find_program(Clang_P clang++ REQUIRED True)
    set(CMAKE_CXX_COMPILER ${Clang_P})

    find_program(Clang_C clang REQUIRED True)
    set(CMAKE_C_COMPILER ${Clang_C})

    # Use clang lld instead of gnu ld
    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS})

    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)

    # Enable clang ubsan when in debug mode
    message("Adding ubsan!")
    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined)
    # set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=integer -fno-sanitize-recover=integer -fsanitize-coverage=inline-8bit-counters -O0)
    # set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=nullability)
    # set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=implicit-conversion)
    # set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=array-bounds)
    # add_compile_options(-fno-omit-frame-pointer)
    message("cmake linker flags: " ${CMAKE_EXE_LINKER_FLAGS})

    target_compile_options(leetcode PRIVATE ${CMAKE_EXE_LINKER_FLAGS})
    target_link_options(leetcode PRIVATE ${CMAKE_EXE_LINKER_FLAGS})

endif()

if(TARGET SharedUtils)
    target_link_libraries(leetcode SharedUtils)
endif()

target_link_libraries(leetcode)



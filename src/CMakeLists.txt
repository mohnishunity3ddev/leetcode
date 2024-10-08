cmake_minimum_required(VERSION 3.22.0)

project(leetcode)

add_executable(leetcode main.cpp)

if (MSVC)
    message("Using MSVC")
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    if(UNIX)
        message("Using clang in linux")

        # Find clang executable and set it as compiler
        find_program(Clang_P clang++ REQUIRED True)
        set(CMAKE_CXX_COMPILER ${Clang_P})

        find_program(Clang_C clang REQUIRED True)
        set(CMAKE_C_COMPILER ${Clang_C})

        # Use clang lld instead of gnu ld
        set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS})

        # lots of warnings and all warnings as errors
        add_compile_options(-Wall -Wextra -pedantic -Werror -Wunused-variable)

        # Enable clang ubsan when in debug mode
        # message("Adding ubsan!")
        # set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined)
        # # set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=integer -fno-sanitize-recover=integer -fsanitize-coverage=inline-8bit-counters -O0)
        # # set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=nullability)
        # # set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=implicit-conversion)
        # # set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=array-bounds)
        # # add_compile_options(-fno-omit-frame-pointer)
        # message("cmake linker flags: " ${CMAKE_EXE_LINKER_FLAGS})
        set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -fsanitize=undefined,address,integer)
        set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined,address,integer)

        # Add any other flags or options you need
        # For example, to disable sanitizer recovery:
        # set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fno-sanitize-recover=integer")

        target_compile_options(leetcode PRIVATE ${CMAKE_EXE_LINKER_FLAGS})
        target_link_options(leetcode PRIVATE ${CMAKE_EXE_LINKER_FLAGS})
    endif()

endif()

if(TARGET SharedUtils)
    message(STATUS "MAIN adding SharedUtils")
    target_link_libraries(leetcode SharedUtils)
endif()

target_link_libraries(leetcode)



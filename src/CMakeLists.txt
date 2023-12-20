cmake_minimum_required(VERSION 3.22.0)

project(leetcode)

include(../cmake_macros/prac.cmake)

SETUP_APP(leetcode "leetcode")

if(TARGET SharedUtils)
    target_link_libraries(leetcode SharedUtils)
endif()

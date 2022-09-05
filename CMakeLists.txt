cmake_minimum_required(VERSION 3.15)
project(PlayWithC)

# Use ccache if available
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

# Write compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
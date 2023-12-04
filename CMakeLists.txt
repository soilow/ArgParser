set(CMAKE_CXX_COMPILER g++)
set(CMAKE_TRY_COMPILE "STATIC_LIBRARY")
set_target_properties(labwork4 PROPERTIES
XCODE_GENERATE_SCHEME TRUE
XCODE_SCHEME_WORKING_DIRECTORY labwork4-soilow)

cmake_minimum_required(VERSION 3.12)

project(
    labwork4
    VERSION 1.0
    DESCRIPTION "C++ Year 2023 labword4"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(lib)
add_subdirectory(bin)


enable_testing()
add_subdirectory(tests)

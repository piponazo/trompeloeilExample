cmake_minimum_required(VERSION 3.13)

project(trompeloeilExample
    VERSION 0.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/findDependencies.cmake REQUIRED)

add_subdirectory(lib)
add_subdirectory(tests)


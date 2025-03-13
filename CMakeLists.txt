# Project specifications
cmake_minimum_required(VERSION 3.10.2)
project(Ratatoskr VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add subdirectories (one can continue adding subdirectories for each sub-project)
add_subdirectory(vendor/googletest-release-1.8.1/googletest)
add_subdirectory(src-diagnostics)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "CLANG")
    target_compile_options(gtest PRIVATE -w)
    target_compile_options(gtest_main PRIVATE -w)
endif()

# Project specifications
cmake_minimum_required(VERSION 3.10.2)
project(Ratatoskr VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Configure gtest and add
add_subdirectory(vendor/googletest-release-1.8.1/googletest)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "CLANG")
    target_compile_options(gtest PRIVATE -w)
    target_compile_options(gtest_main PRIVATE -w)
endif()

# Configure PAHO shared library compilation flags and add
set(PAHO_ENABLE_TESTING FALSE)
add_subdirectory(vendor/paho.mqtt.c-1.3.14)

# Add source subdirectories
add_subdirectory(src-diagnostics)

/**
 * This file defines the entry point for all tests run via GTEST. It is included via the
 * CMakeLists.txt in replacement of the main.cpp file.
 */

#include <gtest/gtest.h>
#include "main.hpp"

/**
 * Entry point to the test runner.
 * 
 * @param argc number of arguments passed to program, including program name.
 * @param argv buffer to strptr repr of each argument passed to the program.
 * 
 * @return Associated GTest Status / Error code.
 */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

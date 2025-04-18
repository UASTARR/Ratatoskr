# Sub-Project Specifications
cmake_minimum_required(VERSION 3.10.2)
project(diagnostics CXX)

### APPLICATION ##########################################################################

# Collect all .cpp files, removing any that have '_test.cpp' in their name
file(GLOB_RECURSE WEATHER_STATION_SRC "src/*.cpp")
list(FILTER WEATHER_STATION_SRC EXCLUDE REGEX "src/.*.test.cpp")

# Create executable for weather station application
add_executable(${PROJECT_NAME} ${WEATHER_STATION_SRC})
target_link_libraries(${PROJECT_NAME} "paho-mqtt3c") # Need to link lib from build/lib

### TESTING ##############################################################################

# Gtest settings 
set(PROJECT_TEST_NAME "diagnostics-tests")

# Collect all unit testing files
file(GLOB_RECURSE WEATHER_STATION_TEST_SRC "src/*.test.cpp")
list(FILTER WEATHER_STATION_SRC EXCLUDE REGEX "src/main.cpp")

# Create and link the cmake executable
enable_testing()
add_executable(
    ${PROJECT_TEST_NAME}
    ${WEATHER_STATION_TEST_SRC}
    ${WEATHER_STATION_SRC}
)
target_link_libraries(${PROJECT_TEST_NAME} gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_TEST_NAME})

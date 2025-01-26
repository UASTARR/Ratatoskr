# Setup
cmake_minimum_required(VERSION 3.11)
project(WeatherStation CXX)

### APPLICATION ##########################################################################

# Collect all .cpp files, removing any that have '_test.cpp' in their name
file(GLOB_RECURSE WEATHER_STATION_SRC "src/*.cpp")
list(FILTER WEATHER_STATION_SRC EXCLUDE REGEX "src/.*.test.cpp")

# Create executable for weather station application
add_executable(WeatherStation ${WEATHER_STATION_SRC})

### TESTING ##############################################################################

# Collect gtest package
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Gtest settings 
set(gtest_force_shared_crt  ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
set(PROJECT_TEST_NAME "ws_unit_tests")

# Collect all unit testing files
file(GLOB_RECURSE WEATHER_STATION_TEST_SRC "src/*.test.cpp")
list(FILTER WEATHER_STATION_SRC EXCLUDE REGEX "src/main.cpp")

enable_testing()

# Create and link the cmake executable
add_executable(
    ${PROJECT_TEST_NAME}
    ${WEATHER_STATION_TEST_SRC}
    ${WEATHER_STATION_SRC}
)
target_link_libraries(
    ${PROJECT_TEST_NAME}
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_TEST_NAME})

# Project specifications
cmake_minimum_required(VERSION 3.11)
project(SensorStorm VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add subdirectories (one can continue adding subdirectories for each sub-project)
add_subdirectory(weather_station)

cmake_minimum_required(VERSION 3.21.3)

# Project's name
project(ltds VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Variables to control the build process
option(PROJECT_BUILD_TESTS "Build the unit tests" OFF)
option(PROJECT_BUILD_EXAMPLES "Build the examples" OFF)

# Only build the tests if required
if(PROJECT_BUILD_TESTS)
  add_subdirectory(tests)
endif()

# Only build the examples if required
# Update this list as you include more examples
if(PROJECT_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

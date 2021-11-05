# Add an executable to the project using the tests' source files.
add_executable(
  ${CMAKE_PROJECT_NAME}-tests
  main.cpp
  test-lists.cpp
  )

include_directories(../src)

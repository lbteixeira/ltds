# Add an executable to the project using the tests' source files.
add_executable(
  ${CMAKE_PROJECT_NAME}-tests
  main.cpp
  test-lists.cpp
  )

include_directories(../src)
target_compile_options(${CMAKE_PROJECT_NAME}-tests PRIVATE -Werror -Wall -Wextra -pedantic-errors -Wconversion -Wsign-conversion)

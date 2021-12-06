# Add an executable to the project using the tests' source files.
add_executable(
  singlyList
  singlyLinkedList.cpp
  )

target_include_directories(singlyList PUBLIC ../src)

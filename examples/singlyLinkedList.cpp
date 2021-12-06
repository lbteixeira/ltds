/* This example compares std::forward_list with ltds::List.  These containers
 * aren't exactly the same, but provide several equivalent functionality.
 * Methodology:
 *    1 - Identical lists with random values are created for both
 *    implementations, with various sizes and data types.
 *    2 - The size operations are applied to both lists.
 *    3 - The resulting outputs are compared, taking the std implementation
 *    as the benchmark
 *    4 - The average time required for the operations is compared.
*/

#include "ltds/listSingly.hpp"
#include <cassert>
#include <forward_list>
#include <iostream>
#include <string>

int main()
{
  const std::string init[3] = {"One", "Two", "Three"};
  std::forward_list<std::string> stdList {"One", "Two", "Three"};
  ltds::List<std::string> ltdsList(init, 3);

  std::cout << "Front element in ltdsList: " << ltdsList.topFront() << std::endl;
  std::cout << "Front element in stdList: " << stdList.front() << std::endl;
}

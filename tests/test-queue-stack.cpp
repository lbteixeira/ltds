#include <catch2/catch.hpp>
#include "ltds/stack.hpp"

TEST_CASE("Stack"){

  SECTION("Constructors"){
    const int intArray[] = {7, 10, 4, 13};
    const int intArray2[] = {9};
    ltds::Stack<int> stackInt(intArray, 4);
    ltds::Stack<int> stackInt2(intArray2, 1);

    stackInt2 = stackInt;

  };

  SECTION("Operations"){
    const int intArray[] = {7, 10, 4, 13};
    ltds::Stack<int> stackInt(intArray, 4);
    REQUIRE(!stackInt.empty());
    REQUIRE(stackInt.top() == 13);
    stackInt.push(25);
    REQUIRE(stackInt.top() == 25);
    REQUIRE(stackInt.pop() == 25);
    REQUIRE(stackInt.pop() == 13);
    REQUIRE(stackInt.pop() == 4);
    REQUIRE(stackInt.top() == 10);
    REQUIRE(stackInt.pop() == 10);
    REQUIRE(stackInt.pop() == 7);
    REQUIRE(stackInt.empty());
  };
}

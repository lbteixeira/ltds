#include <catch2/catch.hpp>
#include "ltds/node.hpp"

TEST_CASE("Construction of nodes", "[node]"){
  ltds::node<float> node1;
  ltds::node<float> node2;
  ltds::node<int> node3;
  ltds::node<int> node4;

  node1.key = 1.0;
  node2.key = 2.0;
  node2.next = &node1;
  node3.key = 3;
  node4.key = 40;
  node4.next = &node3;
  node3.next = &node4;

  REQUIRE(node1.key == 1.0);
  REQUIRE(node2.key == 2.0);
  REQUIRE(node3.key == 3);
  REQUIRE(node1.next == nullptr);
  REQUIRE(node2.next == &node1);
  REQUIRE(node3.next == &node4);
  REQUIRE(node4.next == &node3);
}

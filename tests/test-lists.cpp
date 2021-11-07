#include <catch2/catch.hpp>
#include "ltds/lists.hpp"

TEST_CASE("Construction of nodes", "[node]"){ ltds::nodeSingle<float> node1;
  ltds::nodeSingle<float> node2;
  ltds::nodeSingle<int> node3;
  ltds::nodeSingle<int> node4;

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

TEST_CASE("Singly linked lists", "[slist]"){
  const int intArray[] = {7, 10, 4, 13};
  const double doubleArray[] = {7.0, 10.0, 4.0, 13.0};
  ltds::singlyLinkedList<int> listInt1;
  ltds::singlyLinkedList<int> listInt2(intArray, 4);
  ltds::singlyLinkedList<double> listDouble1;
  ltds::singlyLinkedList<double> listDouble2(doubleArray, 4);

  SECTION("Initial state - Default constructor"){
    REQUIRE(listInt1.head.next == nullptr);
    REQUIRE(listDouble1.head.next == nullptr);

    REQUIRE(listInt1.tail.next == nullptr);
    REQUIRE(listDouble1.tail.next == nullptr);
  };

  SECTION("Initial state - Constructor with array"){
    REQUIRE(listInt2.head.next->key == 7);
    REQUIRE(listDouble2.head.next->key == 7.0);

    REQUIRE(listInt2.tail.next->key == 13);
    REQUIRE(listDouble2.tail.next->key == 13.0);
  };

  SECTION("Push Front"){
    listInt1.pushFront(26);
    listInt2.pushFront(26);
    listDouble1.pushFront(26.0);
    listDouble2.pushFront(26.0);

    REQUIRE(listInt1.head.next->key == 26);
    REQUIRE(listInt1.tail.next->key == 26);
    REQUIRE(listInt2.head.next->key == 26);
    REQUIRE(listInt2.tail.next->key == 13);

    REQUIRE(listDouble1.head.next->key == 26.0);
    REQUIRE(listDouble1.tail.next->key == 26.0);
    REQUIRE(listDouble2.head.next->key == 26.0);
    REQUIRE(listDouble2.tail.next->key == 13.0);

    listInt1.pushFront(12);
    listInt2.pushFront(12);
    listDouble1.pushFront(12.0);
    listDouble2.pushFront(12.0);

    REQUIRE(listInt1.head.next->key == 12);
    REQUIRE(listInt1.tail.next->key == 26);
    REQUIRE(listInt2.head.next->key == 12);
    REQUIRE(listInt2.tail.next->key == 13);

    REQUIRE(listDouble1.head.next->key == 12.0);
    REQUIRE(listDouble1.tail.next->key == 26.0);
    REQUIRE(listDouble2.head.next->key == 12.0);
    REQUIRE(listDouble2.tail.next->key == 13.0);
  };

  SECTION("Push Back"){
    listInt1.pushBack(26);
    listInt2.pushFront(26);
    listDouble1.pushBack(26.0);
    listDouble2.pushFront(26.0);
  };

  SECTION("Pop Front"){
    listInt1.pushFront(10);
    listInt1.pushFront(26);
    listInt1.popFront();
    REQUIRE(listInt1.head.next->key == 10);
  };
}

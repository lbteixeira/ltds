#include <catch2/catch.hpp>
#include <stdexcept>
#include <string>
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
    REQUIRE(listInt1.head == nullptr);
    REQUIRE(listDouble1.head == nullptr);

    REQUIRE(listInt1.tail == nullptr);
    REQUIRE(listDouble1.tail == nullptr);
  };

  SECTION("Initial state - Constructor with array"){
    REQUIRE(listInt2.head->key == 7);
    REQUIRE(listDouble2.head->key == 7.0);

    REQUIRE(listInt2.tail->key == 13);
    REQUIRE(listDouble2.tail->key == 13.0);
  };

  SECTION("Push Front"){
    listInt1.pushFront(26);
    listInt2.pushFront(26);
    listDouble1.pushFront(26.0);
    listDouble2.pushFront(26.0);

    REQUIRE(listInt1.head->key == 26);
    REQUIRE(listInt1.tail->key == 26);
    REQUIRE(listInt2.head->key == 26);
    REQUIRE(listInt2.tail->key == 13);

    REQUIRE(listDouble1.head->key == 26.0);
    REQUIRE(listDouble1.tail->key == 26.0);
    REQUIRE(listDouble2.head->key == 26.0);
    REQUIRE(listDouble2.tail->key == 13.0);

    listInt1.pushFront(12);
    listInt2.pushFront(12);
    listDouble1.pushFront(12.0);
    listDouble2.pushFront(12.0);

    REQUIRE(listInt1.head->key == 12);
    REQUIRE(listInt1.tail->key == 26);
    REQUIRE(listInt2.head->key == 12);
    REQUIRE(listInt2.tail->key == 13);

    REQUIRE(listDouble1.head->key == 12.0);
    REQUIRE(listDouble1.tail->key == 26.0);
    REQUIRE(listDouble2.head->key == 12.0);
    REQUIRE(listDouble2.tail->key == 13.0);
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
    REQUIRE(listInt1.head->key == 10);
    listDouble1.popFront();
    listInt1.pushFront(-1);
    REQUIRE(listInt1.head->key == -1);
  };

  SECTION("Pop Back"){
    listInt1.pushFront(10);
    listInt1.popBack();
    REQUIRE(listInt1.head == nullptr);
    REQUIRE(listInt1.tail == nullptr);
    REQUIRE(listInt1.empty() == true);

    listInt2.popBack();
    REQUIRE(listInt2.tail->key == 4);
    listInt2.popBack();
    REQUIRE(listInt2.tail->key == 10);
    listInt2.pushBack(100);
    REQUIRE(listInt2.tail->key == 100);

    listDouble1.popBack();
    listInt2.pushBack(-1);
    REQUIRE(listInt2.tail->key == -1);

  };

  SECTION("Empty"){
    REQUIRE(listInt1.empty() == true);
    REQUIRE(listInt2.empty() == false);
    REQUIRE(listDouble1.empty() == true);
    REQUIRE(listDouble2.empty() == false);

    listInt1.pushFront(15);
    listInt2.popFront();
    listInt2.popFront();
    listInt2.popFront();
    listInt2.popFront();

    REQUIRE(listInt1.empty() == false);
    REQUIRE(listInt2.empty() == true);
  };

  SECTION("Top Front and Back"){
    listInt1.pushFront(-1);
    REQUIRE(listInt1.topFront() == -1);
    REQUIRE(listInt1.topBack() == -1);
    listInt1.pushBack(-2);
    REQUIRE(listInt1.topFront() == -1);
    REQUIRE(listInt1.topBack() == -2);

    REQUIRE(listInt2.topFront() == 7);
    REQUIRE(listInt2.topBack() == 13);

    listDouble1.pushFront(-1.0);
    REQUIRE(listDouble1.topFront() == -1);
    listDouble1.pushBack(-2.0);
    REQUIRE(listDouble1.topFront() == -1);

    REQUIRE(listDouble2.topFront() == 7);

    ltds::singlyLinkedList<std::string> listString;
    listString.pushBack("One");
    listString.pushBack("Two");
    REQUIRE(listString.topFront().compare("One") == 0);
    REQUIRE(listString.topBack().compare("Two") == 0);
    listString.popFront();
    REQUIRE(listString.topFront().compare("Two") == 0);
    REQUIRE(listString.topBack().compare("Two") == 0);

  };

}

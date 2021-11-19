#include <catch2/catch.hpp>
#include <stdexcept>
#include <string>
#include "ltds/listSingly.hpp"
#include "ltds/listDoubly.hpp"

TEST_CASE("Singly linked lists", "[slist]"){
  const int intArray[] = {7, 10, 4, 13};

  ltds::List<int> listInt1;
  ltds::List<int> listInt2(intArray, 4);

  ltds::ListDoubly<int> listInt1Doubly;
  ltds::ListDoubly<int> listInt2Doubly(intArray, 4);

  ltds::List<std::string> listString;
  listString.pushBack("One");
  listString.pushBack("Two");

  SECTION("Initial state - Default constructor"){
    SECTION("Singly"){
      REQUIRE(listInt1.head == nullptr);

      REQUIRE(listInt1.tail == nullptr);
    };

    SECTION("Doubly"){
      REQUIRE(listInt1Doubly.head == nullptr);

      REQUIRE(listInt1Doubly.tail == nullptr);
    };
  };

  SECTION("Initial state - Constructor with array"){
    REQUIRE(listInt2.head->key == 7);

    REQUIRE(listInt2.tail->key == 13);
  };

  SECTION("Push Front"){
    listInt1.pushFront(26);
    listInt2.pushFront(26);

    REQUIRE(listInt1.head->key == 26);
    REQUIRE(listInt1.tail->key == 26);
    REQUIRE(listInt2.head->key == 26);
    REQUIRE(listInt2.tail->key == 13);

    listInt1.pushFront(12);
    listInt2.pushFront(12);

    REQUIRE(listInt1.head->key == 12);
    REQUIRE(listInt1.tail->key == 26);
    REQUIRE(listInt2.head->key == 12);
    REQUIRE(listInt2.tail->key == 13);

  };

  SECTION("Push Back"){
    listInt1.pushBack(26);
    listInt2.pushFront(26);
  };

  SECTION("Pop Front"){
    listInt1.pushFront(10);
    listInt1.pushFront(26);
    listInt1.popFront();
    REQUIRE(listInt1.head->key == 10);
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

    listInt2.pushBack(-1);
    REQUIRE(listInt2.tail->key == -1);
  };

  SECTION("Empty"){
    REQUIRE(listInt1.empty() == true);
    REQUIRE(listInt2.empty() == false);

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

    REQUIRE(listString.topFront().compare("One") == 0);
    REQUIRE(listString.topBack().compare("Two") == 0);
    listString.popFront();
    REQUIRE(listString.topFront().compare("Two") == 0);
    REQUIRE(listString.topBack().compare("Two") == 0);
  };

  SECTION("Find"){
    REQUIRE(listInt2.find(7));
    REQUIRE(listInt2.find(10));
    REQUIRE(listInt2.find(4));
    REQUIRE(listInt2.find(13));
    REQUIRE(!listInt2.find(-1));
    REQUIRE(listString.find("One"));
    REQUIRE(listString.find("Two"));
    REQUIRE(!listString.find("Three"));
  };

  SECTION("Erase"){
    REQUIRE(listInt2.find(10));
    listInt2.erase(10);
    REQUIRE(!listInt2.find(10));

    REQUIRE(listInt2.find(4));
    listInt2.erase(4);
    REQUIRE(!listInt2.find(4));
  };

}

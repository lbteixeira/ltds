#include <catch2/catch.hpp>
#include <forward_list>
#include <stdexcept>
#include <string>

#include "ltds/listSingly.hpp"
#include "ltds/listDoubly.hpp"

TEST_CASE("Singly linked lists - constructors", "[slist]"){

  const int intArray[] = {7, 10, 4, 13};
  ltds::List<int> listInt(intArray, 4);
  ltds::List<int> listIntEmpty;

  SECTION("Copy of empty list"){
    ltds::List<int> copiedListIntEmpty(listIntEmpty);

    listIntEmpty.pushBack(1);
    copiedListIntEmpty.pushBack(2);

    REQUIRE(listIntEmpty.topBack() != copiedListIntEmpty.topBack());
  }

  SECTION("Copy of initialized list to empty list"){
    ltds::List<int> copiedListInt(listInt);

    copiedListInt.popFront();
    REQUIRE(copiedListInt.topFront() == 10);
    REQUIRE(listInt.topFront() == 7);
  };

  SECTION("Assignment of a list to an empty list"){
    ltds::List<int> assignedList;
    assignedList = listInt;

    assignedList.popFront();
    REQUIRE(assignedList.topFront() == 10);
    REQUIRE(listInt.topFront() == 7);
  };

  SECTION("Assignment of a list to a non-empty list"){
    ltds::List<int> assignedList;
    assignedList.pushBack(1);
    assignedList.pushBack(2);
    assignedList = listInt;

    assignedList.popFront();
    REQUIRE(assignedList.topFront() == 10);
    REQUIRE(listInt.topFront() == 7);
  };

}

TEST_CASE("Singly linked lists - operations", "[slist]"){

  const int intArray[] = {7, 10, 4, 13};
  const std::string stringArray[] = {"Seven", "Ten", "Four", "Thirteen"};

  ltds::List<int> listInt1;
  ltds::List<int> listInt2(intArray, 4);
  ltds::List<std::string> listString1;
  ltds::List<std::string> listString2(stringArray, 4);

  SECTION("Initial state - Constructor with array"){
    SECTION("Int"){
      REQUIRE(listInt2.topFront() == 7);
      REQUIRE(listInt2.topBack() == 13);
    };

    SECTION("String"){
      REQUIRE(listString2.topFront().compare("Seven") == 0);
      REQUIRE(listString2.topBack().compare("Thirteen") == 0);
    };
  };

  SECTION("Push Front"){
    SECTION("Int"){
      listInt1.pushFront(26);
      listInt2.pushFront(26);

      REQUIRE(listInt1.topFront() == 26);
      REQUIRE(listInt1.topBack() == 26);
      REQUIRE(listInt2.topFront() == 26);
      REQUIRE(listInt2.topBack() == 13);

      listInt1.pushFront(12);
      listInt2.pushFront(12);

      REQUIRE(listInt1.topFront() == 12);
      REQUIRE(listInt1.topBack() == 26);
      REQUIRE(listInt2.topFront() == 12);
      REQUIRE(listInt2.topBack() == 13);
    };

    SECTION("String"){
      listString1.pushFront("Twenty-six");
      listString2.pushFront("Twenty-six");

      REQUIRE(listString1.topFront().compare("Twenty-six") == 0);
      REQUIRE(listString1.topBack().compare("Twenty-six") == 0);
      REQUIRE(listString2.topFront().compare("Twenty-six") == 0);
      REQUIRE(listString2.topBack().compare("Thirteen") == 0);

      listString1.pushFront("Twelve");
      listString2.pushFront("Twelve");

      REQUIRE(listString1.topFront().compare("Twelve") == 0);
      REQUIRE(listString1.topBack().compare("Twenty-six") == 0);
      REQUIRE(listString2.topFront().compare("Twelve") == 0);
      REQUIRE(listString2.topBack().compare("Thirteen") == 0);
    };

  };

  SECTION("Push Back"){
    listInt1.pushBack(26);
    listInt2.pushFront(26);
  };

  SECTION("Pop Front"){
    SECTION("Int"){
      listInt1.pushFront(10);
      listInt1.pushFront(26);
      listInt1.popFront();
      REQUIRE(listInt1.topFront() == 10);
      listInt1.pushFront(-1);
      REQUIRE(listInt1.topFront() == -1);
    };

    SECTION("String"){
      listString1.pushFront("Ten");
      listString1.pushFront("Twenty-six");
      listString1.popFront();
      REQUIRE(listString1.topFront().compare("Ten") == 0);
      listString1.pushFront("Minus-one");
      REQUIRE(listString1.topFront().compare("Minus-one") == 0);
    };
  };

  SECTION("Pop Back"){
    SECTION("Int"){
      listInt1.pushFront(10);
      listInt1.popBack();
      REQUIRE(listInt1.empty());

      listInt2.popBack();
      REQUIRE(listInt2.topBack() == 4);
      listInt2.popBack();
      REQUIRE(listInt2.topBack() == 10);
      listInt2.pushBack(100);
      REQUIRE(listInt2.topBack() == 100);

      listInt2.pushBack(-1);
      REQUIRE(listInt2.topBack() == -1);
    };

    SECTION("String"){
      listString1.pushFront("Ten");
      listString1.popBack();
      REQUIRE(listString1.empty());

      listString2.popBack();
      REQUIRE(listString2.topBack().compare("Four") == 0);
      listString2.popBack();
      REQUIRE(listString2.topBack().compare("Ten") == 0);
      listString2.pushBack("One-Hundred");
      REQUIRE(listString2.topBack().compare("One-Hundred") == 0);

      listString2.pushBack("Minus-One");
      REQUIRE(listString2.topBack().compare("Minus-One") == 0);
    };
  };

  SECTION("Empty"){
    SECTION("Int"){
      REQUIRE(listInt1.empty());
      REQUIRE(!listInt2.empty());

      listInt1.pushFront(15);
      listInt2.popFront();
      listInt2.popFront();
      listInt2.popFront();
      listInt2.popFront();

      REQUIRE(!listInt1.empty());
      REQUIRE(listInt2.empty());
    };

    SECTION("String"){
      REQUIRE(listString1.empty());
      REQUIRE(!listString2.empty());

      listString1.pushFront("Fifteen");
      listString2.popFront();
      listString2.popFront();
      listString2.popFront();
      listString2.popFront();

      REQUIRE(!listString1.empty());
      REQUIRE(listString2.empty());
    };
  };

  SECTION("Top Front and Back"){
    SECTION("Int"){
      listInt1.pushFront(-1);
      REQUIRE(listInt1.topFront() == -1);
      REQUIRE(listInt1.topBack() == -1);
      listInt1.pushBack(-2);
      REQUIRE(listInt1.topFront() == -1);
      REQUIRE(listInt1.topBack() == -2);

      REQUIRE(listInt2.topFront() == 7);
      REQUIRE(listInt2.topBack() == 13);
    };

    SECTION("String"){
      listString1.pushFront("Minus-one");
      REQUIRE(listString1.topFront().compare("Minus-one") == 0);
      REQUIRE(listString1.topBack().compare("Minus-one") == 0);
      listString1.pushBack("Minus-two");
      REQUIRE(listString1.topFront() == "Minus-one");
      REQUIRE(listString1.topBack().compare("Minus-two") == 0);

      REQUIRE(listString2.topFront().compare("Seven") == 0);
      REQUIRE(listString2.topBack().compare("Thirteen") == 0);
    };
  };

  SECTION("Find"){
    SECTION("Int"){
      REQUIRE(listInt2.find(7));
      REQUIRE(listInt2.find(10));
      REQUIRE(listInt2.find(4));
      REQUIRE(listInt2.find(13));
      REQUIRE(!listInt2.find(-1));
    };

    SECTION("String"){
      REQUIRE(listString2.find("Seven"));
      REQUIRE(listString2.find("Ten"));
      REQUIRE(listString2.find("Four"));
      REQUIRE(listString2.find("Thirteen"));
      REQUIRE(!listString2.find("Minus-one"));
    };
  };

  SECTION("Erase"){
    SECTION("Int"){
      REQUIRE(listInt2.find(10));
      listInt2.erase(10);
      REQUIRE(!listInt2.find(10));

      REQUIRE(listInt2.find(4));
      listInt2.erase(4);
      REQUIRE(!listInt2.find(4));
    };

    SECTION("String"){
      REQUIRE(listString2.find("Ten"));
      listString2.erase("Ten");
      REQUIRE(!listString2.find("Ten"));

      REQUIRE(listString2.find("Four"));
      listString2.erase("Four");
      REQUIRE(!listString2.find("Four"));
    };

    SECTION("Clear"){
      listInt2.clear();
      listString2.clear();
      REQUIRE(listInt2.empty());
      REQUIRE(listString2.empty());
    };
  };
}

TEST_CASE("Doubly linked lists - operations", "[dlist]"){
  const int intArray[] = {7, 10, 4, 13};
  const std::string stringArray[] = {"Seven", "Ten", "Four", "Thirteen"};

  ltds::ListDouble<int> listInt(intArray, 4);
  ltds::ListDouble<std::string> listString(stringArray, 4);

  SECTION("Push and pop back"){

    SECTION("List of integers"){
      REQUIRE(listInt.topBack() == 13);
      listInt.pushBack(-1);
      REQUIRE(listInt.topBack() == -1);
      listInt.pushBack(2);
      listInt.pushBack(-50);
      listInt.pushBack(0);
      REQUIRE(listInt.topBack() == 0);
      listInt.popBack();
      listInt.popBack();
      listInt.popBack();
      listInt.popBack();
      listInt.popBack();
      listInt.popBack();
      REQUIRE(listInt.topBack() == 10);
      REQUIRE(!listInt.empty());
      listInt.popBack();
      listInt.popBack();
      REQUIRE(listInt.empty());
      listInt.pushBack(0);
      REQUIRE(listInt.topBack() == 0);
      REQUIRE(listInt.topFront() == 0);
    };

    SECTION("List of strings"){
      REQUIRE(listString.topBack().compare("Thirteen") == 0);
      listString.pushBack("MinusOne");
      REQUIRE(listString.topBack().compare("MinusOne") == 0);
      listString.pushBack("Two");
      listString.pushBack("MinusFifty");
      listString.pushBack("Zero");
      REQUIRE(listString.topBack().compare("Zero") == 0);
      listString.popBack();
      listString.popBack();
      listString.popBack();
      listString.popBack();
      listString.popBack();
      listString.popBack();
      REQUIRE(listString.topBack().compare("Ten") == 0);
      REQUIRE(!listString.empty());
      listString.popBack();
      listString.popBack();
      REQUIRE(listString.empty());
      listString.pushBack("Zero");
      REQUIRE(listString.topBack().compare("Zero") == 0);
      REQUIRE(listString.topFront().compare("Zero") == 0);
    };
  };

  SECTION("Push and pop front"){

    SECTION("List of integers"){
      REQUIRE(listInt.topFront() == 7);
      listInt.pushFront(-1);
      REQUIRE(listInt.topFront() == -1);
      listInt.pushFront(2);
      listInt.pushFront(-50);
      listInt.pushFront(0);
      REQUIRE(listInt.topFront() == 0);
      listInt.popFront();
      listInt.popFront();
      listInt.popFront();
      listInt.popFront();
      listInt.popFront();
      listInt.popFront();
      REQUIRE(listInt.topFront() == 4);
      REQUIRE(!listInt.empty());
      listInt.popFront();
      listInt.popFront();
      REQUIRE(listInt.empty());
      listInt.pushFront(0);
      REQUIRE(listInt.topFront() == 0);
      REQUIRE(listInt.topBack() == 0);
    };

    SECTION("List of strings"){
      REQUIRE(listString.topBack().compare("Thirteen") == 0);
      listString.pushBack("MinusOne");
      REQUIRE(listString.topBack().compare("MinusOne") == 0);
      listString.pushBack("Two");
      listString.pushBack("MinusFifty");
      listString.pushBack("Zero");
      REQUIRE(listString.topBack().compare("Zero") == 0);
      listString.popBack();
      listString.popBack();
      listString.popBack();
      listString.popBack();
      listString.popBack();
      listString.popBack();
      REQUIRE(listString.topBack().compare("Ten") == 0);
      REQUIRE(!listString.empty());
      listString.popBack();
      listString.popBack();
      REQUIRE(listString.empty());
      listString.pushBack("Zero");
      REQUIRE(listString.topBack().compare("Zero") == 0);
      REQUIRE(listString.topFront().compare("Zero") == 0);
    };
  };
}

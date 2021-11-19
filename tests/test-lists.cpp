#include <catch2/catch.hpp>
#include <stdexcept>
#include <string>
#include "ltds/listSingly.hpp"
#include "ltds/listDoubly.hpp"

TEST_CASE("Singly linked lists", "[slist]"){
  const int intArray[] = {7, 10, 4, 13};
  const std::string stringArray[] = {"Seven", "Ten", "Four", "Thirteen"};

  ltds::List<int> listInt1;
  ltds::List<int> listInt2(intArray, 4);
  ltds::List<std::string> listString1;
  ltds::List<std::string> listString2(stringArray, 4);

  ltds::ListDoubly<int> listInt1Doubly;
  ltds::ListDoubly<int> listInt2Doubly(intArray, 4);

  SECTION("Initial state - Default constructor"){
    SECTION("Int"){
      REQUIRE(listInt1.head == nullptr);
      REQUIRE(listInt1.tail == nullptr);
    };

    SECTION("String"){
      REQUIRE(listString1.head == nullptr);
      REQUIRE(listString1.tail == nullptr);
    };

    REQUIRE(listInt1Doubly.head == nullptr);
    REQUIRE(listInt1Doubly.tail == nullptr);
  };

  SECTION("Initial state - Constructor with array"){
    SECTION("Int"){
      REQUIRE(listInt2.head->key == 7);
      REQUIRE(listInt2.tail->key == 13);
    };

    SECTION("String"){
      REQUIRE(listString2.head->key.compare("Seven") == 0);
      REQUIRE(listString2.tail->key.compare("Thirteen") == 0);
    };
  };

  SECTION("Push Front"){
    SECTION("Int"){
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

    SECTION("String"){
      listString1.pushFront("Twenty-six");
      listString2.pushFront("Twenty-six");

      REQUIRE(listString1.head->key.compare("Twenty-six") == 0);
      REQUIRE(listString1.tail->key.compare("Twenty-six") == 0);
      REQUIRE(listString2.head->key.compare("Twenty-six") == 0);
      REQUIRE(listString2.tail->key.compare("Thirteen") == 0);

      listString1.pushFront("Twelve");
      listString2.pushFront("Twelve");

      REQUIRE(listString1.head->key.compare("Twelve") == 0);
      REQUIRE(listString1.tail->key.compare("Twenty-six") == 0);
      REQUIRE(listString2.head->key.compare("Twelve") == 0);
      REQUIRE(listString2.tail->key.compare("Thirteen") == 0);
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
      REQUIRE(listInt1.head->key == 10);
      listInt1.pushFront(-1);
      REQUIRE(listInt1.head->key == -1);
    };

    SECTION("String"){
      listString1.pushFront("Ten");
      listString1.pushFront("Twenty-six");
      listString1.popFront();
      REQUIRE(listString1.head->key.compare("Ten") == 0);
      listString1.pushFront("Minus-one");
      REQUIRE(listString1.head->key.compare("Minus-one") == 0);
    };
  };

  SECTION("Pop Back"){
    SECTION("Int"){
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

    SECTION("String"){
      listString1.pushFront("Ten");
      listString1.popBack();
      REQUIRE(listString1.head == nullptr);
      REQUIRE(listString1.tail == nullptr);
      REQUIRE(listString1.empty() == true);

      listString2.popBack();
      REQUIRE(listString2.tail->key.compare("Four") == 0);
      listString2.popBack();
      REQUIRE(listString2.tail->key.compare("Ten") == 0);
      listString2.pushBack("One-Hundred");
      REQUIRE(listString2.tail->key.compare("One-Hundred") == 0);

      listString2.pushBack("Minus-One");
      REQUIRE(listString2.tail->key.compare("Minus-One") == 0);
    };
  };

  SECTION("Empty"){
    SECTION("Int"){
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

    SECTION("String"){
      REQUIRE(listString1.empty() == true);
      REQUIRE(listString2.empty() == false);

      listString1.pushFront("Fifteen");
      listString2.popFront();
      listString2.popFront();
      listString2.popFront();
      listString2.popFront();

      REQUIRE(listString1.empty() == false);
      REQUIRE(listString2.empty() == true);
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
  };

}

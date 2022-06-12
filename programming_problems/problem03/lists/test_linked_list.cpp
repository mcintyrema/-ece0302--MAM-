#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "Call all public functions", "[LinkedList]" ) {
  LinkedList<int>a;

  a.isEmpty();
  a.getLength();
  a.insert(0,0);
  a.getEntry(0);
  a.setEntry(0,0);
  a.remove(0);
  a.clear();

}

TEST_CASE("Test list initialized to zero", "[LinkedList]"){
  LinkedList<int>a;

  REQUIRE(a.getLength() == 0);
  REQUIRE(a.isEmpty() == true);
}

TEST_CASE("Test getLength returns correct number of items", "[LinkedList]"){
  LinkedList<int>a;

  a.insert(5,5);
  REQUIRE(a.getLength() == 5);
}

TEST_CASE("Test that item was inserted if position valid", "[LinkedList]"){
  LinkedList<int>a;

  a.insert(0,7);
  a.insert(1, 8);
  REQUIRE(a.insert(2, 9) == true);
  REQUIRE(a.getEntry(0) == 7);
  REQUIRE(a.getEntry(1) == 8);
  REQUIRE(a.getEntry(2) == 9);
  REQUIRE(a.insert(-1, 5) == false);
}

TEST_CASE("test that remove deletes elements", "[LinkedList]"){
  LinkedList<int>a;

  for(int i = 0; i < 50; i++){
    a.insert(i,i);
  }
  a.remove(9);
  REQUIRE(a.getLength() == 49);
}

TEST_CASE("clear() removes all items from list", "[LinkedList"){
  LinkedList<int>a;

  for(int i = 0; i < 50; i++){
    a.insert(i,i);
  }

  a.clear();
  REQUIRE(a.getLength() == 0);
}

TEST_CASE("getEntry returns correct value", "[LinkedList]"){
  LinkedList<int>a;

  for(int i = 0; i < 50; i++){
    a.insert(i,i);
  }

  a.setEntry(9, 9);
  REQUIRE(a.getEntry(9) == 9);

}

TEST_CASE("setEntry changes value specified", "[LinkedList]"){
  LinkedList<int>a;

  a.setEntry(7,7);
  REQUIRE(a.getEntry(7) == 7);
}

TEST_CASE("list is copy constructable", "[LinkedList]"){
  LinkedList<int>a;

  for(int i = 0; i < 50; i++){
    a.insert(i,i);
  }

  LinkedList<int>c(a);
  for(int i = 0; i < a.getLength(); i++){
    REQUIRE(c.getEntry(i) == i);
  }
}

TEST_CASE("test operator overloader", "[LinkedList]"){
  LinkedList<int>a;

  for(int i = 0; i<50; i++){
    a.insert(i,i);
  }

  LinkedList<int>b;
  b = a;
  for(int i = 0; i < 50; i++){
    REQUIRE(b.getEntry(i) == i);
  }
}
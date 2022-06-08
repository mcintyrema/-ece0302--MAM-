#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Calling all public members", "[ArrayList]" ) {
  ArrayList<int> list;

  list.insert(0, 0);
  list.remove(0);
  list.isEmpty();
  list.clear();
  list.getLength();
  list.getEntry(0);
  list.setEntry(0, 0);

}

TEST_CASE( "Calling copy constructor", "[ArrayList]"){
  ArrayList<int> list;
  ArrayList<int> listb(list);
}

TEST_CASE("Array initialized empty", "[ArrayList]"){
  ArrayList<int> list;
  REQUIRE(list.isEmpty() == true);

  ArrayList<int> listb(list);
  REQUIRE(listb.isEmpty() == true);
}

TEST_CASE("getLength returns correct length", "[ArrayList]"){
  ArrayList<int> list;
  std::size_t dim = 7;
  list.setLength(dim);
  REQUIRE(list.getLength() == 7);
}

TEST_CASE("array can be cleared", "[ArrayList]"){
  ArrayList<int> list;
  list.clear();
  REQUIRE(list.isEmpty() == true);
}

TEST_CASE("test copy constructor", "[ArrayList]"){
  ArrayList<int>list;
  ArrayList<int>listb = list;

  REQUIRE(&list.operator=(listb) == &list);
}

TEST_CASE("add shows if item added to array", "[ArrayList]"){
  ArrayList<std::string>list;

  std::string item = "chapstick";
  bool check;
  check = list.insert(0, item);

  REQUIRE(check == true);
  REQUIRE(list.getEntry(0) == "chapstick");
}

TEST_CASE("remove deletes item from array", "[ArrayList]"){
  ArrayList<std::string>list;

  std::string item = "chapstick";
  list.insert(0, item);
  REQUIRE(list.remove(0) == true);
}

TEST_CASE("isEmpty shows if array is empty", "[ArrayList]"){
  ArrayList<int>list;
  list.setLength(0);
  list.clear();
  REQUIRE(list.isEmpty() == true);
}

TEST_CASE("test assignment operator", "[ArrayList]"){
  ArrayList<int>list;
  ArrayList<int>listb;

  REQUIRE(&list.operator=(listb) == &list);

}

TEST_CASE("setEntry adds item at position", "[ArrayList]"){
  ArrayList<std::string>list;

  const std::string item = "chapstick";
  list.setEntry(0, item);
  REQUIRE(list.getEntry(0) == item);
}
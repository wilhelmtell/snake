#include <catch/catch.hpp>
#include "../src/height.hh"
#include <type_traits>

TEST_CASE("height::value_type is an int") {
  static_assert(std::is_same<snk::height::value_type, int>::value,
                "height::value_type is an int");
}

TEST_CASE("height constructs from an integer") { snk::height const h{7}; }

TEST_CASE("height converts to an integer") {
  snk::height const h{7};
  int const value = h;
}

TEST_CASE("height value") {
  snk::height const h{7};
  int const value = h;
  REQUIRE(value == 7);
}

TEST_CASE("height equality") {
  snk::height const h{7};
  REQUIRE(h == 7);
}

TEST_CASE("height inequality") {
  snk::height const h{7};
  REQUIRE(h != 6);
}

#include <catch/catch.hpp>
#include "../src/width.hh"
#include <type_traits>

TEST_CASE("width::value_type is an int") {
  static_assert(std::is_same<snk::width::value_type, int>::value,
                "width::value_type is an int");
}

TEST_CASE("width constructs from an integer") { snk::width const w{7}; }

TEST_CASE("width converts to an integer") {
  snk::width const w{7};
  int const value = w;
}

TEST_CASE("width value") {
  snk::width const w{7};
  int const value = w;
  REQUIRE(value == 7);
}

TEST_CASE("width equality") {
  snk::width const w{7};
  REQUIRE(w == 7);
}

TEST_CASE("width inequality") {
  snk::width const w{7};
  REQUIRE(w != 6);
}

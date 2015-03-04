#include <catch/catch.hpp>
#include "mock_factory.hh"
#include "../src/snake_control.hh"

TEST_CASE("snake is initially at origin") {
  snk::test::mock_factory factory;
  snk::snake_control control{factory};
}

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <cstdint>
#include <vector>

#include "StaticArray.hpp"

TEST_CASE( "Static Array", "[SArray]" ) {
  SECTION( "basic usage" ) {
    Prim::StaticArray<int, 3> arr{1, 2, 3};
    REQUIRE(arr.Front() == 1);
    REQUIRE(arr.Back() == 3);
  }
}

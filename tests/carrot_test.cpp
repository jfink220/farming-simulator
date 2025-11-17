#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"

TEST_CASE( "it returns a _ as its symbol as tilled soil" ) {
  Carrot carrot;
  REQUIRE( carrot.symbol() == "_" );
}

TEST_CASE( "it returns a V when the carrot is mature" ) {
  Carrot carrot;
  carrot.end_day();
  REQUIRE( carrot.symbol() == "V" );
}
TEST_CASE("cannot harvest a new carrot"){
  Carrot carrot;
  REQUIRE(carrot.can_harvest() == false);
}
TEST_CASE("can harvest after 1 day maturation"){
  Carrot carrot;
  carrot.end_day();
  REQUIRE(carrot.can_harvest() == true);
}
TEST_CASE("can harvest after 2 day maturation"){
  Carrot carrot;
  carrot.end_day();
  carrot.end_day();
  REQUIRE(carrot.can_harvest() == true);
}
TEST_CASE("watering increases age by 2 after ending the day"){
  Carrot carrot;
  carrot.water();
  carrot.end_day();
  REQUIRE(carrot.get_age() == 2);
}
TEST_CASE("watering twice on the same day causes no effect"){
  Carrot carrot;
  carrot.water();
  carrot.water();
  carrot.end_day();
  REQUIRE(carrot.get_age() == 2);
}
TEST_CASE("watering on one day does not effect days in the future"){
  Carrot carrot;
  carrot.water();
  carrot.end_day();
  carrot.end_day();
  REQUIRE(carrot.get_age() == 3);
}
TEST_CASE("watering supported on multiple days"){
  Carrot carrot;
  carrot.water();
  carrot.end_day();
  carrot.water();
  carrot.end_day();
  REQUIRE(carrot.get_age() == 4);
}

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"
#include "../src/farm.hpp"
#include "../src/carrot.hpp"
#include <iostream>
TEST_CASE( "it can be initialized with a single plot" ) {
  Player player;
  Farm farm(1, 1, &player);
  REQUIRE( farm.number_of_rows() == 1 );
  REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it can be initialized as a 1x2 farm" ) {
  Player player;
  Farm farm(1, 2, &player);
  REQUIRE( farm.number_of_rows() == 1 );
  REQUIRE( farm.number_of_columns() == 2 );
}

TEST_CASE( "it can be initialized as a 2x1 farm" ) {
  Player player;
  Farm farm(2, 1, &player);
  REQUIRE( farm.number_of_rows() == 2 );
  REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it returns the symbol for a single soil plot" ) {
  Player player;
  Farm farm(1, 1, &player);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
}

TEST_CASE( "it returns the symbols for a 1x2 farm" ) {
  Player player;
  Farm farm(1, 2, &player);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it returns the symbols for a 2x1 farm" ) {
  Player player;
  Farm farm(2, 1, &player);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
  REQUIRE( farm.get_symbol(1, 0) == "." );
}

TEST_CASE( "it allows us to plant a carrot" ) {
  Player player;
  Farm farm(1, 2, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  REQUIRE( farm.get_symbol(0, 1) == "v" );
}

TEST_CASE("carrot can only be harvested when mature"){
  Player player;
  Farm farm(3, 3, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  REQUIRE( farm.get_symbol(0, 1) == "v" );
  farm.harvest(0,1);
  REQUIRE( farm.get_symbol(0, 1) == "v" );
  farm.end_day();
  REQUIRE( farm.get_symbol(0, 1) == "V" );
  farm.harvest(0,1);
  REQUIRE(farm.get_symbol(0,1) == ".");
}

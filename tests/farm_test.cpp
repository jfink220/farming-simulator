#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"
#include "../src/farm.hpp"
#include "../src/carrot.hpp"
#include "../src/lettuce.hpp"
#include "../src/spinach.hpp"
#include "../src/brussel_sprout.hpp"
#include "../src/beet.hpp"
#include <iostream>
TEST_CASE( "it can be initialized with a single plot" ) {
  Player player;
  Bunny bunny;
  Farm farm(1, 1, &player, &bunny);
  REQUIRE( farm.number_of_rows() == 1 );
  REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it can be initialized as a 1x2 farm" ) {
  Player player;
  Bunny bunny;
  Farm farm(1, 2, &player, &bunny);
  REQUIRE( farm.number_of_rows() == 1 );
  REQUIRE( farm.number_of_columns() == 2 );
}

TEST_CASE( "it can be initialized as a 2x1 farm" ) {
  Player player;
  Bunny bunny;
  Farm farm(2, 1, &player, &bunny);
  REQUIRE( farm.number_of_rows() == 2 );
  REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it returns the symbol for a single soil plot" ) {
  Player player;
  Bunny bunny;
  Farm farm(1, 1, &player, &bunny);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
}

TEST_CASE( "it returns the symbols for a 1x2 farm" ) {
  Player player;
  Bunny bunny;
  Farm farm(1, 2, &player, &bunny);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it returns the symbols for a 2x1 farm" ) {
  Player player;
  Bunny bunny;
  Farm farm(2, 1, &player, &bunny);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
  REQUIRE( farm.get_symbol(1, 0) == "." );
}

TEST_CASE( "it allows us to plant a carrot" ) {
  Player player;
  Bunny bunny;
  Farm farm(1, 2, &player, &bunny);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  REQUIRE( farm.get_symbol(0, 1) == "_" );
}

TEST_CASE("carrot can only be harvested when mature"){
  Player player;
  Bunny bunny;
  Farm farm(3, 3, &player, &bunny);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  REQUIRE( farm.get_symbol(0, 1) == "_" );
  farm.harvest(0,1);
  REQUIRE( farm.get_symbol(0, 1) == "_" );
  farm.end_day();
  REQUIRE( farm.get_symbol(0, 1) == "V" );
  farm.harvest(0,1);
  REQUIRE(farm.get_symbol(0,1) == ".");
}
TEST_CASE("can water a carrot"){
  Player player;
  Bunny bunny;
  Farm farm(3, 3, &player, &bunny);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  farm.water(0,1);
  farm.end_day();
  REQUIRE(carrot->get_age() == 2);
}
TEST_CASE("cannot plant one seed over another"){
  Player player;
  Bunny bunny;
  Farm farm(3, 3, &player, &bunny);
  Carrot *carrot = new Carrot();
  Lettuce *lettuce = new Lettuce();
  farm.plant(0,1, carrot);
  farm.plant(0,1, lettuce);
  farm.end_day();
  REQUIRE(farm.get_symbol(0,1) == "V");
}
TEST_CASE("nothing happens when watering bare soil"){
  Player player;
  Bunny bunny;
  Farm farm(3, 3, &player, &bunny);
  farm.water(0,1);
  farm.end_day();
  REQUIRE(farm.get_symbol(0,1) == ".");
}
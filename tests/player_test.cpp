#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"

TEST_CASE( "it starts the player in row zero, column zero" ) {
  Player player;
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player to the right" ) {
  Player player;
  player.move_right(3, -1, -1);
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 1 );
}

TEST_CASE( "it moves the player down" ) {
  Player player;
  player.move_down(3, -1, -1);
  REQUIRE( player.row() == 1 );
  REQUIRE( player.column() == 0 );
}
TEST_CASE("player is unable to move out of bounds"){
  Player player;
  player.move_left(-1,-1);
  player.move_up(-1,-1);
  int tot_rows{3};
  int tot_cols{3};
  REQUIRE(player.column() == 0);
  REQUIRE(player.row() == 0);

  for(int i =0; i < 5; i++){
    player.move_right(tot_cols, -1, -1);
    player.move_down(tot_rows, -1, -1);
  }
  REQUIRE(player.row() == tot_rows-1);
  REQUIRE(player.column() == tot_cols-1);
}

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/bunny.hpp"

TEST_CASE("bunny can move up out of bounds to despawn"){
    Bunny bunny;
    bunny.spawn(1,1);
    bunny.move_up();
    bunny.move_up();
    REQUIRE(bunny.is_spawned() == false);
}

TEST_CASE("bunny can move right out of bounds to despawn"){
    Bunny bunny;   
    bunny.spawn(1,1);
    int TOT_COLUMNS = 2;
    bunny.move_right(TOT_COLUMNS);
    bunny.move_right(TOT_COLUMNS);
    REQUIRE(bunny.is_spawned() == false);
}

TEST_CASE("bunny can move left out of bounds to despawn"){
    Bunny bunny;
    bunny.spawn(1,1);
    bunny.move_left();
    bunny.move_left();    
    REQUIRE(bunny.is_spawned() == false);
}

TEST_CASE("bunny can move down out of bounds to despawn"){
    Bunny bunny;
    bunny.spawn(1,1);
    int TOT_ROWS = 2;
    bunny.move_down(TOT_ROWS);
    bunny.move_down(TOT_ROWS);
    REQUIRE(bunny.is_spawned() == false);
}

TEST_CASE("bunny will panic when player is to its right"){
    Bunny bunny;
    bunny.spawn(1,1);
    const int PLR_ROW = 1;
    const int PLR_COLUMN = 2;
    const int TOT_ROWS = 3;
    const int TOT_COLUMNS = 3;
    REQUIRE(bunny.is_panicking(TOT_ROWS, TOT_COLUMNS, PLR_ROW, PLR_COLUMN) == true);
}
TEST_CASE("bunny will panic when player is to its left"){
    Bunny bunny;
    bunny.spawn(1,1);
    const int PLR_ROW = 1;
    const int PLR_COLUMN = 0;
    const int TOT_ROWS = 3;
    const int TOT_COLUMNS = 3;
    REQUIRE(bunny.is_panicking(TOT_ROWS, TOT_COLUMNS, PLR_ROW, PLR_COLUMN) == true);
}
TEST_CASE("bunny will panic when player is underneath it"){
    Bunny bunny;
    bunny.spawn(1,1);
    const int PLR_ROW = 2;
    const int PLR_COLUMN = 1;
    const int TOT_ROWS = 3;
    const int TOT_COLUMNS = 3;
    REQUIRE(bunny.is_panicking(TOT_ROWS, TOT_COLUMNS, PLR_ROW, PLR_COLUMN) == true);
}
TEST_CASE("bunny will panic when player is above it"){
    Bunny bunny;
    bunny.spawn(1,1);
    const int PLR_ROW = 0;
    const int PLR_COLUMN = 1;
    const int TOT_ROWS = 3;
    const int TOT_COLUMNS = 3;
    REQUIRE(bunny.is_panicking(TOT_ROWS, TOT_COLUMNS, PLR_ROW, PLR_COLUMN) == true);
}
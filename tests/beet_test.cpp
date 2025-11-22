#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/beet.hpp"

TEST_CASE("beets naturally mature after 5 days "){
    Beet beet;
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    REQUIRE(beet.symbol() == "B");
}
TEST_CASE("can expedite growing process by watering"){
    Beet beet;
    beet.water();
    beet.end_day();
    beet.water();
    beet.end_day();
    beet.water();
    beet.end_day();
    REQUIRE(beet.symbol() == "B");
}
TEST_CASE("beet naturally sprouts after 2 days"){
    Beet beet;
    beet.end_day();
    beet.end_day();
    REQUIRE(beet.symbol() == "!");
}
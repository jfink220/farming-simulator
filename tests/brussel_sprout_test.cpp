#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/brussel_sprout.hpp"

TEST_CASE("brussel sprout matures after 10 days"){
    Brussel_Sprout brussel_sprout;
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    REQUIRE(brussel_sprout.symbol() == "N");
    REQUIRE(brussel_sprout.can_harvest() == true);
}
TEST_CASE("can expedite maturation process to 5 days by watering"){
    Brussel_Sprout brussel_sprout;
    brussel_sprout.water();
    brussel_sprout.end_day();
    brussel_sprout.water();
    brussel_sprout.end_day();
    brussel_sprout.water();
    brussel_sprout.end_day();
    brussel_sprout.water();
    brussel_sprout.end_day();
    brussel_sprout.water();
    brussel_sprout.end_day();
    REQUIRE(brussel_sprout.symbol() == "N");
    REQUIRE(brussel_sprout.can_harvest() == true);
}
TEST_CASE("sprouting naturally occurs after 5 days"){
    Brussel_Sprout brussel_sprout;
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    brussel_sprout.end_day();
    REQUIRE(brussel_sprout.symbol() == "!");
}
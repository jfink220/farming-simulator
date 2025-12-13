#pragma once

#include <string>
#include <vector>

#include "plot.hpp"
#include "player.hpp"
#include "bunny.hpp"

class Farm{
  private:
    int rows;
    int columns;
    Player *player;
    std::vector<std::vector<Plot *>> plots;
    int dayNum;
    Bunny *bunny;
    bool bunny_on = true;

  public:
    Farm(int rows, int columns, Player *player, Bunny *bunny, bool bunny_on);
    int number_of_rows();
    int number_of_columns();
    std::string get_symbol(int row, int column);
    void plant(int row, int column, Plot *plot);
    void harvest(int row, int column);
    void end_day();
    int day_num();
    void water(int row, int column);
    void spawn();
    void delete_crop(int row, int column);
    void bunny_off();
    ~Farm();
};

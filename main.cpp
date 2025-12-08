#include <iostream>
#include <ctime>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"
#include "src/lettuce.hpp"
#include "src/spinach.hpp"
#include "src/beet.hpp"
#include "src/brussel_sprout.hpp"

int main() {
  std::srand(std::time(0));
  Player player;
  Bunny bunny;
  int farm_rows{7};
  int farm_columns{8};
  Farm farm(farm_rows, farm_columns, &player, &bunny);
  FarmPrinter printer(&farm);
  bool game_in_progress = true;
  std::string player_input;

  while(game_in_progress) {
    ansi_clear();
    std::cout << "Control Legend: " << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Movement: w - move up, a - move left, s - move down, d - move right" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Actions: h - harvest, t - water plant, e - end day, q - end game" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Planting: c - plant carrot, l - plant lettuce, u - plant spinach, b - plant beet, \nn - plant brussel sprouts" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Day Number: " << farm.day_num() << std::endl;
    std::cout << printer.pp() << std::endl;
    std::cin >> player_input;

    if(player_input == "q") {
      game_in_progress = false;
      std::cout << "\nThank you for playing the Farming Simulator." << std::endl;
    } else if(player_input == "d") {
      player.move_right(farm_columns);
    } else if(player_input == "s") {
      player.move_down(farm_rows);
    } else if(player_input == "a"){
      player.move_left();
    } else if(player_input == "w"){
      player.move_up();
    }else if(player_input == "c") {
      Carrot *carrot = new Carrot();
      farm.plant(player.row(), player.column(), carrot);
    }else if(player_input == "h"){
      farm.harvest(player.row(),player.column());
    }else if(player_input == "e"){
      farm.end_day();
    }else if(player_input == "t"){
      farm.water(player.row(),player.column());
    }else if(player_input == "l"){
      Lettuce *lettuce = new Lettuce();
      farm.plant(player.row(), player.column(), lettuce);
    }else if(player_input == "u"){
      Spinach *spinach = new Spinach();
      farm.plant(player.row(), player.column(), spinach);
    }else if(player_input == "b"){
      Beet *beet = new Beet();
      farm.plant(player.row(), player.column(), beet);
    }else if(player_input == "n"){
      Brussel_Sprout *brussel_sprout = new Brussel_Sprout();
      farm.plant(player.row(), player.column(), brussel_sprout);
    }
  }
}

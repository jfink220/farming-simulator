#include <iostream>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"

int main() {
  Player player;
  int farm_rows{7};
  int farm_columns{8};
  Farm farm(farm_rows, farm_columns, &player);
  FarmPrinter printer(&farm);
  bool game_in_progress = true;
  std::string player_input;

  while(game_in_progress) {
    ansi_clear();
    std::cout << "Control Legend: " << std::endl;
    std::cout << "Movement: w - move up, a - move left, s - move down, d - move right" << std::endl;
    std::cout << "Actions: c - plant carrot, h - harvest, e - end day, q - end game\n" << std::endl;
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
    }
  }
}

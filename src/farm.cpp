#include <string>
#include <vector>
#include <iostream>
#include "farm.hpp"
#include "soil.hpp"

Farm::Farm(int rows, int columns, Player *player, Bunny *bunny, bool bunny_on) : rows(rows), columns(columns), player(player), bunny(bunny), dayNum(1), bunny_on(bunny_on) {
  for(int i = 0; i < rows; i++) {
    std::vector<Plot *> row;
    for(int j = 0; j < columns; j++) {
      Soil *soil = new Soil();
      row.push_back(soil);
    }
    plots.push_back(row);
  }

  if(bunny_on && bunny->can_spawn()){
    spawn();
  }
}

void Farm::spawn(){
  int side_1 = (rand()%2);
  int b_row = (side_1 == 0) ? rand()%rows : 0;
  int b_column = (side_1 == 0) ? 0 : rand()%columns;
  while(b_row == player->row() && b_column == player->column()){
    side_1 = (rand()%2);
    b_row = (side_1 == 0) ? rand()%rows : 0;
    b_column = (side_1 == 0) ? 0 : rand()%columns;
  }
  bunny->spawn(b_row, b_column);
}

int Farm::number_of_rows() {
  return rows;
}


int Farm::number_of_columns() {
  return columns;
}

int Farm::day_num(){
  return dayNum;
}

std::string Farm::get_symbol(int row, int column) {
  if(player->row() == row && player->column() == column) {
    return "@";
  } else if(bunny->row() == row && bunny->column() == column && bunny_on){
    return "&";
  }
  else {
    return plots.at(row).at(column)->symbol();
  }
}

void Farm::plant(int row, int column, Plot *plot) {
  Plot *current_plot = plots.at(row).at(column);
  if(current_plot->symbol() == "."){
    plots.at(row).at(column) = plot;
    delete current_plot;
  }

}

void Farm::harvest(int row, int column){
  Plot *current_plot = plots.at(row).at(column);
  if (current_plot->can_harvest()){
    Plot *new_plot = new Soil();
    plots.at(row).at(column) = new_plot;
    delete current_plot;
  }


}

void Farm::end_day(){
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      plots.at(i).at(j)->end_day();
    }
  }
  dayNum += 1;
  if(bunny->can_spawn()){
    spawn();
  }else{
    delete_crop(bunny->row(), bunny->column());
    if(!bunny->is_panicking(rows, columns, player->row(), player->column())){
      int choice = rand()%10;
      if(choice == 0){
        bunny->move_left();
      }
      else if(choice == 1){
        bunny->move_up();
      }
      else if(choice == 2){
        bunny->move_down(rows);
      }
      else if(choice >= 3){
        bunny->move_right(columns);        
      }
    }
  }
  
}
void Farm::water(int row, int column){
  Plot *current_plot = plots.at(row).at(column);
  current_plot->water();
}

void Farm::delete_crop(int row, int column){
  if(row >= 0 && column >= 0 && row < rows && column < columns){
    Plot *current_plot = plots.at(row).at(column);
    Plot *new_plot = new Soil();
    plots.at(row).at(column) = new_plot;
    delete current_plot;
  }

}

Farm::~Farm(){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      delete plots.at(i).at(j);
    }
  }
}

void Farm::bunny_off(){
  bunny_on = false;
}



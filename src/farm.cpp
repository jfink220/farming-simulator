#include <string>
#include <vector>

#include "farm.hpp"
#include "soil.hpp"

Farm::Farm(int rows, int columns, Player *player) : rows(rows), columns(columns), player(player), dayNum(1) {
  for(int i = 0; i < rows; i++) {
    std::vector<Plot *> row;
    for(int j = 0; j < columns; j++) {
      Soil *soil = new Soil();
      row.push_back(soil);
    }
    plots.push_back(row);
  }
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
  } else {
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

// write tests
void Farm::end_day(){
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      plots.at(i).at(j)->end_day();
    }
  }
  dayNum += 1;
}
Farm::~Farm(){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      delete plots.at(i).at(j);
    }
  }
}



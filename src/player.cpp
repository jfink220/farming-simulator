#include "player.hpp"

int Player::row() {
  return current_row;
}

int Player::column() {
  return current_column;
}

void Player::move_right(const int columns, int b_row, int b_column) {
  if(current_column < columns-1){
    if(current_column+1 != b_column || current_row != b_row){
      current_column += 1;
    }
  }
}

void Player::move_down(int rows, int b_row, int b_column) {
  if(current_row < rows-1){
    if(current_row+1 != b_row || current_column != b_column){
      current_row += 1;
    }
  }
}

void Player::move_up(int b_row, int b_column){
  if(current_row > 0){
    if(current_row-1 != b_row || current_column != b_column){
      current_row -= 1;
    }
  }
}

void Player::move_left(int b_row, int b_column){
  if(current_column > 0){
    if(current_column-1 != b_column || current_row != b_row){
      current_column -= 1;
    }
  }
}

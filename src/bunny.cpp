#include <cstdlib>
#include "bunny.hpp"
bool Bunny::can_spawn(){
    if(spawned){
        return false;
    }
    else{
        int rand_val = std::rand()%10;
        return rand_val==0;
    }
}

void Bunny::spawn(int row, int column){
    current_row = row;
    current_column = column;
    spawned = true;
}

int Bunny::row(){
    return current_row;
}

int Bunny::column(){
    return current_column;
}

void Bunny::move_right(int columns) {
    if(spawned){
        current_column += 1;
        if(current_column > columns-1){
            spawned = false;
        }
    }
}

void Bunny::move_down(int rows) {
  if(current_row < rows-1){
    current_row += 1;
  }
}

void Bunny::move_up(){
  if(current_row > 0){
    current_row -= 1;
  }
}

void Bunny::move_left(){
  if(current_column > 0){
    current_column -= 1;
  }
}
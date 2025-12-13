#include <cstdlib>
#include "bunny.hpp"
bool Bunny::can_spawn(){
    if(spawned){
        return false;
    }
    else{
        int rand_val = std::rand()%1;
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
    if(spawned){
        current_row += 1;
        if(current_row > rows-1){
            spawned = false;
        }
    }
}

void Bunny::move_up(){
    if(spawned){
        current_row -= 1;
        if(current_row < 0){
            spawned = false;
        }
    }
}

void Bunny::move_left(){
    if(spawned){
        current_column -= 1;
        if(current_column < 0){
            spawned = false;
        }
    }
}

bool Bunny::is_panicking(int rows, int columns, int plr_row, int plr_column){
    if(spawned){
        if(current_column-1 == plr_column && current_row == plr_row){
            move_right(columns);
            move_right(columns);
            move_right(columns);
            move_right(columns);
            return true;
        }
        else if(current_column+1 == plr_column && current_row == plr_row){
            move_left();
            move_left();
            move_left();
            move_left();
            return true;
        }
        else if(current_row-1 == plr_row && current_column == plr_column){
            move_down(rows);
            move_down(rows);
            move_down(rows);
            move_down(rows);
            return true;
        }
        else if(current_row+1 == plr_row && current_column == plr_column){
            move_up();
            move_up();
            move_up();
            move_up();
            return true;
        }

    }
    return false;
}
bool Bunny::is_spawned(){
    return spawned;
}
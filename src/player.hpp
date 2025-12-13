#pragma once

class Player {
  private:
    int current_row = 0;
    int current_column = 0;

  public:
    int row();
    int column();
    void move_right(int columns, int b_row, int b_column);
    void move_down(int rows, int b_row, int b_column);
    void move_up(int b_row, int b_column);
    void move_left(int b_row, int b_column);
};

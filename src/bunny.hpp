class Bunny{
    private:
        bool spawned = false;
        int current_row = -1;
        int current_column = -1;
    public:
        int row();
        int column();
        void move_right(int columns);
        void move_down(int rows);
        void move_up();
        void move_left();
        void end_day();
        void spawn(int row, int column);
        bool can_spawn();
};
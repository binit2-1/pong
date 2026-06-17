#pragma once
#include "raylib.h"

class Ball{
    private:
        int x, y;
        int radius;
        int speed_x, speed_y;
    
    public:
        Ball(int x, int y, int radius, int speed_x, int speed_y);
        void Draw();
        void Update();
};
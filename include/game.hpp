#pragma once
#include "raylib.h"

class Ball{
    public:
        int x, y;
        int radius;
        int speed_x, speed_y;
        Ball(int x, int y, int radius, int speed_x, int speed_y);
        void Draw();
        void Update();
};

class Player{
    protected:
        int x, y;
        int width, height;
        int speed;

    public: 
        Player(int x, int y, int width, int height, int speed);
        void Draw();
        void Update();
        void LimitMovement();
};

class Cpu:public Player{
    public:
        Cpu(int x, int y, int width, int height, int speed);
        void Update(int ball_y);
};
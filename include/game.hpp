#pragma once
#include "raylib.h"

class Ball{
    public:
        float x, y;
        float radius;
        float speed_x, speed_y;
        Ball(float x, float y, float radius, float speed_x, float speed_y);
        void Draw();
        void ResetBall();
        int Update();
};

class Player{
    public:
        float x, y;
        float width, height;
        float speed;
        Player(float x, float y, float width, float height, float speed);
        void Draw();
        void Update();
        void LimitMovement();
};

class Cpu:public Player{
    public:
        Cpu(float x, float y, float width, float height, float speed);
        void Update(float ball_y);
};
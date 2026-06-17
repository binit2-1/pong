#include "game.hpp"

Ball::Ball(int x, int y, int radius, int speed_x, int speed_y){
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->speed_x = speed_x;
    this->speed_y = speed_y;
}

void Ball::Draw(){
    DrawCircle(x, y, radius, WHITE);
}

void Ball::Update(){
   x += speed_x;
   y += speed_y;

   if(y - radius  <=0 || y + radius > GetScreenHeight()){
        speed_y *= -1;
   }

   if(x - radius <= 0 || x + radius > GetScreenWidth()){
        speed_x *= -1;
   }   
}

Player::Player(int x, int y, int width, int height, int speed){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speed = speed;
}

void Player::Draw(){
    DrawRectangle(x, y, width, height, WHITE);
}

void Player::Update(){
    if(IsKeyDown(KEY_UP) && y > 0){
        y -= speed;
    }

    if(IsKeyDown(KEY_DOWN) && y + height < GetScreenHeight()){
        y += speed;
    }
}
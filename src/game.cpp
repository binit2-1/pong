#include "game.hpp"

Ball::Ball(float x, float y, float radius, float speed_x, float speed_y){
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

Player::Player(float x, float y, float width, float height, float speed){
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
    if(IsKeyDown(KEY_UP)){
        y -= speed;
    }

    if(IsKeyDown(KEY_DOWN)){
        y += speed;
    }

    LimitMovement();
}

void Player::LimitMovement(){
    if(y < 0){
        y = 0;
    }
    if(y + height >= GetScreenHeight()){
        y = GetScreenHeight() - height;
    }
}

Cpu::Cpu(float x, float y, float width, float height, float speed)
    :Player(x, y, width, height, speed){
    
}

void Cpu::Update(float ball_y){
    if(y+height/2 < ball_y){
        y += speed;
    }
    else if(y+height/2 > ball_y){
        y -= speed;
    }

    LimitMovement();
}
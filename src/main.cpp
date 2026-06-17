#include "raylib.h"
#include "game.hpp"


int main(){
    const int screenHeight = 800;
    const int screenWidth = 1280;


    InitWindow(screenWidth, screenHeight, "Pong Game");
    SetTargetFPS(60);

    Ball ball(screenWidth/2, screenHeight/2, 10, 7, 7);
    Player player(screenWidth - 35, screenHeight/2 - 50, 20, 100, 7);
    Cpu cpu(10, screenHeight/2 - 50, 20, 100, 7);

    while(!WindowShouldClose()){
        BeginDrawing();

        //Update
        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        //check collision with paddles 
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius,Rectangle{player.x, player.y, player.width, player.height})){
            ball.speed_x *= -1;
        }
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius,Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})){
            ball.speed_x *= -1;
        }

        //Draw
        ClearBackground(BLACK);
        ball.Draw();
        player.Draw();
        cpu.Draw();

        EndDrawing();
    }
    CloseWindow();
}
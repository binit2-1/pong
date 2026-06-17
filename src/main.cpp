#include "raylib.h"
#include "game.hpp"


int main(){
    const int screenHeight = 800;
    const int screenWidth = 1280;


    InitWindow(screenWidth, screenHeight, "Pong Game");
    SetTargetFPS(60);

    Ball ball(screenWidth/2, screenHeight/2, 10, 7, 7);

    while(!WindowShouldClose()){
        BeginDrawing();

        ball.Update();
        ClearBackground(BLACK);
        ball.Draw();

        EndDrawing();
    }
    CloseWindow();
}
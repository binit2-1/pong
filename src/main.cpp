#include "raylib.h"
#include "game.hpp"

int player_score = 0;
int cpu_score = 0;

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
        int result = ball.Update();
        
        if (result == 1) cpu_score++;
        else if (result == 2) player_score++;

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

        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
        DrawCircleLines(screenWidth/2, screenHeight/2, 70, WHITE);
        DrawText(TextFormat("%i", cpu_score), screenWidth/4, 20, 80, WHITE);
        DrawText(TextFormat("%i", player_score), 3*screenWidth/4, 20, 80, WHITE);

        ball.Draw();
        player.Draw();
        cpu.Draw();

        EndDrawing();
    }
    CloseWindow();
}
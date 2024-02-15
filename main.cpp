#include "raylib.h"
#include <iostream>

using namespace std;

int main() {
    float ballSize = 15;
    float ballX = 400;
    float ballY = 300;
    float ballSpeedX = 6;
    float ballSpeedY = 4;

    Font ft = LoadFont("resources/fonts/pixantiqua.png");

    InitWindow(800, 600, "Pong");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        
        ballX += ballSpeedX;
        ballY += ballSpeedY;

        if (ballX >= 800 - ballSize || ballX <= 0 + ballSize) {
            ballSpeedX *= -1;
        }
        if (ballY >= 600 - ballSize || ballY <= 0 + ballSize) {
            ballSpeedY *= -1;
        }
        
        BeginDrawing();
            ClearBackground(WHITE);
            
            DrawTextEx(ft, "Test", Vector2{ 385, 285 }, 15, 1, Color(BLACK));

            DrawCircle(ballX, ballY, ballSize, Color(BLACK));
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
#include "raylib.h"
#include <iostream>

using namespace std;

int main() {
    int ballX = 400;
    int ballY = 300;
    int ballSpeedX = 8;
    int ballSpeedY = 8;

    int padX = 0;
    int padY = 0; 
    int aiPadX = 550;
    int aiPadY = 0;
    int padSpeed = 10; 

    InitWindow(800, 600, "Pong.exe");
    SetTargetFPS(60);

    Font ft = LoadFont("resources/pixantiqua.ttf");

    while (!WindowShouldClose()) {
        ballX += ballSpeedX;
        ballY += ballSpeedY;
 
        if (ballX + 15 > 800) {
            ballSpeedX *= -1;
        }
        if (ballX - 15 < 0) {
            ballSpeedX *= -1;
        }
        if (ballY + 15 > 600) {
            ballSpeedY *= -1;
        }
        if (ballY - 15 < 0) {
            ballSpeedY *= -1;
        }

        if ((ballX + 15 >= padX) && (ballX - 15 <= padX + 10) && (ballY + 15 >= padY) && (ballY - 15 <= padY + 10)) {
            ballSpeedX = -ballSpeedX;
        }
        if ((ballX + 15 >= aiPadX) && (ballX - 15 <= aiPadX + 10) && (ballY + 15 >= aiPadY) && (ballY - 15 <= aiPadY + 10)) {
            ballSpeedX = -ballSpeedX;
        }

        if (IsKeyDown(KEY_W)) {
            padY -= padSpeed;
        }
        if (IsKeyDown(KEY_S)) {
            padY += padSpeed;
        }

        if (IsKeyDown(KEY_UP)) {
            aiPadY -= padSpeed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            aiPadY += padSpeed;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawTextEx(ft, TextFormat("0"), Vector2{ 400, 50 }, 50, 2, WHITE);
        DrawTextEx(ft, TextFormat("0"), Vector2{ 400, 50 }, 50, 2, WHITE);

        for (float i = 0; i < 600; i += 100) {
            DrawLineEx(Vector2{ 400, i }, Vector2{ 400, i + 50 }, 5, WHITE);
        }

        DrawCircle(ballX, ballY, 15, RED);

        DrawRectangle(100, padY, 30, 150, WHITE);
        DrawRectangle(1700, aiPadY, 30, 150, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

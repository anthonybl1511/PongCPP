#include "raylib.h"
#include <iostream>
#include "string"

using namespace std;

int main() {
    int ballX = 400;
    int ballY = 300;
    int ballSpeedX = 4;
    int ballSpeedY = 4;

    int padX = 10;
    int padY = 0; 
    int aiPadX = 770;
    int aiPadY = 0;
    int padSpeed = 10; 

    int score = 0;
    int aiScore = 0;

    InitWindow(800, 600, "Pong.exe");
    SetTargetFPS(60);

    Font ft = LoadFont("resources/pixantiqua.ttf");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        
        ballX += ballSpeedX;
        ballY += ballSpeedY;
 
        if (ballX + 5 > 800) {
            ballSpeedX *= -1;
        }
        if (ballX - 5 < 0) {
            ballSpeedX *= -1;
        }
        if (ballY + 5 > 600) {
            ballSpeedY *= -1;
        }
        if (ballY - 5 < 0) {
            ballSpeedY *= -1;
        }

        /*if ((ballX + 5 >= padX) && (ballX - 5 <= padX + 10) && (ballY + 5 >= padY) && (ballY - 5 <= padY + 10)) {
            ballSpeedX = -ballSpeedX;
        }
        if ((ballX + 5 >= aiPadX) && (ballX - 5 <= aiPadX + 10) && (ballY + 5 >= aiPadY) && (ballY - 5 <= aiPadY + 10)) {
            ballSpeedX = -ballSpeedX;
        }*/

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

        DrawTextEx(ft, to_string(score).c_str(), Vector2{315, 50}, 50, 2, GRAY);
        DrawTextEx(ft, to_string(aiScore).c_str(), Vector2{ 450, 50 }, 50, 2, GRAY);

        for (float i = 0; i < 600; i += 50) {
            DrawLineEx(Vector2{ 400, i }, Vector2{ 400, i + 20 }, 10, GRAY);
        }

        DrawCircle(ballX, ballY, 10, BLACK);

        Rectangle rec1 = { padX, padY, 20, 120 };
        Rectangle rec2 = { aiPadX, aiPadY, 20, 120 };
        DrawRectangleRounded(rec1, 10, 3, BLACK);
        DrawRectangleRounded(rec2, 10, 3, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

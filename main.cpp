#include "raylib.h"
#include <iostream>
#include "string"
using namespace std;

int main() {
    int ballX = 400;
    int ballY = 300;
    int ballSpeedX = 4;
    int ballSpeedY = 2;

    int padX = 10;
    int padY = 0; 
    int aiPadX = 770;
    int aiPadY = 0;
    int padSpeed = 10;
    int aiPadSpeed = 5;

    int playerScore = 0;
    int aiScore = 0;
    string winner;

    enum Scene {
        menu,
        game,
        score
    };
    Scene activeScene = Scene::menu;

    bool soloMode = true;

    InitWindow(800, 600, "Pong.exe");
    InitAudioDevice();
    SetTargetFPS(60);

    Music music = LoadMusicStream("resources/sounds/music.wav");
    Sound touchSFX = LoadSound("resources/sounds/touch.wav");
    Sound pointSFX = LoadSound("resources/sounds/point.wav");
    Font ft = LoadFont("resources/pixantiqua.ttf");

    PlayMusicStream(music);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
;
        switch (activeScene)
        {
        case Scene::menu: 
        {
            DrawTextEx(ft, "PONG", Vector2{320, 50}, 60, 2, BLACK);
            DrawTextEx(ft, "Press any key to start.", Vector2{270, 300}, 20, 2, BLACK);

            if (IsKeyDown(KEY_SPACE)) {
                activeScene = Scene::game;
            }
        }
            break;
        case Scene::game:
        {
            UpdateMusicStream(music);
            if (playerScore == 10) {
                winner = "Player 1";
                activeScene = Scene::score;
            }
            if (aiScore == 10) {
                winner = "Player 2";
                activeScene = Scene::score;
            }

            ballX += ballSpeedX;
            ballY += ballSpeedY;

            if (ballX + 5 > 800) {
                PlaySound(pointSFX);

                ballSpeedX *= -1;
                playerScore++;

                ballX = 400;
                ballY = 300;
                ballSpeedX = -4;
                ballSpeedY = 2;
            }
            if (ballX - 5 < 0) {
                PlaySound(pointSFX);

                ballSpeedX *= -1;
                aiScore++;

                ballX = 400;
                ballY = 300;
                ballSpeedX = 4;
                ballSpeedY = 2;
            }
            if (ballY + 5 > 600) {
                PlaySound(touchSFX);

                ballSpeedY *= -1;
            }
            if (ballY - 5 < 0) {
                PlaySound(touchSFX);

                ballSpeedY *= -1;
            }

            if (ballX - 5 <= padX + 20 && ballY > padY && ballY < padY + 120) {
                PlaySound(touchSFX);

                ballSpeedX *= -1.3f;
                ballSpeedY *= 1.4f;
            }
            if (ballX + 5 >= aiPadX && ballY > aiPadY && ballY < aiPadY + 120) {
                PlaySound(touchSFX);

                ballSpeedX *= -1.3f;
                ballSpeedY *= 1.4f;
            }

            if (IsKeyDown(KEY_W) && padY > 0) {
                padY -= padSpeed;
            }
            if (IsKeyDown(KEY_S) && padY + 120 < 600) {
                padY += padSpeed;
            }
            if (soloMode) {
                if (ballY < aiPadY + 60 && aiPadY > 0) {
                    aiPadY -= aiPadSpeed;
                }
                else if (ballY > aiPadY + 60 && aiPadY + 120 < 600) {
                    aiPadY += aiPadSpeed;
                }
            }
            else {
                if (IsKeyDown(KEY_UP) && aiPadY > 0) {
                    aiPadY -= aiPadSpeed;
                }
                if (IsKeyDown(KEY_DOWN) && aiPadY + 120 < 600) {
                    aiPadY += aiPadSpeed;
                }
            }
            

            DrawTextEx(ft, to_string(playerScore).c_str(), Vector2{ 315, 50 }, 50, 2, GRAY);
            DrawTextEx(ft, to_string(aiScore).c_str(), Vector2{ 450, 50 }, 50, 2, GRAY);

            for (float i = 0; i < 600; i += 50) {
                DrawLineEx(Vector2{ 400, i }, Vector2{ 400, i + 20 }, 10, GRAY);
            }

            DrawCircle(ballX, ballY, 10, BLACK);

            Rectangle rec1 = { padX, padY, 20, 120 };
            Rectangle rec2 = { aiPadX, aiPadY, 20, 120 };
            DrawRectangleRounded(rec1, 10, 3, BLACK);
            DrawRectangleRounded(rec2, 10, 3, BLACK);

            if (IsKeyDown(KEY_M)) {
                activeScene = Scene::menu;
            }
        }
            break;
        case Scene::score:
        {
            playerScore = 0;
            aiScore = 0;

            DrawTextEx(ft, "GAME OVER", Vector2{ 320, 50 }, 60, 2, BLACK);
            DrawTextEx(ft, (winner + " wins!").c_str(), Vector2{ 370, 200 }, 40, 2, BLACK);
            DrawTextEx(ft, "Press M to return to menu or SPACE to restart.", Vector2{ 100, 300 }, 20, 2, BLACK);

            if (IsKeyDown(KEY_M)) {
                activeScene = Scene::menu;
            }
            if (IsKeyDown(KEY_SPACE)) {
                activeScene = Scene::game;
            }
        }
            break;
        }

        EndDrawing();
    }

    UnloadMusicStream(music);
    UnloadSound(touchSFX);
    UnloadSound(pointSFX);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

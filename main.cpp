#include <raylib.h>
#include <string>
#include "game.hpp"

int main()
{
    int windowWidth = 1400;
    int windowHeight = 800;

    InitWindow(windowWidth, windowHeight, "Apple Catcher");
    InitAudioDevice();

    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        game.Update();

        BeginDrawing();
        ClearBackground(SKYBLUE);
        DrawRectangle(0, 640, 1400, 160, GREEN);
        std::string scoreText = "SCORE: " + std::to_string(game.score);
        DrawText(scoreText.c_str(), 50,740, 34, BROWN);
        std::string highscoreText = "HIGH SCORE: " + std::to_string(game.highscore);
        DrawText(highscoreText.c_str(), 1050, 740, 34, BROWN);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}
#include <raylib.h>
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
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}
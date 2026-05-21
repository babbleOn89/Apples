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

        game.Draw();
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}

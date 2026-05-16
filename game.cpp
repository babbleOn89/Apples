#include "game.hpp"
#include <iostream>
#include <fstream>

Game::Game()
{
    music = LoadMusicStream("Sounds/bgtrack.ogg");
    fallingSound = LoadSound("Sounds/falling.ogg");
    gameOverSound = LoadSound("Sounds/lvlcomplete.ogg");
    PlayMusicStream(music);
    run = true;
    score = 0;
    highscore = LoadHighscoreFromFile();
    timeLeft = 45.0f;
    CreateTrees();
}

Game::~Game()
{
    UnloadMusicStream(music);
    UnloadSound(fallingSound);
    UnloadSound(gameOverSound);
}

void Game::Update()
{
    if(run)
    {
        timeLeft -= GetFrameTime();
        if(timeLeft <= 0)
        {
            timeLeft = 0;
            run = false; //game over

            StopMusicStream(music);
            PlaySound(gameOverSound);

            return;
        }

        apple.Update();

        if(CheckCollisionRecs(player.GetBasketRect(), apple.getRect()))
        {
            std::cout << "Apple Caught!\n";
            score++;
            CheckForHighscore();
            apple.Reset();

            PlaySound(fallingSound);
        }

    }
}    

void Game::CreateTrees()
{
    trees.emplace_back(Vector2{-180, -200});
    trees.emplace_back(Vector2{180, -200});
    trees.emplace_back(Vector2{500, -200});
    trees.emplace_back(Vector2{800, -200});
}

void Game::Draw()
{
    for(auto& tree : trees)
    {
        tree.Draw();
    }
    apple.Draw();
    player.Draw();

    //Debug Hitboxes
    //Rectangle basket = player.GetBasketRect();
    //Rectangle appleBox = apple.getRect();

    //DrawRectangleLines(
        //basket.x,
        //basket.y,
        //basket.width,
        //basket.height,
        //BLACK
    //);

    //DrawRectangleLines(
        //appleBox.x,
        //appleBox.y,
        //appleBox.width,
        //appleBox.height,
        //BLUE
    //);

    int timer = (int)timeLeft;
    const char* timerText = TextFormat("%d", timer);

    int fontSize = 50;
    int textWidth = MeasureText(timerText, fontSize);

    DrawText(
        timerText,
        GetScreenWidth()/2 - textWidth/2,
        20,
        fontSize,
        BLACK
    );
}

void Game::HandleInput()
{
    if(run)
    {
        if(IsKeyDown(KEY_LEFT))
        {
            player.MoveLeft();
        }
        else if (IsKeyDown(KEY_RIGHT))
        {
            player.MoveRight();
        }
    }
    else
        {
            if(IsKeyPressed(KEY_SPACE))
            {
                Reset();
            }
        }
}

void Game::CheckForHighscore()
{
    if(score >highscore)
    {
        highscore = score;
        SaveHighscoreToFile(highscore);
    }
}

void Game::SaveHighscoreToFile(int highscore)
{
    std::ofstream highscoreFile("highscore.txt");

    if(highscoreFile.is_open())
    {
        highscoreFile <<highscore;
        highscoreFile.close();
    }
}

int Game::LoadHighscoreFromFile()
{
    int loadedHighscore = 0;
    std::ifstream highscoreFile("highscore.txt");

    if(highscoreFile.is_open())
    {
        highscoreFile >> loadedHighscore;
        highscoreFile.close();
    }
    
    return loadedHighscore;
}

void Game::Reset()
{
    score = 0;
    timeLeft = 45.0f;
    run = true;

    apple.Reset();

    PlayMusicStream(music);

}


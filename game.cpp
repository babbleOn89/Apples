#include "game.hpp"
#include <iostream>
#include <fstream>
#include <raylib.h>

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

    characterChosen = false;
    selectedCharacter = 1;

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
    if(characterChosen == false)
    {
        if(IsKeyPressed(KEY_LEFT))
        {
            selectedCharacter = 1;
        }
        
        if(IsKeyPressed(KEY_RIGHT))
        {
            selectedCharacter = 2;
        }
        
        if(IsKeyPressed(KEY_ENTER))
        {
            characterChosen = true;

            if(selectedCharacter == 1)
            {
                player.SetPlayer(Girl_Player);
            }
            else if(selectedCharacter == 2)
            {
                player.SetPlayer(Boy_Player);
            }
        }
        return;
    }

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
            score += apple.value;
            if(score < 0)
            {
                score = 0;
            }

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
    if(characterChosen == false)
    {
        ClearBackground(SKYBLUE);

        DrawText("CHOOSE YOUR CHARACTER", 300, 80, 50, BROWN);

        if(selectedCharacter == 1)
        {
            DrawCircle(350, 500, 100, Fade(YELLOW, 0.35f));
        }
        else if(selectedCharacter == 2)
        {
            DrawCircle(950, 500, 100, Fade(YELLOW, 0.35f));
        }
        // Temporary preview placeholders
        DrawText("GIRL", 300, 500, 40, BLACK);
        DrawText("BOY", 920, 500, 40, BLACK);

        DrawText("LEFT / RIGHT to choose", 440, 620, 30, BLACK);
        DrawText("ENTER to confirm", 500, 670, 30, BLACK);

        return;
    }
    DrawWorld();
    DrawWorldUI();

    if(!run)
    {
        DrawGameOver();
    }

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
}

void Game::DrawWorld()
{
    DrawRectangle(0, 640, 1400, 160, GREEN);
    for(auto& tree : trees)
    {
        tree.Draw();
    }

    apple.Draw();
    player.Draw();

}

void Game::DrawWorldUI()
{
    int timer = (int)timeLeft;
    const char* timerText = TextFormat("%d", timer);

    int timerFontSize = 50;
    int timerTextWidth = MeasureText(timerText, timerFontSize);

    DrawText(
        timerText,
        GetScreenWidth()/2 - timerTextWidth/2,
        20,
        timerFontSize,
        BLACK
    );

    DrawText(
        TextFormat("SCORE: %d", score),
        50,
        740,
        34,
        BROWN
    );

    const char* highScoreText = TextFormat("HIGH SCORE: %d", highscore);
    int highScoreFontSize = 34;
    int highScoreTextWidth = MeasureText(highScoreText, highScoreFontSize);

    DrawText(
        highScoreText,
        GetScreenWidth() - highScoreTextWidth - 50,
        740,
        highScoreFontSize,
        BROWN
    );
}

void Game::DrawGameOver()
{
    const char* gameOverText = "GAME OVER";
    int gameOverFontSize = 60;
    int gameOverTextWidth = MeasureText(gameOverText, gameOverFontSize);

    DrawText(
        gameOverText,
        GetScreenWidth()/2 - gameOverTextWidth/2,
        GetScreenHeight()/2 - 60,
        gameOverFontSize,
        RED
    );

    const char* restartText = "Press SPACE to restart";
    int restartFontSize = 30;
    int restartTextWidth = MeasureText(restartText, restartFontSize);

    DrawText(
        restartText,
        GetScreenWidth()/2 - restartTextWidth/2,
        GetScreenHeight()/2 +20,
        restartFontSize,
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


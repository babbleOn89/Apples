#pragma once
#include <vector>
#include "player.hpp"
#include "tree.hpp"
#include "apple.hpp"

class Game
{
public:
    Game();
    ~Game();
    void Update();
    void Draw();
    void HandleInput();
    void Reset();
    bool run;
    int score;
    int highscore;
    int selectedCharacter;
    float timeLeft;
    bool characterChosen;
    Music music;
private:
    Player player;
    Apple apple;
    std::vector<Tree> trees;
    void CheckForHighscore();
    void SaveHighscoreToFile(int highscore);
    int LoadHighscoreFromFile();
    void CreateTrees();
    void DrawWorld();
    void DrawWorldUI();
    void DrawGameOver();
    Sound fallingSound;
    Sound gameOverSound;
};

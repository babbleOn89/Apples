#pragma once
#include <raylib.h>

class Player
{
    public:
    Player();
    ~Player();
    void Draw();
    void MoveLeft();
    void MoveRight();
    float scale;
    Rectangle GetBasketRect();

    private:
    Texture2D girlLeft;
    Texture2D girlRight;
    bool facingRight;
    Texture2D currentImage;
    Vector2 position;
    int speed;
};
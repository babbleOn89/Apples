#pragma once
#include <raylib.h>
#include "draw.hpp"

class Player : public Drawable
{
    public:
    Player();
    ~Player();
    void Draw() override;
    void MoveLeft();
    void MoveRight();
    Rectangle GetBasketRect();

    private:
    Texture2D girlLeft;
    Texture2D girlRight;
    bool facingRight;
    Texture2D currentImage;
    Vector2 position;
    float scale;
    float speed;
};
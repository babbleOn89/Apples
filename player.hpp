#pragma once
#include <raylib.h>
#include "draw.hpp"

enum PlayerType
{
    Girl_Player,
    Boy_Player
};

class Player : public Drawable
{
    public:
    Player();
    ~Player();
    PlayerType type;
    void Draw() override;
    void MoveLeft();
    void MoveRight();
    void SetPlayer(PlayerType newType);
    Rectangle GetBasketRect();

    private:
    Texture2D girlLeft;
    Texture2D girlRight;
    
    Texture2D boyLeft;
    Texture2D boyRight;

    bool facingRight;
    Texture2D currentImage;
    Vector2 position;
    float scale;
    float speed;
};

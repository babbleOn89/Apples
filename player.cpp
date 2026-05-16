#include "player.hpp"

Player::Player()
{
    girlLeft = LoadTexture("Graphics/girlL.png");
    girlRight = LoadTexture("Graphics/girlR.png");
    currentImage = girlRight;
    facingRight = true;
    scale = 0.35f;
    position.x = (GetScreenWidth() - currentImage.width * scale)/2;
    position.y = GetScreenHeight() - currentImage.height * scale - 50;

    speed = 10.0f;
}

Player::~Player()
{
    UnloadTexture(girlLeft);
    UnloadTexture(girlRight);
}

void Player::Draw()
{
    DrawTextureEx(currentImage, position, 0.0f, scale, WHITE);
}

void Player::MoveLeft()
{
    currentImage = girlLeft;
    position.x -= speed;
    if(position.x < -150)
    {
        position.x = -150;
    }
    facingRight = false;
}

void Player::MoveRight()
{
    currentImage = girlRight;
    position.x += speed;
    if(position.x > GetScreenWidth() - currentImage.width * scale + 225)
    {
        position.x = GetScreenWidth() - currentImage.width * scale + 225;
    }
    facingRight = true;
}

Rectangle Player::GetBasketRect()
{
    if(facingRight)
    {
        return
        {
            position.x + 175,
            position.y + 85,
            120,
            55
        };
    }
    else
    {
        return
        {
            position.x + 165,
            position.y + 90,
            120,
            55
        };
    }
}

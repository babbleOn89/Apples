#include "apple.hpp"

Apple::Apple()
{
    image = LoadTexture("Graphics/apple.png");
    position = {700, 120};
    speed = 6.0f;
    scale = 0.0165f;
    spawnDelay = 30;
    falling = false;

    active = true;
}

Apple::~Apple()
{
    UnloadTexture(image);
}

void Apple::Update()
{
    if(!falling)
    {
        spawnDelay--;

        if(spawnDelay <= 0)
        {
            falling = true;
        }
        return;
    }
    position.y += speed;
    
    if(position.y > GetScreenHeight() - 150)
    {
        Reset();
    }
}

void Apple::Draw()
{
    if(active)
    {
        DrawTextureEx(image, position, 0.0f, scale, WHITE);
    }
}

Rectangle Apple::getRect()
{
    return {
        position.x,
        position.y,
        image.width * scale,
        image.height * scale
    };
}

void Apple::Reset()
{
    position.x = GetRandomValue(
        0,
        GetScreenWidth() - image.width * scale
    );
    position.y = 120;

    spawnDelay = 60;
    falling = false;
}
#include "apple.hpp"

Apple::Apple()
{
    redTexture = LoadTexture("Graphics/apple.png");
    greenTexture = LoadTexture("Graphics/gapple.png");
    rottenTexture = LoadTexture("Graphics/rapple.png");
    
    position = {700, 120};
    speed = 6.0f;
    scale = 0.0165f;
    greenScale = 0.08f; //green
    rottenScale = 0.08f; //rotten
    spawnDelay = 30;
    falling = false;

    active = true;

    type = APPLE_RED;
    value = 1;
}

Apple::~Apple()
{
    UnloadTexture(redTexture);
    UnloadTexture(greenTexture);
    UnloadTexture(rottenTexture);
    position = {300, 0};
}

void Apple::Reset()
{
    position.x = GetRandomValue(100, 1200);
    position.y = 120;

    spawnDelay= 60;
    falling = false;

    int randomType = GetRandomValue(0 , 9);

    if(randomType == 0)
    {
        type= APPLE_ROTTEN;
        value = -1;
    }
    else if(randomType <= 2)
    {
        type = APPLE_GREEN;
        value = 2;
    }
    else
    {
        type = APPLE_RED;
        value = 1;
    }
}

    

void Apple::Draw()
{
    if(active)
    {
        if(type == APPLE_RED)
	    {
            DrawTextureEx(redTexture, position, 0.0f, scale, WHITE);
        }
        else if(type == APPLE_GREEN)
        {
            DrawTextureEx(greenTexture, position, 0.0f, greenScale, WHITE);
        }
        else if(type == APPLE_ROTTEN)
        {
            DrawTextureEx(rottenTexture, position, 0.0f, rottenScale, WHITE);
        }
    }
}

Rectangle Apple::getRect()
{
    Texture2D currentTexture;
    float currentScale;

    if(type == APPLE_RED)
    {
        currentTexture = redTexture;
        currentScale = scale;
    }
    else if(type == APPLE_GREEN)
    {
        currentTexture = greenTexture;
        currentScale = greenScale;
    }
    else
    {
        currentTexture = rottenTexture;
        currentScale = rottenScale;
    }

    return
    {
        position.x,
        position.y,
        currentTexture.width * scale,
        currentTexture.height * scale
    };
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

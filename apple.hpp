#pragma once
#include <raylib.h>
#include "draw.hpp"

enum AppleType
{
    APPLE_RED,
    APPLE_GREEN,
    APPLE_ROTTEN	
};

class Apple : public Drawable
{
public:
    Apple();
    ~Apple();
    void Update();
    void Draw() override;
    void Reset();
    Rectangle getRect();
    bool active;
    int value;
    
private:
    Texture2D redTexture;
    Texture2D greenTexture;
    Texture2D rottenTexture;
    AppleType type;
    Vector2 position;
    float speed;
    float scale;
    float rottenScale;
    float greenScale;
    float spawnDelay;
    bool falling;
 
};

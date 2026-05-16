#pragma once
#include <raylib.h>

class Apple
{
public:
    Apple();
    ~Apple();
    void Update();
    void Draw();
    void Reset();
    Rectangle getRect();
    bool active;
    
private:
    Texture2D image;
    Vector2 position;
    float speed;
    float scale;
    float spawnDelay;
    bool falling;
 
};
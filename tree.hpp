#pragma once
#include <raylib.h>

class Tree
{
    public:
        Tree(Vector2 position);
        ~Tree();
        void Draw();

    private:
        Texture2D image;
        Vector2 position;
};
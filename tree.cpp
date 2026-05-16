#include "tree.hpp"

Tree::Tree(Vector2 position)
{
    this -> position = position;
    image = LoadTexture("Graphics/tree.png");
}

void Tree::Draw()
{
    DrawTextureEx(image, position, 0.0, 1.5f, WHITE);
}

Tree::~Tree()
{
    
}

#include "main.hpp"
#define MAX_ENEMIES 10

class Enemy{
    typedef struct Goomba {
        Vector2 randPlace = {(float)GetRandomValue(100, 10000), (float)GetRandomValue(100, 10000)};
        Vector2 zoom = {0, 0};
        Texture2D texture = LoadTexture("res/badguy.png");
        bool active = true;
    } Goomba;
    Goomba Enemy[MAX_ENEMIES]; // Sets up default values
    public:
        void goombaCollision();
        //Texture2D spacegoomba = LoadTexture("res/badguy.png");
};
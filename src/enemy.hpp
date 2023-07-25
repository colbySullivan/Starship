#include "main.hpp"
#define MAX_ENEMIES 40

class Enemy{
    typedef struct Goomba {
        float randX = GetRandomValue(100, 10000);
        float randY = GetRandomValue(100, 10000);
        Texture2D texture = LoadTexture("res/badguy.png");
        bool active = true;
    } Goomba;
    Goomba Enemy[MAX_ENEMIES]; // Sets up default values
    public:
        void goombaCollision(Vector2);
        //Texture2D spacegoomba = LoadTexture("res/badguy.png");
    private:
        int distance;
};
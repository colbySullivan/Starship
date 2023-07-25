#include "main.hpp"
#define MAX_ENEMIES 40

class Enemy{
    typedef struct Goomba {
        float randX = GetRandomValue(100, 10000);
        float randY = GetRandomValue(100, 10000);
        Texture2D texture;
        bool active = true;
    } Goomba;
    Goomba Enemy[MAX_ENEMIES]; // Sets up default values
    public:
        int goombaCollision(Vector2);
        void initGoombas();
    private:
        Texture2D spacegoomba = LoadTexture("res/badguy.png");
        int distance;
        int goombasDown = 0;
};
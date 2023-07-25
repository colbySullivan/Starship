#include "main.hpp"
#define MAX_ENEMIES 10

class Enemy{
    typedef struct Goomba {
        Vector2 xy = {0, 0};;
        Vector2 zoom = {0, 0};;
        float radius = 5;
        int lifeSpawn = 0;
        bool active = false;
        Color color = WHITE;
    } Goomba;
    Goomba Enemy[MAX_ENEMIES]; // Sets up default values
    public:
        void drawGoomba();
};
#include "main.hpp"
#define MAX_BULLETS 10

class Bullet{
    typedef struct Shoot {
        Vector2 xy = {0, 0};;
        Vector2 zoom = {0, 0};;
        float radius = 5;
        int lifeSpawn = 0;
        bool active = false;
        Color color = WHITE;
    } Shoot;
    Shoot shoot[MAX_BULLETS]; // Sets up default values
public:
    Texture2D trajectile;
    void fire(Vector2 position);
    void speed(float &);
private:
};
#include "main.hpp"
#include "enemy.hpp"

#define MAX_BULLETS 20

class Bullet {
    // Represents a single bullet shot by the player.
    typedef struct Shoot {
        Vector2 xy = { 0, 0 };    // Position of the bullet.
        Vector2 zoom = { 0, 0 };  // Velocity of the bullet in the x and y directions.
        float radius = 5;         // Radius of the bullet (used for collision checks).
        int lifeSpawn = 0;        // Current lifetime of the bullet (used for despawning).
        bool active = false;      // Flag to indicate if the bullet is active or not.
        Color color = WHITE;      // Color of the bullet.
    } Shoot;
    Shoot shoot[MAX_BULLETS];   // Array to store multiple bullets.

public:
    Texture2D trajectile;       // Texture representing the bullet's appearance.
    void fire(Vector2&, float, float, Texture2D);
    void speed(float& playerspeed);
private:
    Enemy goomba;           // Instance of the Enemy class to handle enemy interactions.
    int bulletsShot = 0;    // The number of bullets currently active and flying in the scene.
    int goombasDown = 0;    // The number of enemies defeated by the bullets.
};

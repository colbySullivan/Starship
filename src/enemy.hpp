#include "main.hpp"

#define MAX_ENEMIES 40

// This class is responsible for managing enemies and their behavior.

class Enemy {
    // Represents a single enemy (Goomba) in the game.
    typedef struct Goomba {
        float randX = GetRandomValue(100, 10000); // Random initial X position for the enemy.
        float randY = GetRandomValue(100, 10000); // Random initial Y position for the enemy.
        Texture2D texture; // Texture of the enemy.
        bool active = true; // Flag to indicate if the enemy is active (visible) or not.
    } Goomba;

    Goomba Enemy[MAX_ENEMIES]; // Array to store multiple enemies (Goombas).

public:
    int goombaCollision(Vector2, Texture2D);
    void initGoombas(Texture2D);

private:
    int distance; // Distance between the bullet and the enemy.
    int goombasDown = 0; // The number of defeated goombas.
};

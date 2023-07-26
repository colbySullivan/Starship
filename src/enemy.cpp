#include "enemy.hpp"

/*
  Description: Checks for collision between bullets and goombas and updates their status accordingly.
  Parameters:
  - bulletPos: The position of the bullet to check for collisions.
Return:
  - The number of defeated goombas.
 */
int Enemy::goombaCollision(Vector2 bulletPos) {
    // Initialize goombas if not already done.
    this->initGoombas();

    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (Enemy[i].active) {
            // Draw the active goombas on the screen.
            DrawTextureEx(Enemy[i].texture, {Enemy[i].randX, Enemy[i].randY}, 0.0f, 5.0f, WHITE);

            // Calculate the distance between the bullet and the current goomba.
            distance = sqrt(pow(bulletPos.x - Enemy[i].randX, 2) + pow(bulletPos.y - Enemy[i].randY, 2));

            // Check for collision between the bullet and the goomba.
            if (distance < 250) { // TODO: Collision detection might need further refinement.
                // If there is a collision, deactivate the goomba and update its position.
                Enemy[i].active = false;
                Enemy[i].randX = 0;
                Enemy[i].randY = 0;
                goombasDown++; // Increment the count of defeated goombas.
            }
        }
    }
    return goombasDown; // Return the total number of defeated goombas.
}

/*
  Description: Initializes the goombas and their textures.
 */
void Enemy::initGoombas() {
    for (int i = 0; i < MAX_ENEMIES; i++) { 
        Enemy[i].texture = spacegoomba; // Assign the texture to each goomba.
        //Enemy[i].active = true; // TODO: Reset goombas if needed.
    }
}

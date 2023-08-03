#include "bullet.hpp"

/*
  Description: Fires a bullet from the player's position with a given acceleration.
  Parameters:
  - position: The initial position of the player.
  - accelerationUp: The acceleration of the bullet in the upward direction.
  - accelerationRight: The acceleration of the bullet in the right direction.
 */
void Bullet::fire(Vector2& position, float accelerationUp, float accelerationRight, Texture2D spacegoomba) {
    // Player shoot logic
    if (IsKeyPressed(KEY_Q)) { // TODO: Allow shooting from a stopped state
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!shoot[i].active) {
                // Set the bullet's initial position and activate it
                this->shoot[i].xy = { position.x + 30, position.y + 30 };
                this->shoot[i].active = true;
                // Set the bullet's velocity based on the provided accelerations
                this->shoot[i].zoom.x = 2 * accelerationRight;
                this->shoot[i].zoom.y = 2 * accelerationUp;
                bulletsShot++; // Increment the count of active bullets
                break;
            }
        }
    }

    // Shoot life timer
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (shoot[i].active) shoot[i].lifeSpawn++;
    }

    // Shot logic
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (shoot[i].active) {
            // Move the bullet based on its velocity
            this->shoot[i].xy.x += shoot[i].zoom.x;
            this->shoot[i].xy.y -= shoot[i].zoom.y;

            // Collision logic: Bullet vs walls
            if (shoot[i].xy.x > 22500 || shoot[i].xy.x < 500 ||
                shoot[i].xy.y > 10500 || shoot[i].xy.y < 500) {
                // Deactivate the bullet if it hits the boundary walls
                shoot[i].active = false;
                shoot[i].lifeSpawn = 0;
                bulletsShot--; // Decrement the count of active bullets
            }

            // Despawn shot
            if (shoot[i].lifeSpawn >= 3000) { // Bullet timer - Deactivate the bullet after a certain time
                this->shoot[i].xy = { 0, 0 };
                this->shoot[i].zoom = { 0, 0 };
                this->shoot[i].lifeSpawn = 0;
                this->shoot[i].active = false;
                bulletsShot--; // Decrement the count of active bullets
            }
        }
    }

    for (int i = 0; i < MAX_BULLETS; i++) {
        if (shoot[i].active)
            DrawCircleV(shoot[i].xy, 5, shoot[i].color);

        // Enemy creation logic - Check for collisions with the created bullets
        goombasDown = goomba.goombaCollision(shoot[i].xy, spacegoomba);
    }

    // Draw the number of bullets remaining and the number of remaining enemies
    DrawText(TextFormat("Bullets reloaded: %2d", MAX_BULLETS - bulletsShot), position.x - 100, position.y - 450, 42, WHITE);
    DrawText(TextFormat("Goombas left: %2d", MAX_ENEMIES - goombasDown), position.x - 100, position.y - 400, 42, WHITE);
}

/*
  Description: Adjusts the player's speed.
  Parameters:
  - playerspeed: Reference to the player's speed, which will be modified by the function.
 */
void Bullet::speed(float& playerspeed) {
    playerspeed = 1.5f; // Set the player's speed to 1.5 units
}

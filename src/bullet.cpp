#include "bullet.hpp"

void Bullet::fire(Vector2 position, float accelerationUp, float accelerationRight){
    // Player shoot logic
    if (IsKeyPressed(KEY_SPACE)){
        for (int i = 0; i < MAX_BULLETS; i++){
            if (!shoot[i].active){
                this->shoot[i].xy = { position.x + 30 , position.y + 30}; 
                this->shoot[i].active = true;
                this->shoot[i].zoom.x = 2 * accelerationRight;
                this->shoot[i].zoom.y = 2 * accelerationUp;//
                break;
            }
        }
    }
    
    // Shoot life timer
    for (int i = 0; i < MAX_BULLETS; i++){
        if (shoot[i].active) shoot[i].lifeSpawn++;
    }

    // Shot logic
    for (int i = 0; i < MAX_BULLETS; i++){
        if (shoot[i].active){
            // Movement
            this->shoot[i].xy.x += shoot[i].zoom.x;
            this->shoot[i].xy.y -= shoot[i].zoom.y;

            // Collision logic: shoot vs walls
            if  (shoot[i].xy.x > 22500){
                shoot[i].active = false;
                shoot[i].lifeSpawn = 0;
            }
            else if (shoot[i].xy.x < 500){
                shoot[i].active = false;
                shoot[i].lifeSpawn = 0;
            }
            if (shoot[i].xy.y > 10500){
                shoot[i].active = false;
                shoot[i].lifeSpawn = 0;
            }
            else if (shoot[i].xy.y < 500){
                shoot[i].active = false;
                shoot[i].lifeSpawn = 0;
            }

            //Despawn shot
            // if (shoot[i].lifeSpawn >= 60){ //TODO if used make life longer
            //     this->shoot[i].zoom = (Vector2){0, 0};
            //     this->shoot[i].zoom = (Vector2){0, 0};
            //     this->shoot[i].lifeSpawn = 0;
            //     this->shoot[i].active = false;
            // }
        }
    }
    for (int i = 0; i < MAX_BULLETS; i++){
        if (shoot[i].active) DrawCircleV(shoot[i].xy, 5, shoot[i].color);
    }
}

void Bullet::speed(float &playerspeed){
    playerspeed = 1.5f;
}
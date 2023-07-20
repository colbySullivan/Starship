#include "bullet.hpp"

void Bullet::fire(Vector2 position){
    // Player shoot logic
    if (IsKeyPressed(KEY_SPACE)){
        for (int i = 0; i < MAX_BULLETS; i++){
            if (!shoot[i].active){
                this->shoot[i].xy = (Vector2){ position.x , position.y }; 
                this->shoot[i].active = true;
                this->shoot[i].zoom.x = 1.5;
                this->shoot[i].zoom.y = 1.5;
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
            // if  (shoot[i].position.x > GetScreenWidth() + shoot[i].radius){
            //     shoot[i].active = false;
            //     shoot[i].lifeSpawn = 0;
            // }
            // else if (shoot[i].position.x < 0 - shoot[i].radius){
            //     shoot[i].active = false;
            //     shoot[i].lifeSpawn = 0;
            // }
            // if (shoot[i].position.y > GetScreenHeight() + shoot[i].radius){
            //     shoot[i].active = false;
            //     shoot[i].lifeSpawn = 0;
            // }
            // else if (shoot[i].position.y < 0 - shoot[i].radius){
            //     shoot[i].active = false;
            //     shoot[i].lifeSpawn = 0;
            // }

            // Life of shoot
            // if (shoot[i].lifeSpawn >= 60){
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
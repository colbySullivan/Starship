#include "enemy.hpp"

int Enemy::goombaCollision(Vector2 bulletPos){
    this->initGoombas();
    for (int i = 0; i < MAX_ENEMIES; i++){
        if (Enemy[i].active){
            DrawTextureEx(Enemy[i].texture, {Enemy[i].randX, Enemy[i].randY}, 0.0f, 5.0f, WHITE); 
            distance = sqrt(pow(bulletPos.x - Enemy[i].randX, 2) + pow(bulletPos.y - Enemy[i].randY, 2));
            if(distance < 300){
                Enemy[i].active = false;
                Enemy[i].randX = 0;
                Enemy[i].randY = 0;
                goombasDown++;
            }
        }
    }
    return goombasDown;
}

void Enemy::initGoombas(){
    for (int i = 0; i < MAX_ENEMIES; i++){ 
        Enemy[i].texture = spacegoomba;
    }
}
#include "enemy.hpp"

void Enemy::goombaCollision(Vector2 userPos){
    for (int i = 0; i < MAX_ENEMIES; i++){
        if (Enemy[i].active)
            DrawTextureEx(Enemy[i].texture, {Enemy[i].randX, Enemy[i].randY}, 0.0f, 10.0f, WHITE); 

        distance = sqrt(pow(userPos.x - Enemy[i].randX, 2) + pow(userPos.y - Enemy[i].randY, 2));
        if(distance < 300){
            Enemy[i].active = false;
            Enemy[i].randX = 0;
            Enemy[i].randY = 0;
        }
    }
}

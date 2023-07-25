#include "enemy.hpp"

void Enemy::goombaCollision(){
    for (int i = 0; i < MAX_ENEMIES; i++){
        if (Enemy[i].active)
            DrawTextureEx(Enemy[i].texture, Enemy[i].randPlace, 0.0f, 10.0f, WHITE); 
    }
}

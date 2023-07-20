#include "bullet.hpp"

void Bullet::shoot(Vector2 &position){
    //trajectile = LoadTexture("res/badguy.png");
    float movX = position.x;
    float deltaTime = GetFrameTime();
    movX += 300.0f * deltaTime;
    DrawTexture(trajectile, movX, position.y, WHITE);

}

void Bullet::speed(float &playerspeed){
    playerspeed = 1.5f;
}
#include "main.hpp"
#include "bullet.hpp"

class Movement{
    public:
        void manageRotation(uint16_t &, uint8_t);
        uint8_t manageMovement(Vector2 &, float &, float &, Texture2D &);
        void checkWallCollision(Vector2 &);
    private:
        Bullet ship;
        float accelerationUp;
        float accelerationRight;
};
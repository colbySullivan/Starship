#include "main.hpp"
#include "bullet.hpp"

class PlayerRotation{
    public:
        void manageRotation( uint16_t &rotation, uint8_t rotationFlags );
        uint8_t manageMovement( Vector2 &position, float &playerSpeed, float &deltaTime, Texture2D player );
    private:
        Bullet ship;
};
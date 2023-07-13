#include "main.hpp"

class PlayerRotation{
    public:
        void manageRotation( uint16_t &rotation, uint8_t rotationFlags );
        uint8_t manageMovement( Vector2 &position, const float &playerSpeed, float &deltaTime, Texture2D player );
};
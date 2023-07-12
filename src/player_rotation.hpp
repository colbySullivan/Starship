#include "main.hpp"

class PlayerRotation{
    public:
        enum PlayerDirectionEnum{  
            RIGHT = 0b00010000,
            LEFT = 0b00100000,
            UP = 0b01000000,
            DOWN = 0b10000000,
            UP_RIGHT = UP | RIGHT,
            DOWN_RIGHT = DOWN | RIGHT,
            UP_LEFT = UP | LEFT,
            DOWN_LEFT = DOWN | LEFT
        };

        void manageRotation( uint16_t &rotation, uint8_t rotationFlags );
        uint8_t manageMovement( Vector2 &position, const float &playerSpeed, float &deltaTime, Texture2D player );
};
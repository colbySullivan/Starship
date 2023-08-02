#include "main.hpp"
#include "bullet.hpp"

// This class handles player movement and rotation.

class Movement{
    public:
        void manageRotation(uint16_t &, uint8_t);
        uint8_t manageMovement(Vector2 &, float &, float &, Texture2D &, Texture2D);
        void checkWallCollision(Vector2 &);
    private:
        Bullet ship;                 // Instance of the Bullet class for player shooting.
        float accelerationUp;        // Acceleration value for player's upward movement.
        float accelerationRight;     // Acceleration value for player's rightward movement.
        Texture2D TextureBuffer = LoadTexture("res/player.png");
};
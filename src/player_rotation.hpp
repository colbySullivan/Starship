#include "main.hpp"
#include "bullet.hpp"

class PlayerRotation{
    public:
        void manageRotation(uint16_t &, uint8_t);
        uint8_t manageMovement(Vector2 &, float &, float &, Texture2D &);
    private:
        Bullet ship;
};
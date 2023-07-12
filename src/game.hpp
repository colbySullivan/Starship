#include "main.hpp"

class Game{
    public:
        void CreateWindow();
        void Gameloop();
        void TitleScreen();
        void DrawObject();
        void drawPlayer ( Texture2D &Texture, Vector2 &position, uint16_t rotation );
        void RunGame();
    private:
		Texture2D mushroom;
        Texture2D player;
        Image icon;
        int PosX;
        int PosY;
        int Health;

        uint16_t playerRotation = 0;
        bool GameStarted;
};
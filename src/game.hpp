#include "main.hpp"

class Game{
    public:
        void CreateWindow();
        void Gameloop();
        void TitleScreen();
        void DrawObject();
        void drawPlayer ( Texture2D &Texture, Vector2 &position, uint16_t rotation );
        void RunGame();
        void UpdateCameraCenter(Camera2D *camera, Vector2 position);
    private:
		Texture2D spacegoomba;
        Texture2D user;
        Texture2D background;
        Texture2D speedster;
        Vector2 midscreen;
        Camera2D camera;
        Image icon;
        float PosX;
        float PosY;
        float rotategoomba;
        int Health;

        uint16_t playerRotation = 0;
        bool GameStarted;
};
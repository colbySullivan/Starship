#include "main.hpp"

class Game{
    public:
        void CreateWindow();
        void Gameloop();
        void TitleScreen();
        void DrawObject();
        void drawPlayer (Texture2D &, Vector2 &, uint16_t);
        void RunGame();
        void UpdateCameraCenter(Camera2D *, Vector2);
        void EndScreen();
    private:
        int MAX_BADGUYS;
		Texture2D spacegoomba;
        Texture2D user;
        Texture2D background;
        Texture2D speedster;
        Vector2 midscreen;
        Vector2 position;
        Camera2D camera;
        bool gamestart = false;
        int startTime;
        Image icon;
        float PosX;
        float PosY;
        float rotategoomba;
        int Health;

        uint16_t playerRotation = 0;
        bool GameStarted;
};
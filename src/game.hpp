// This class represents the main game logic and functionality.

#include "main.hpp"

class Game {
public:
    void CreateWindow();
    void Gameloop();
    void TitleScreen(Vector2&);
    void DrawObject();
    void drawPlayer(Texture2D& , Vector2& , uint16_t);
    void RunGame();
    void UpdateCameraCenter(Camera2D* , Vector2);
    void EndScreen();
    void embedResources();
    void createHeaders();

private:
    int GAME_TIME;           // The total game time in seconds.
    Texture2D spacegoomba;   // Texture for the enemy (goomba).
    Texture2D user;          // Texture for the player.
    Texture2D back;    // Texture for the game background.
    Texture2D speedster;     // Texture for the player's speedster.
    Vector2 midscreen;       // The position of the center of the screen.
    Vector2 position;        // The current position of the player.
    Camera2D camera;         // The camera to handle the view of the game.
    bool gamestart = false;  // Flag to indicate if the game has started.
    int startTime;           // The starting time of the game.
    Image iconLogo;              // Image for the window icon.
    float PosX;              // X position of the enemy (goomba).
    float PosY;              // Y position of the enemy (goomba).
    float rotategoomba;      // Rotation angle for the enemy (goomba).
    int Health;              // The player's health.

    uint16_t playerRotation = 0; // Rotation angle for the player.
    bool GameStarted;            // Flag to indicate if the game has started.
};

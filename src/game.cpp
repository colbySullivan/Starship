#include "game.hpp"
#include "main.hpp"
#include "movement.hpp"
#include "player.h"
#include "badguy.h"
#include "background.h"
#include <iostream>

/*
  Description: Draws the game objects on the screen, such as the health and background.
 */
void Game::DrawObject() {
    DrawText(TextFormat("Health = %d", Health), position.x, position.y, 42, WHITE);
    DrawTextureEx(back, {0, 0}, 0.0f, 10.0f, WHITE);
}
/*
  Description: Draws the end game screen when the game is over.
  Allows the player to unpause the game by pressing the spacebar.
 */
void Game::EndScreen() {
    DrawText("Game-Over ...", position.x - 100, position.y - 500, 42, RED);
    DrawText("Press Space To Play Again", position.x - 500, position.y + 200, 64, RED);
    if (IsKeyPressed(KEY_SPACE)) {
        startTime = GetTime(); // Unpause game time counter
    }
}
/*
Description: Draws the title screen with the game's initial instructions.
             Allows the player to start the game by pressing the spacebar.
Parameters:
  - startXY: Reference to a Vector2 variable representing the start position of a texture to animate.
 */
void Game::TitleScreen(Vector2& startXY) {
    ClearBackground(GetColor(0x052c46ff));
    DrawText("Press Space To Play!", 50, 500, 64, WHITE);

    // Animate the "speedster" texture on the title screen.
    startXY.x += 0.1;
    if (startXY.x > 900)
        startXY.x = 0;
    DrawTextureEx(speedster, startXY, 0.1f, 5.0f, WHITE);

    if (IsKeyPressed(KEY_SPACE)) {
        gamestart = true;
        startTime = GetTime(); // Start the game by setting the start time.
    }
}
/*
  Description: Main game loop that handles gameplay and game states.
  TODO more documentation
 */
void Game::Gameloop() {
    // Game settings
    GAME_TIME = 20;
    Movement move;
    position = {2500, 2500}; // Initial player position
    playerRotation = 0; // Initial player rotation
    float playerSpeed = 2.0f; // Player movement speed
    Health = 0; // Player health
    PosX = GetRandomValue(500, 22500 - spacegoomba.width); // Random initial X position for the enemy.
    PosY = GetRandomValue(400, 10500 - spacegoomba.height); // Random initial Y position for the enemy.

    // Initialize camera
    camera = {0};
    camera.target = position;
    midscreen = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.offset = midscreen;
    camera.rotation = 0.0f;
    camera.zoom = 0.75f;
    int cameraOption = 0; // Default center

    // Vector2 startXY;
    Vector2 startXY = {0, 0};

    while (!WindowShouldClose()) {
        camera.zoom += ((float)GetMouseWheelMove() * 0.05f);
        if (camera.zoom > 5.0f)
            camera.zoom = 5.0f;
        else if (camera.zoom < 0.25f)
            camera.zoom = 0.25f;

        float deltaTime = GetFrameTime();

        // Move camera with the player
        UpdateCameraCenter(&camera, position);

        BeginDrawing();

        if (!gamestart) {
            TitleScreen(startXY);
        } else if (IsKeyPressed(KEY_P)) {
            gamestart = false;
        } else {
            ClearBackground(GetColor(0x052c46ff));
            BeginMode2D(camera);

            DrawObject();
            drawPlayer(user, position, playerRotation);

            float distance = 0.0f;

            int currentTime = GetTime() - startTime;
            int timeLeft = GAME_TIME - currentTime;
            if (timeLeft <= 0) {
                // TODO: Unload textures when used, there is a texture bug.
                EndScreen();
            } else {
                uint8_t playerDirection = move.manageMovement(position, playerSpeed, deltaTime, user, speedster);
                move.manageRotation(playerRotation, playerDirection);
                DrawText(TextFormat("Timer : %02ds", timeLeft), position.x - 100, position.y - 500, 42, WHITE);
                DrawText("Press Q to shoot", position.x - 750, position.y - 500, 25, WHITE);
                DrawText("Press E to boost", position.x - 750, position.y - 450, 25, WHITE);
            }

            distance = sqrt(pow(position.x - PosX, 2) + pow(position.y - PosY, 2));
            if (distance < 300) {
                Health++;

                UnloadTexture(spacegoomba);

                // Respawn the enemy with a new random position.
                PosX = GetRandomValue(100, 10000 - spacegoomba.height);
                PosY = GetRandomValue(100, 10000 - spacegoomba.height);

                spacegoomba = LoadTexture("res/badguy.png");
            }
        }

        EndMode2D();
        EndDrawing();
    }
}
/*
  Description: Initializes the game window and resources, runs the main game loop, and unloads resources.
 */
void Game::CreateWindow() {
    SetTraceLogLevel(LOG_NONE);
    InitWindow(1200, 800, "Starship");
    //ToggleFullscreen();
    HideCursor();

    // Set the window icon
    icon = LoadImage("res/icon.png");
    SetWindowIcon(icon);

    // load player
	Image player = { 0 };
	player.format = PLAYER_FORMAT;
	player.height = PLAYER_HEIGHT;
	player.width = PLAYER_WIDTH;
	player.data = PLAYER_DATA;
	player.mipmaps = 1;
	user = LoadTextureFromImage(player);

    Image background = { 0 };
	background.format = BACKGROUND_FORMAT;
	background.height = BACKGROUND_HEIGHT;
	background.width = BACKGROUND_WIDTH;
	background.data = BACKGROUND_DATA;
	background.mipmaps = 1;
	back = LoadTexture("res/background.png");


    //spacegoomba = LoadTexture("res/badguy.png");
    //user = LoadTexture("res/player.png");
    //background = LoadTexture("res/background.png");
    //speedster = LoadTexture("res/speedplayer.png");

    Gameloop();

    // Unload resources
    UnloadTexture(user);
    UnloadTexture(spacegoomba);
    UnloadTexture(back);
    CloseWindow();
}

/*
  Description: Draws the player texture with the specified rotation at the given position.
  Parameters:
  - Texture: Reference to the player texture.
  - position: Reference to the player position Vector2.
  - rotation: Rotation angle of the player texture.
  */
void Game::drawPlayer(Texture2D& Texture, Vector2& position, uint16_t rotation) {
    Vector2 newPosition = position;
    switch (rotation) {
        case 0:
            break;
        case 180:
            newPosition.x += 64;
            newPosition.y += 64;
            break;
        case 270:
            newPosition.y += 64;
            break;
        case 90:
            newPosition.x += 64;
            break;
        case 45:
            newPosition.x += 32;
            break;
        case 135:
            newPosition.y += 32;
            newPosition.x += 64;
            break;
        case 315:
            newPosition.y += 32;
            break;
        case 225:
            newPosition.y += 64;
            newPosition.x += 32;
            break;
        default:
            break;
    }
    DrawTextureEx(Texture, newPosition, rotation, 1.0f, WHITE);
}
/*
  Description: Entry point for running the game.
 */
void Game::RunGame() {
    CreateWindow();
}
/*
  Description: Updates the camera center to follow the player.
  Parameters:
  - camera: Pointer to the Camera2D struct representing the camera.
  - position: The position of the player to be followed by the camera.
  */
void Game::UpdateCameraCenter(Camera2D* camera, Vector2 position) {
    camera->offset = midscreen;
    camera->target = position;
}

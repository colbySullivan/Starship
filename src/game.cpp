#include "game.hpp"
#include "main.hpp"
#include "movement.hpp"
#include <iostream>

void Game::DrawObject(){
    DrawText(TextFormat("Health = %d", Health), position.x, position.y, 42, WHITE);
    DrawTextureEx(background, {0,0}, 0.0f, 10.0f, WHITE);
    DrawTextureEx(spacegoomba, {PosX, PosY}, rotategoomba, 10.0f, WHITE);
}

void Game::TitleScreen(){
    ClearBackground(GetColor(0x052c46ff));
    DrawText("Press Space To Play!", 50, 500, 64, WHITE);
    if(IsKeyPressed(KEY_SPACE)){
        gamestart = true;
        startTime = GetTime();
    }
}

void Game::Gameloop(){
    MAX_BADGUYS = 10;
    Movement move;
    position = {2500, 2500};
    playerRotation = 0;
    float acceleration = 0.0f;
    float playerSpeed = 2.0f;
    Health = 0;
    PosX = GetRandomValue(500, 22500 - spacegoomba.width);
    PosY = GetRandomValue(400, 10500 - spacegoomba.height);

    // Initialize camera
    camera = { 0 };
    camera.target = position;
    midscreen = {GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};
    camera.offset = midscreen;
    camera.rotation = 0.0f;
    camera.zoom = 0.75f;
    int cameraOption = 0; // Default center

    while(!WindowShouldClose()){
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);
        if (camera.zoom > 5.0f) 
            camera.zoom = 5.0f;
        else if (camera.zoom < 0.25f) 
            camera.zoom = 0.25f;

        float deltaTime = GetFrameTime();
        // Move camera with user
        UpdateCameraCenter(&camera, position);

        BeginDrawing();

        if(!gamestart)
            TitleScreen();
        else{
            ClearBackground(GetColor(0x052c46ff));
            BeginMode2D(camera);

            DrawObject();
            drawPlayer(user, position, playerRotation);

            float distance = 0.0f;
            
            int currentTime = GetTime() - startTime;
            int timeLeft = 10 - currentTime;
            if (timeLeft <= 0){
                // UnloadTexture(user);
                // UnloadTexture(spacegoomba);
                // UnloadTexture(background);
                ClearBackground(BROWN);
                DrawText("Game-Over ...", position.x - 100, position.y - 500, 42, RED);
            }
            else{
                rotategoomba+=0.1f;
                uint8_t playerDirection = move.manageMovement( position, playerSpeed, deltaTime, user, speedster);
                move.manageRotation(playerRotation, playerDirection);
                DrawText(TextFormat("Timer : %02ds", timeLeft), position.x - 100, position.y - 500, 42, WHITE);
                DrawText("Press Q to shoot", position.x - 750, position.y - 500, 25, WHITE);
                DrawText("Press E to boost", position.x - 750, position.y - 450, 25, WHITE);

            }
            distance = sqrt(pow(position.x - PosX, 2) + pow(position.y - PosY, 2));
            if(distance < 300) {
                Health++;

                UnloadTexture(spacegoomba);

                PosX = GetRandomValue(100, 10000 - spacegoomba.height);
                PosY = GetRandomValue(100, 10000 - spacegoomba.height);

                spacegoomba = LoadTexture("res/badguy.png");             
            }
        }
        EndMode2D();
        EndDrawing();
    }
}

void Game::CreateWindow(){
    SetTraceLogLevel(LOG_NONE);
    
    InitWindow(1200, 800, "Starship");
    //ToggleFullscreen();
    HideCursor();

    // set the window icon
    icon = LoadImage("res/icon.png");
    SetWindowIcon(icon);

    spacegoomba = LoadTexture("res/badguy.png");
    user = LoadTexture("res/player.png");
    background = LoadTexture("res/background.png");
    speedster = LoadTexture("res/speedplayer.png");
    
    Gameloop();
    UnloadTexture(user);
    UnloadTexture(spacegoomba);
    UnloadTexture(background);
    CloseWindow();
    }

void Game::drawPlayer(Texture2D &Texture, Vector2 &position, uint16_t rotation){
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
	        };
	        DrawTextureEx( Texture, newPosition, rotation, 1.0f, WHITE);
    }

void Game::RunGame(){
    CreateWindow();
}

void Game::UpdateCameraCenter(Camera2D *camera, Vector2 position){
    camera->offset = midscreen;
    camera->target = position;
}

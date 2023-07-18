#include "game.hpp"
#include "main.hpp"
#include "player_rotation.hpp"
#include <iostream>

void Game::DrawObject(){
    DrawText(TextFormat("Health = %d", Health), 269, 28, 42, WHITE);
    DrawTexture(background, GetScreenWidth()/2, GetScreenHeight()/2, WHITE);
    DrawTexture(mushroom, PosX, PosY, WHITE);
}

/*void Game::TitleScreen(){
    ClearBackground(BLUE);
    DrawText("Press Start To Play!", 50, 500, 64, WHITE);
    if(IsKeyPressed(KEY_SPACE)){
        fmt::print("space test");
        ClearBackground(WHITE);
    }
}*/

void Game::Gameloop(){
    PlayerRotation pr;
    Vector2 position = {0, 500};
    const float playerSpeed = 300.0f;
    Health = 0;
    PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
    PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);
    int startTime = GetTime();

    // Initialize camera
    camera = { 0 };
    camera.target = position;
    camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    int cameraOption = 0; // Default center

    while(!WindowShouldClose()){
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);
        if (camera.zoom > 3.0f) 
            camera.zoom = 3.0f;
        else if (camera.zoom < 0.25f) 
            camera.zoom = 0.25f;
        
        BeginDrawing();

        float deltaTime = GetFrameTime();
        // Move camera with user
        UpdateCameraCenter(&camera, position, deltaTime, GetScreenWidth(), GetScreenHeight());

        //TitleScreen();
        background = LoadTexture("res/back.jpg"); 
        ClearBackground(GREEN);
        BeginMode2D(camera);

        DrawObject();
        drawPlayer(user, position, playerRotation);
        uint8_t playerDirection = pr.manageMovement( position, playerSpeed, deltaTime, user);
        pr.manageRotation(  playerRotation, playerDirection );

        float distance = 0.0f;
        
        int currentTime = GetTime() - startTime;
        int timeLeft = 10 - currentTime;
        if (timeLeft <= 0){
            UnloadTexture(user);
            UnloadTexture(mushroom);
            ClearBackground(WHITE);
            DrawText("Game-Over ...", 269, 75, 42, RED);
        }
        else{
            DrawText(TextFormat("Timer : %02ds", timeLeft), 269, 75, 42, WHITE);
        }
        distance = sqrt(pow(position.x - PosX, 2) + pow(position.y - PosY, 2));
        if(distance < 50) {
            Health++;

            UnloadTexture(mushroom);

            PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
            PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);

            mushroom = LoadTexture("res/badguy.png");             
        }
        EndMode2D();
        EndDrawing();
    }
}

void Game::CreateWindow(){
    SetTraceLogLevel(LOG_NONE);
    
    InitWindow(800, 600, "Galaga");
    //ToggleFullscreen();
    //HideCursor();
    
    // set the window icon
    icon = LoadImage("res/icon.png");
    SetWindowIcon(icon);

    mushroom = LoadTexture("res/badguy.png");
    user = LoadTexture("res/player.png");
    
    Gameloop();
    UnloadTexture(user);
    UnloadTexture(mushroom);
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

void Game::UpdateCameraCenter(Camera2D *camera, Vector2 position, float delta, int width, int height){
    camera->offset = (Vector2){ width/2.0f, height/2.0f };
    camera->target = position;
}

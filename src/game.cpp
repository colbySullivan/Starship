#include "game.hpp"
#include "main.hpp"
#include "player_rotation.hpp"
#include <iostream>

void Game::DrawObject(){
    DrawText(TextFormat("Health = %d", Health), 269, 28, 42, WHITE);
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
    while(!WindowShouldClose()){
        BeginDrawing();
        float deltaTime = GetFrameTime();
        
        //TitleScreen();
        ClearBackground(GREEN);
        DrawObject();
        drawPlayer(player, position, playerRotation);
        uint8_t playerDirection = pr.manageMovement( position, playerSpeed, deltaTime, player);
        pr.manageRotation(  playerRotation, playerDirection );

        float distance = 0.0f;
        
        int currentTime = GetTime() - startTime;
        int timeLeft = 10 - currentTime;
        if (timeLeft <= 0){
            UnloadTexture(player);
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
        EndDrawing();
    }
}

void Game::CreateWindow(){
    SetTraceLogLevel(LOG_NONE);
    
    InitWindow(800, 600, "Starship");
    //ToggleFullscreen();
    //HideCursor();
    
    // set the window icon
    icon = LoadImage("res/icon.png");
    SetWindowIcon(icon);

    mushroom = LoadTexture("res/badguy.png");
    player = LoadTexture("res/player.png");
    
    Gameloop();
    UnloadTexture(player);
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
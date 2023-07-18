#include "game.hpp"
#include "main.hpp"
#include "player_rotation.hpp"

enum PlayerDirectionEnum{
	RIGHT = 0b00010000,
	LEFT = 0b00100000,
	UP = 0b01000000,
	DOWN = 0b10000000,
	UP_RIGHT = UP | RIGHT,
	DOWN_RIGHT = DOWN | RIGHT,
	UP_LEFT = UP | LEFT,
	DOWN_LEFT = DOWN | LEFT
};

void PlayerRotation::manageRotation(uint16_t &rotation, uint8_t rotationFlags){
	switch (rotationFlags) {
		case PlayerDirectionEnum::RIGHT:
		      rotation = 0;
		      break;
		case PlayerDirectionEnum::LEFT:
		      rotation = 180;
		      break;
		case PlayerDirectionEnum::UP:
		      rotation = 270;
		      break;
		case PlayerDirectionEnum::DOWN:
		      rotation = 90;
		      break;
		case PlayerDirectionEnum::UP_RIGHT:
		      rotation = 315;
		      break;
		case PlayerDirectionEnum::DOWN_RIGHT:
		      rotation = 45;
		      break;
		case PlayerDirectionEnum::UP_LEFT:
		      rotation = 225;
		      break;
		case PlayerDirectionEnum::DOWN_LEFT:
		      rotation = 135;
	}
}

uint8_t PlayerRotation::manageMovement(Vector2 &position, float &playerSpeed, float &deltaTime, Texture2D player){
	uint8_t rotationFlags = 0;
	// managing player movement and save rotation flags.
	if (IsKeyDown(KEY_RIGHT)){
		if(position.x > 11000)
			position.x = 10;
		rotationFlags |= PlayerDirectionEnum::RIGHT;
		position.x += playerSpeed * deltaTime;
	}
	if (IsKeyDown(KEY_LEFT)){
		if(position.x < 10)
			position.x = 10000;
		rotationFlags |= PlayerDirectionEnum::LEFT;
		position.x -= playerSpeed * deltaTime;
	}
	if (IsKeyDown(KEY_DOWN)){
		if(position.y > 11000)
			position.y = 10;
		rotationFlags |= PlayerDirectionEnum::DOWN;
		position.y += playerSpeed * deltaTime;
	}
	if (IsKeyDown(KEY_UP)){
		if(position.y < 10)
			position.y = 11000;
		rotationFlags |= PlayerDirectionEnum::UP;
		position.y -= playerSpeed * deltaTime;
	}
	if (IsKeyDown(KEY_SPACE)){
		ship.shoot(position);
		ship.speed(playerSpeed);
	}
	if (IsKeyUp(KEY_SPACE)){
		playerSpeed = 300.0f; // reset speed after space
	}
	return rotationFlags;
}

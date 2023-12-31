#include "game.hpp"
#include "main.hpp"
#include "movement.hpp"

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

/*
  Description: Converts the player's movement flags into the corresponding rotation angle.
  Parameters:
  - rotation: Reference to the rotation angle of the player.
  - rotationFlags: Flags representing the player's movement direction.
 */
void Movement::manageRotation(uint16_t &rotation, uint8_t rotationFlags){
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

/*
  Description: Manages the player's movement based on input and returns rotation flags.
  Parameters:
  - position: Reference to the position of the player.
  - playerSpeed: Reference to the speed of the player.
  - deltaTime: The time elapsed since the last frame.
  - player: Reference to the player's texture.
  - speedster: Texture for the player's speedster.
  Returns: The rotation flags representing the player's movement direction.
 */
uint8_t Movement::manageMovement(Vector2 &position, float &playerSpeed, float &deltaTime, Texture2D &player, Texture2D speedster, Texture2D TextureBuffer, Texture2D spacegoomba){
	uint8_t rotationFlags = 0;

	// Managing player movement and return rotation flags
	if (IsKeyDown(KEY_RIGHT)){
		rotationFlags |= PlayerDirectionEnum::RIGHT;
		if (accelerationRight < 1) 
			accelerationRight += 0.04f;
	}
	if (IsKeyDown(KEY_LEFT)){
		rotationFlags |= PlayerDirectionEnum::LEFT;
		if (accelerationRight > -1)
			accelerationRight -= 0.04f;
	}
	if (IsKeyDown(KEY_DOWN)){
		rotationFlags |= PlayerDirectionEnum::DOWN;
		if (accelerationUp > -1)
			accelerationUp -= 0.04f;
	}
	if (IsKeyDown(KEY_UP)){
		rotationFlags |= PlayerDirectionEnum::UP;
		if (accelerationUp < 1) 
			accelerationUp += 0.04f;
	}
	if (IsKeyDown(KEY_E)){
		player = speedster;
		ship.speed(playerSpeed);
	}
	else{
		playerSpeed = 1.0f; // reset speed after space
		player = TextureBuffer; // TODO texture bug causes static background

		// Deceleration
		if (accelerationRight > 0) accelerationRight -= 0.001f;
		if (accelerationUp > 0) accelerationUp -= 0.001f;
		
		if (accelerationRight < 0) accelerationRight += 0.001f;
		if (accelerationUp < 0) accelerationUp += 0.001f;
	}
	// Player movement
	position.x += (playerSpeed * accelerationRight);
    position.y -= (playerSpeed * accelerationUp);
	
	ship.fire(position, accelerationUp, accelerationRight, spacegoomba); // Shooting logical call
	checkWallCollision(position);

	return rotationFlags;
}

/*
  Description: Checks if the player has collided with the game boundaries (walls) and updates the position accordingly.
  Parameters:
  - position: Reference to the position of the player.
 */
void Movement::checkWallCollision(Vector2 &position){
	if(position.x > 22500) //Right
			position.x = 500;
	if(position.x < 500) //Left
			position.x = 22500;
	if(position.y > 10500) //Down
			position.y = 500;
	if(position.y < 500) //Up
			position.y = 10500;
}

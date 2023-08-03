#include "main.hpp"
#include "game.hpp"

#include <iostream>

int main(int argc, char ** argv){

	Game game; // New game instance

	// uncomment if images are dynamically compiled / or header files don't exist
    game.createHeaders();
	
	game.RunGame(); // Game loop//
    return 0;
}

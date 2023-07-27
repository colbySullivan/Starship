#include "main.hpp"
#include "game.hpp"

#include <iostream>

int main(int argc, char ** argv){
	// Image img = LoadImage("res/player.png");
	// ExportImageAsCode(img, "player.h");
	// UnloadImage(img);

    // img = LoadImage("res/badguy.png");
    // ExportImageAsCode(img, "embededbadguy.h");
    // UnloadImage(img);

	// img = LoadImage("res/background.png");
	// ExportImageAsCode(img, "background.h");
	// UnloadImage(img);

	// img = LoadImage("res/speedplayer.png");
	// ExportImageAsCode(img, "speedplayer.h");
	// UnloadImage(img);
	
	Game game; // New game instance

	game.RunGame(); // Game loop
    return 0;
}

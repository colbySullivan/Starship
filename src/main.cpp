#include "main.hpp"
#include "game.hpp"

#include <iostream>

int main(int argc, char ** argv){
	Image img = LoadImage("res/player.png");
	ExportImageAsCode(img, "player.h");
	UnloadImage(img);

    img = LoadImage("res/badguy.png");
    ExportImageAsCode(img, "badguy.h");
    UnloadImage(img);
	
	Game game; // New game instance

	game.RunGame(); // Game loop
    return 0;
}

#include "Game.hpp"

int main()
{
	std::cout << "Jour 1 : Je veux mourir" << std::endl;

	//	Initialisation of the srand
	std::srand(static_cast<unsigned>(time(NULL)));

	// Initialisation of the Game
	Game game;

	//	Game Loop
	while (game.running() and !game.getEndGame())
	{
		//Update
		game.update();

		//Render
		game.render();
	}

	return 0;
}
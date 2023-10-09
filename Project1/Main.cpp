#include "Game.hpp"

int main()
{
	std::cout << "Jour 5 : Attaque des enemis 5 !" << std::endl;

	//	Initialisation of the randomization seed
	std::srand(static_cast<unsigned>(time(NULL)));

	// Initialisation of the Game
	Game game;

	//	Game Loop : CHAIRACANON
	while (game.running() and !game.getEndGame())
	{
		//Update
		game.update();

		//Render
		game.render();
	}

	return 0;
}
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <vector>
#include "Level.hpp"

using namespace std;

class LevelManager
{
	public :

		LevelManager();

		void initLevels(sf::Sprite spriteMenu, sf::Sprite spriteButtons, sf::Sprite spriteLevel1, sf::Image maskLevel1, sf::Sprite cloudLevel1, sf::Sprite spriteLevel2, sf::Image maskLevel2, sf::Sprite spriteGameOver);
		void renderLevel(sf::RenderTarget& window, int numLevel);

		vector<Level> levels;

};


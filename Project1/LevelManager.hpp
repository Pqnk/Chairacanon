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
		void initLevels(sf::Sprite spriteMenu, sf::Sprite spriteLevel1, sf::Sprite spriteLevel2);
		void renderLevel(sf::RenderTarget& window, int numLevel);

		vector<Level> levels;

};


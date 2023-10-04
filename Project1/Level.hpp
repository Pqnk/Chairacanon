#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#ifndef DEF_LEVEL
#define DEF_LEVEL

class Level
{
	public :

		Level();
		~Level();

		sf::Sprite getSpriteLevel();
		void setSpriteLevel(sf::Sprite s);

	protected : 

		sf::Sprite spriteLevel;
};

#endif

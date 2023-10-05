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

		//##########################
		//	Level Elements
		//##########################
		void initLevelElements();
		void updateLevelElements(sf::RenderTarget& window);

		//##########################
		//	Accessors
		//##########################
		sf::Sprite getSpriteLevel();
		sf::Image getMaskLevel();
		sf::Sprite getCloudLevel();

		//##########################
		//	Setters
		//##########################
		void setSpriteLevel(sf::Sprite s);
		void setMaskLevel(sf::Image i);
		void setCloudLevel(sf::Sprite s);

	protected : 

		sf::Sprite	spriteLevel;
		sf::Image	maskLevel;
		sf::Sprite	spriteCloudLevel;
};

#endif

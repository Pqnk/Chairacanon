#pragma once
#include "StillObject.hpp"

#ifndef DEF_LEVEL
#define DEF_LEVEL

class Level : public StillObject
{
	public :

		Level();
		~Level();

		sf::Sprite getSpriteLevel();
		void setSpriteLevel(sf::Sprite s);

	protected : 

		int numberLevel;
		sf::Sprite spriteLevel;
};

#endif


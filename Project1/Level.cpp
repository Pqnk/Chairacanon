#include "Level.hpp"

Level::Level()
{

}

Level::~Level()
{
}

sf::Sprite Level::getSpriteLevel()
{
	return spriteLevel;
}

void Level::setSpriteLevel(sf::Sprite s)
{
	spriteLevel = s;
}

sf::Image Level::getMaskLevel()
{
	return maskLevel;
}

void Level::setMaskLevel(sf::Image i)
{
	maskLevel = i;
}



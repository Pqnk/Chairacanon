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

#include "Level.hpp"

Level::Level() : numberLevel(0)
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

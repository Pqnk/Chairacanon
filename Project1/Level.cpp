#include "Level.hpp"

Level::Level()
{

}

Level::~Level()
{
}


//#######################################################################################################
//	Level Elements
//#######################################################################################################
void Level::initLevelElements()
{
	spriteCloudLevel.setPosition(0.f, 0.f);
}

void Level::updateLevelElements(sf::RenderTarget& window)
{
	spriteCloudLevel.move(1.f, 1.f);

	if (spriteCloudLevel.getPosition().y > window.getSize().y)
	{
		spriteCloudLevel.setPosition(-spriteCloudLevel.getGlobalBounds().left, -spriteCloudLevel.getGlobalBounds().top);
	}
}

//#######################################################################################################
//	Accessors
//#######################################################################################################
sf::Sprite Level::getSpriteLevel()
{
	return spriteLevel;
}

sf::Image Level::getMaskLevel()
{
	return maskLevel;
}

sf::Sprite Level::getCloudLevel()
{
	return spriteCloudLevel;
}

//#######################################################################################################
//	Setters
//#######################################################################################################
void Level::setSpriteLevel(sf::Sprite s)
{
	spriteLevel = s;
}

void Level::setMaskLevel(sf::Image i)
{
	maskLevel = i;
}

void Level::setCloudLevel(sf::Sprite s)
{
	spriteCloudLevel = s;
}
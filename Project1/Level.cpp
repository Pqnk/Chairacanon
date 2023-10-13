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

sf::Sprite Level::getButton1Level()
{
	return spriteButton1;
}

sf::Sprite Level::getButton2Level()
{
	return spriteButton2;
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

void Level::setButtonsLevel(sf::Sprite s)
{
	spriteButton1 = s;
	frameButton1.left = 0.f;
	frameButton1.top = 0.f;
	frameButton1.width = 230.f;
	frameButton1.height = 80.f;
	spriteButton1.setTextureRect(frameButton1);
	spriteButton1.setOrigin(115, 40);
	spriteButton1.setPosition(815.f, 440.f);

	spriteButton2 = s;
	frameButton2.left = 0.f;
	frameButton2.top = 80.f;
	frameButton2.width = 230.f;
	frameButton2.height = 80.f;
	spriteButton2.setTextureRect(frameButton2);
	spriteButton2.setOrigin(115, 40);
	spriteButton2.setPosition(815.f, 640.f);
}

void Level::setColorButton1()
{
	frameButton1.left = 234.f;
	spriteButton1.setTextureRect(frameButton1);
	spriteButton1.setScale(1.2f, 1.2f);
}

void Level::resetColorButton1()
{
	frameButton1.left = 0.f;
	spriteButton1.setTextureRect(frameButton1);
	spriteButton1.setScale(1.f, 1.f);
}

void Level::setColorButton2()
{
	frameButton2.left = 234.f;
	spriteButton2.setTextureRect(frameButton2);
	spriteButton2.setScale(1.2f, 1.2f);
}

void Level::resetColorButton2()
{
	frameButton2.left = 0.f;
	spriteButton2.setTextureRect(frameButton2);
	spriteButton2.setScale(1.f, 1.f);
}


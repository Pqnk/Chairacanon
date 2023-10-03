#include "SpriteManager.hpp"

SpriteManager::SpriteManager()
{
}

//#######################################################################################################
//	Initialisations
//#######################################################################################################
void SpriteManager::initSpriteManager()
{
	initCharacterSprite();
	initLateralScreenSprite();
	initLevelSprite();
}

void SpriteManager::initCharacterSprite()
{
	characterImage.loadFromFile("Textures/Sprite_Sheet.png");
	characterSprite.setTexture(characterImage);
}

void SpriteManager::initLevelSprite()
{
	mainMenuImage.loadFromFile("Textures/Main_Menu.png");
	mainMenuSprite.setTexture(mainMenuImage);

	level1Image.loadFromFile("Textures/Level_01.png");
	level1Sprite.setTexture(level1Image);

	level2Image.loadFromFile("Textures/Level_02.png");
	level2Sprite.setTexture(level2Image);
}

void SpriteManager::initLateralScreenSprite()
{
	lateralScreenImage.loadFromFile("Textures/Lateral_Screen.png");
	lateralScreenSprite.setTexture(lateralScreenImage);
}

//#######################################################################################################
//	Accessors
//#######################################################################################################
sf::Sprite SpriteManager::getCharacterSprite()
{
	return characterSprite;
}

sf::Sprite SpriteManager::getMainMenuSprite()
{
	return mainMenuSprite;
}

sf::Sprite SpriteManager::getLateralScreenSprite()
{
	return lateralScreenSprite;
}

sf::Sprite SpriteManager::getLevel1Sprite()
{
	return level1Sprite;
}

sf::Sprite SpriteManager::getLevel2Sprite()
{
	return level2Sprite;
}

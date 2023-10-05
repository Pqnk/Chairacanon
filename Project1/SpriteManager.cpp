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
	initCloudSprite();
}

void SpriteManager::initCharacterSprite()
{
	characterImage.loadFromFile("Textures/Sprite_Sheet.png");
	characterSprite.setTexture(characterImage);
}

void SpriteManager::initLevelSprite()
{
	//	////////////////////////////////////////////////////////
	//	Menu
	mainMenuImage.loadFromFile("Textures/Main_Menu.png");
	mainMenuSprite.setTexture(mainMenuImage);

	//	////////////////////////////////////////////////////////
	//	Level 01
	level1Image.loadFromFile("Textures/Level_01.png");
	level1Sprite.setTexture(level1Image);
	//	Mask Level1
	level1MaskImage.loadFromFile("Textures/Level_01_Mask.png");

	//	////////////////////////////////////////////////////////
	//	Level 02
	level2Image.loadFromFile("Textures/Level_02.png");
	level2Sprite.setTexture(level2Image);
	//	Mask Level2
	level2MaskImage.loadFromFile("Textures/Level_02_Mask.png");
}

void SpriteManager::initLateralScreenSprite()
{
	lateralScreenImage.loadFromFile("Textures/Lateral_Screen.png");
	lateralScreenSprite.setTexture(lateralScreenImage);
}

void SpriteManager::initCloudSprite()
{
	cloudImage.loadFromFile("Textures/Cloud_02.png");
	cloudSprite.setTexture(cloudImage);
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

sf::Image SpriteManager::getLevel1MaskImage()
{
	return level1MaskImage;
}

sf::Sprite SpriteManager::getLevel1CloudSprite()
{
	return cloudSprite;
}

sf::Sprite SpriteManager::getLevel2Sprite()
{
	return level2Sprite;
}

sf::Image SpriteManager::getLevel2MaskImage()
{
	return level2MaskImage;
}

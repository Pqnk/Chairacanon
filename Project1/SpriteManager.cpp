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
	initEarthSprite();
	initNumbersSprite();
	initButtonsSprite();
	initVictorySprite();
	initGameOverSprite();
}

void SpriteManager::initCharacterSprite()
{
	characterImage.loadFromFile("Textures/Sprite_Sheet.png");
	characterSprite.setTexture(characterImage);

	enemyImage.loadFromFile("Textures/Enemy_Sheet.png");
	enemySprite.setTexture(enemyImage);
	enemySprite.setColor(sf::Color::Green);
}

void SpriteManager::initLevelSprite()
{
	//	////////////////////////////////////////////////////////
	//	Menu
	mainMenuImage.loadFromFile("Textures/Main_Menu.png");
	mainMenuSprite.setTexture(mainMenuImage);

	//	////////////////////////////////////////////////////////
	//	Level 01
	level1Image.loadFromFile("Textures/Level_00.png");
	level1Sprite.setTexture(level1Image);
	//	Mask Level1
	level1MaskImage.loadFromFile("Textures/Level_00_Mask.png");

	//	////////////////////////////////////////////////////////
	//	Level 02
	level2Image.loadFromFile("Textures/Level_02bis.png");
	level2Sprite.setTexture(level2Image);
	//	Mask Level2
	level2MaskImage.loadFromFile("Textures/Level_02bis_Mask.png");
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

void SpriteManager::initEarthSprite()
{
	earthImage.loadFromFile("Textures/Earth_Spinning.png");
	earthSprite.setTexture(earthImage);
}

void SpriteManager::initNumbersSprite()
{
	numbersImage.loadFromFile("Textures/Numbers.png");
	numbersSprite.setTexture(numbersImage);
}

void SpriteManager::initButtonsSprite()
{
	buttonsImage.loadFromFile("Textures/Buttons.png");
	buttonsSprite.setTexture(buttonsImage);
}

void SpriteManager::initVictorySprite()
{
	victoryImage.loadFromFile("Textures/Victory.png");
	victorySprite.setTexture(victoryImage);
	victorySprite.setScale(0.5, 0.5);
	victorySprite.setOrigin(800, 400);
}

void SpriteManager::initGameOverSprite()
{
	gameOverImage.loadFromFile("Textures/GameOver.png");
	gameOverSprite.setTexture(gameOverImage);
	gameOverSprite.setScale(0.5, 0.5);
	gameOverSprite.setOrigin(800, 400);
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

sf::Texture SpriteManager::getLevel1Texture()
{
	return level1Image;
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

sf::Texture SpriteManager::getLevel2Texture()
{
	return level2Image;
}

sf::Image SpriteManager::getLevel2MaskImage()
{
	return level2MaskImage;
}

sf::Sprite SpriteManager::getEarthSprite()
{
	return earthSprite;
}

sf::Sprite SpriteManager::getNumbersSprite()
{
	return numbersSprite;
}

sf::Sprite SpriteManager::getButtonsSprite()
{
	return buttonsSprite;
}

sf::Sprite SpriteManager::getGameOverSprite()
{
	return gameOverSprite;
}

sf::Sprite SpriteManager::getEnemySprite()
{
	return enemySprite;
}


//#######################################################################################################
//	Renders
//#######################################################################################################
void SpriteManager::renderVictory(Camera& cam, sf::RenderTarget& window)
{
	victorySprite.setPosition(
		cam.getCameraView().getCenter().x,
		cam.getCameraView().getCenter().y
	);
	window.draw(victorySprite);
}

void SpriteManager::renderGameOver(Camera& cam, sf::RenderTarget& window)
{
	gameOverSprite.setPosition(
		cam.getCameraView().getCenter().x,
		cam.getCameraView().getCenter().y
	);
	window.draw(gameOverSprite);
}

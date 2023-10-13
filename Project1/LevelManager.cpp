#include "LevelManager.hpp"

LevelManager::LevelManager()
{
}

void LevelManager::initLevels(sf::Sprite spriteMenu, sf::Sprite spriteButtons, sf::Sprite spriteLevel1, sf::Image maskLevel1, sf::Sprite cloudLevel1, sf::Sprite spriteLevel2, sf::Image maskLevel2, sf::Sprite spriteGameOver)
{
	//	//////////////////////////////////////
	//	Main Menu : 0
	Level menu;
	menu.setSpriteLevel(spriteMenu);
	menu.setButtonsLevel(spriteButtons);
	levels.push_back(menu);

	//	//////////////////////////////////////
	//	Level 1 : 1
	Level level1;
	level1.setSpriteLevel(spriteLevel1);
	level1.setMaskLevel(maskLevel1);
	level1.setCloudLevel(cloudLevel1);
	level1.initLevelElements();
	levels.push_back(level1);

	//	//////////////////////////////////////
	//	Level 2 : 2
	Level level2;
	level2.setSpriteLevel(spriteLevel2);
	level2.setMaskLevel(maskLevel2);
	levels.push_back(level2);

	//	//////////////////////////////////////
	//	Game Over : 3
	Level gameOver;
	gameOver.setSpriteLevel(spriteGameOver);
	gameOver.setButtonsLevel(spriteButtons);
	levels.push_back(gameOver);
}

void LevelManager::renderLevel(sf::RenderTarget& window, int numLevel)
{
	if (numLevel < 3)
	{
		window.draw(levels[numLevel].getSpriteLevel());
	}

	if (numLevel == 0)
	{
		window.draw(levels[numLevel].getButton1Level());
		window.draw(levels[numLevel].getButton2Level());
	}

	if (numLevel == 1)
	{
		window.draw(levels[numLevel].getCloudLevel());
	}

	if (numLevel == 3)
	{
		window.draw(levels[numLevel].getButton1Level());
		window.draw(levels[numLevel].getButton2Level());
	}
}
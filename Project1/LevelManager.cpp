#include "LevelManager.hpp"

LevelManager::LevelManager()
{
}

void LevelManager::initLevels(sf::Sprite spriteMenu, sf::Sprite spriteLevel1, sf::Image maskLevel1, sf::Sprite cloudLevel1, sf::Sprite spriteLevel2, sf::Image maskLevel2)
{
	Level menu;
	menu.setSpriteLevel(spriteMenu);
	levels.push_back(menu);

	Level level1;
	level1.setSpriteLevel(spriteLevel1);
	level1.setMaskLevel(maskLevel1);
	level1.setCloudLevel(cloudLevel1);
	level1.initLevelElements();
	levels.push_back(level1);

	Level level2;
	level2.setSpriteLevel(spriteLevel2);
	level2.setMaskLevel(maskLevel2);
	levels.push_back(level2);

}

void LevelManager::renderLevel(sf::RenderTarget& window, int numLevel)
{
	window.draw(levels[numLevel].getSpriteLevel());
	window.draw(levels[numLevel].getCloudLevel());
}
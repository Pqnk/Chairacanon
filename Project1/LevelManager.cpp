#include "LevelManager.hpp"

LevelManager::LevelManager()
{
}

void LevelManager::initLevels(sf::Sprite spriteMenu, sf::Sprite spriteLevel1, sf::Sprite spriteLevel2)
{
	Level menu;
	menu.setSpriteLevel(spriteMenu);
	levels.push_back(menu);

	Level level1;
	level1.setSpriteLevel(spriteLevel1);
	levels.push_back(level1);

	Level level2;
	level2.setSpriteLevel(spriteLevel2);
	levels.push_back(level2);

}

void LevelManager::renderLevel(sf::RenderTarget& window, int numLevel)
{
	window.draw(levels[numLevel].getSpriteLevel());
}
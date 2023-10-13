#include "EnemyManager.hpp"


EnemyManager::EnemyManager()
{
}

void EnemyManager::initEnemyManager(sf::Sprite s)
{
	characterSprite = s;
}

void EnemyManager::initEnemiesOnLevel(int numLevel)
{
	clearEnemies();

	if (numLevel == 1)
	{
		Enemy enemy1;
		enemy1.initEnemy(characterSprite);
		enemy1.setSpritePosition(sf::Vector2f(650.f, 500.f));
		enemies.push_back(enemy1);

		Enemy enemy2;
		enemy2.initEnemy(characterSprite);
		enemy2.setSpritePosition(sf::Vector2f(500.f, 420.f));
		enemies.push_back(enemy2);
	}

	if (numLevel == 2)
	{
		Enemy enemy1;
		enemy1.initEnemy(characterSprite);
		enemy1.setSpritePosition(sf::Vector2f(650.f, 500.f));
		enemies.push_back(enemy1);

		Enemy enemy2;
		enemy2.initEnemy(characterSprite);
		enemy2.setSpritePosition(sf::Vector2f(500.f, 420.f));
		enemies.push_back(enemy2);

		Enemy enemy3;
		enemy3.initEnemy(characterSprite);
		enemy3.setSpritePosition(sf::Vector2f(450.f, 500.f));
		enemies.push_back(enemy3);

		Enemy enemy4;
		enemy4.initEnemy(characterSprite);
		enemy4.setSpritePosition(sf::Vector2f(500.f, 800.f));
		enemies.push_back(enemy4);

		Enemy enemy5;
		enemy5.initEnemy(characterSprite);
		enemy5.setSpritePosition(sf::Vector2f(550.f, 800.f));
		enemies.push_back(enemy5);
	}
}

void EnemyManager::addEnemy(Enemy e)
{
	enemies.push_back(e);
}

void EnemyManager::drawEnemy(sf::RenderTarget& window)
{
	for (auto& e : enemies)
	{
		window.draw(e.getSprite());
	}
	eraseEnemy();
}

void EnemyManager::eraseEnemy()
{
	enemies.erase(std::remove_if(enemies.begin(), enemies.end(),[](Enemy& enemy) 
		{
			return enemy.getWaitinForErase() == true;
		})
		, enemies.end());

	for (auto& e : enemies)
	{
		if (e.getWaitinForErase() == true)
		{
			enemies.erase(enemies.end());
		}
	}
}

void EnemyManager::updateEnemies(Player &player, sf::Image maskLevel)
{
	for (auto& e : enemies)
	{
		e.updateEnemy(player, maskLevel);
		e.updateSpriteColor();
	}
}

void EnemyManager::clearEnemies()
{
	enemies.clear();
}



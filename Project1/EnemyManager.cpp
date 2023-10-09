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
	}
}



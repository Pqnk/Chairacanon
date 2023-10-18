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
		enemy1.setSpritePosition(sf::Vector2f(300.f, 100.f));
		enemies.push_back(enemy1);

		Enemy enemy2;
		enemy2.initEnemy(characterSprite);
		enemy2.setSpritePosition(sf::Vector2f(150.f, 300.f));
		enemies.push_back(enemy2);

		Enemy enemy3;
		enemy3.initEnemy(characterSprite);
		enemy3.setSpritePosition(sf::Vector2f(65.f, 205.f));
		enemies.push_back(enemy3);

	}

	if (numLevel == 2)
	{
		Enemy enemy1;
		enemy1.initEnemy(characterSprite);
		enemy1.setSpritePosition(sf::Vector2f(400.f, 580.f));
		enemies.push_back(enemy1);

		Enemy enemy2;
		enemy2.initEnemy(characterSprite);
		enemy2.setSpritePosition(sf::Vector2f(460.f, 540.f));
		enemies.push_back(enemy2);

		Enemy enemy3;
		enemy3.initEnemy(characterSprite);
		enemy3.setSpritePosition(sf::Vector2f(520.f, 540.f));
		enemies.push_back(enemy3);

		Enemy enemy4;
		enemy4.initEnemy(characterSprite);
		enemy4.setSpritePosition(sf::Vector2f(560.f, 580.f));
		enemies.push_back(enemy4);

		Enemy enemy5;
		enemy5.initEnemy(characterSprite);
		enemy5.setSpritePosition(sf::Vector2f(125.f, 100.f));
		enemies.push_back(enemy5);

		Enemy enemy6;
		enemy6.initEnemy(characterSprite);
		enemy6.setSpritePosition(sf::Vector2f(700.f, 110.f));
		enemies.push_back(enemy6);

		Enemy enemy7;
		enemy7.initEnemy(characterSprite);
		enemy7.setSpritePosition(sf::Vector2f(960.f, 300.f));
		enemies.push_back(enemy7);

		Enemy enemy8;
		enemy8.initEnemy(characterSprite);
		enemy8.setSpritePosition(sf::Vector2f(150.f, 700.f));
		enemies.push_back(enemy8);

		Enemy enemy9;
		enemy9.initEnemy(characterSprite);
		enemy9.setSpritePosition(sf::Vector2f(250.f, 800.f));
		enemies.push_back(enemy9);
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



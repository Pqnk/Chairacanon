#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <sstream>

#include "Enemy.hpp"

class EnemyManager
{
	public :
	
		EnemyManager();
		
		void initEnemyManager(sf::Sprite s);

		void initEnemiesOnLevel(int numLevel);

		void addEnemy(Enemy e);
		void drawEnemy(sf::RenderTarget& window);
		void eraseEnemy();
		void updateEnemies(sf::Vector2f playerPos);


		std::vector <Enemy> enemies;

		sf::Sprite characterSprite;
};


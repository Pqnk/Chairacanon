#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>

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
		void updateEnemies(Player &player, sf::Image maskLevel);
		void clearEnemies();

		std::vector <Enemy> enemies;

		sf::Sprite characterSprite;
};


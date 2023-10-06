#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include "EnemyManager.hpp"

using namespace std;

class Bullet
{
	public :

		Bullet(sf::Vector2f pos, sf::Vector2f dir, sf::Sprite sprite);

		sf::RectangleShape bulletShape;

		sf::Sprite spriteBullet;
		sf::IntRect frameBullet;

		sf::Vector2f direction;
		sf::Vector2f position;

		void updateBullet(std::vector<Enemy> &enemies);
		void animationBullet();

		sf::Clock bulletTimer;
		sf::Clock bulletAnimationTimer;

		bool waitingForDestroy;
		bool hasAlreadyHit;
};


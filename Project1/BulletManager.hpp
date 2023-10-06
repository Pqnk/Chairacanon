#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include "Bullet.hpp"


class BulletManager
{
	public :

		BulletManager();

		void addBullet(Bullet b);
		void drawBullet(sf::RenderTarget& window);
		void eraseBullet();
		void updateBullets(std::vector<Enemy>& enemies);

		std::vector<Bullet> bullets;
};


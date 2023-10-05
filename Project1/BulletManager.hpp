#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Bullet.hpp"

class BulletManager
{
	public :

		BulletManager();

		void addBullet(Bullet b);
		void drawBullet(sf::RenderTarget& window);
		void eraseBullet();
		void updateBullets();

		std::vector<Bullet> bullets;
};


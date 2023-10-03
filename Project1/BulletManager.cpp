#include "BulletManager.hpp"

BulletManager::BulletManager()
{

}

void BulletManager::addBullet(Bullet b)
{
	bullets.push_back(b);
}

void BulletManager::drawBullet(sf::RenderTarget& window)
{
	for (auto& b : bullets)
	{
		//window.draw(b.spriteBullet);
		window.draw(b.bulletShape);
	}
}

void BulletManager::eraseBullet()
{
}

void BulletManager::updateBullets()
{
	for (auto& bu : bullets)
	{
		bu.updateBullet();
	}
}

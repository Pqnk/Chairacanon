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
		if (b.hasAlreadyHit == false)
		{
			window.draw(b.spriteBullet);
		}
	}

	eraseBullet();
}

void BulletManager::eraseBullet()
{
	for (auto& b : bullets)
	{
		if (b.waitingForDestroy == true)
		{
			bullets.erase(bullets.begin());
		}
	}
}

void BulletManager::updateBullets(std::vector<Enemy>& enemies, sf::Image maskLevel)
{
	for (auto& bu : bullets)
	{
		bu.updateBullet(enemies, maskLevel);
	}
}

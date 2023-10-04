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
		window.draw(b.spriteBullet);
		std::cout << "Longueur tab : " << bullets.size() << std::endl;
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

void BulletManager::updateBullets()
{
	for (auto& bu : bullets)
	{
		bu.updateBullet();
	}
}

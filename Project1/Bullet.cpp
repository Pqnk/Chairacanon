#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f dir, sf::Sprite sprite)
{	
	waitingForDestroy = false;
	hasAlreadyHit = false;


	bulletSpeed = 3.f;

	position = pos;
	position.x += 5.f;
	position.y -= 10.f;

	spriteBullet = sprite;
	spriteBullet.setPosition(pos);
	frameBullet.left = 0.f;
	frameBullet.top = 1728.f;
	frameBullet.width = 64.f;
	frameBullet.height = 64.f;
	spriteBullet.setTextureRect(frameBullet);
	spriteBullet.setScale(0.5f, 0.5f);
	spriteBullet.setOrigin(30.f, 50.f);
	
	direction = dir - position;

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0)
		direction /= length;
	direction.x *= bulletSpeed;
	direction.y *= bulletSpeed;

	bulletTimer.restart();
	bulletAnimationTimer.restart();
}

void Bullet::updateBullet(std::vector<Enemy> &enemies, sf::Image maskLevel)
{
	animationBullet();
	collisionDetection(maskLevel);
	//	/////////////////////////////////////////////////////
	//	Detects an enemy
	for (auto& e : enemies)
	{
		sf::Vector2f bulletPosRelativeToEnemy;
		bulletPosRelativeToEnemy = e.getSpritePosition() - spriteBullet.getPosition();

		if (bulletPosRelativeToEnemy.x > -5
			&&	bulletPosRelativeToEnemy.x	<	5
			&&	bulletPosRelativeToEnemy.y	>	-2
			&&	bulletPosRelativeToEnemy.y < 30
			&&	hasAlreadyHit == false
			)
		{
			e.damageHealth(2);
			hasAlreadyHit = true;
		}
	}
}

void Bullet::animationBullet()
{
	if (bulletTimer.getElapsedTime().asSeconds() < 1.f && hasAlreadyHit == false)
	{
		spriteBullet.move(direction);

		if (bulletAnimationTimer.getElapsedTime().asSeconds() >= 0.06f)
		{
			frameBullet.left += 64.f;
			if (frameBullet.left >= 1024.f)
			{
				frameBullet.left = 0.f;
			}

			spriteBullet.setTextureRect(frameBullet);
			bulletAnimationTimer.restart();
		}
	}
	else
	{
		spriteBullet.setColor(sf::Color::Transparent);
		waitingForDestroy = true;
		bulletTimer.restart();
	}
}

void Bullet::collisionDetection(sf::Image maskLevel)
{
	int pixelColored = maskLevel.getPixel(spriteBullet.getPosition().x, spriteBullet.getPosition().y).toInteger();


	switch (pixelColored)
	{
		//	BLACK
		case 255:
			hasAlreadyHit = true;
		break;
	}
}

#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f dir, sf::Sprite sprite)
{	
	waitingForDestroy = false;

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
	direction.x *= 2.f;
	direction.y *= 2.f;

	bulletTimer.restart();
}

void Bullet::updateBullet()
{

	if (bulletTimer.getElapsedTime().asSeconds() < 1.f)
	{
		spriteBullet.move(direction);
	}
	else
	{
		spriteBullet.setColor(sf::Color::Transparent);
		waitingForDestroy = true;
		bulletTimer.restart();
	}
}
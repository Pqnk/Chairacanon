#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f dir)
{
	/*
	texturebullet.loadFromFile("Textures/Mickey2.png");
	spriteBullet.setTexture(texturebullet);

	spriteBullet.setPosition(pos);

	frameBullet.left = 0.f;
	frameBullet.top = 0.f;
	frameBullet.width = 64.f;
	frameBullet.height = 64.f;
	spriteBullet.setTextureRect(frameBullet);

	spriteBullet.setScale(0.5f, 0.5f);
	*/
	
	bulletShape.setSize(sf::Vector2f(3.f,3.f));
	bulletShape.setFillColor(sf::Color::Blue);
	
	position = pos;
	position.x += 5.f;
	position.y -= 10.f;
	bulletShape.setPosition(position);
	

	direction = dir - position;
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0)
	{
		direction /= length;
	}
	direction.x *= 2.f;
	direction.y *= 2.f;

	bulletTimer.restart();
}

void Bullet::updateBullet()
{
	if (bulletTimer.getElapsedTime().asSeconds() < 1.f)
	{
		sf::Vector2f actualPos = bulletShape.getPosition();
		bulletShape.setPosition(actualPos + direction);

		//sf::Vector2f actualPos = spriteBullet.getPosition();
		//spriteBullet.setPosition(actualPos + direction);
	}
	else
	{
		bulletShape.setFillColor(sf::Color::Transparent);
		//spriteBullet.setColor(sf::Color::Transparent);
		bulletTimer.restart();
	}
}
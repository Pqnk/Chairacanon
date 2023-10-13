#include "Rocket.hpp"
#include <iostream>

Rocket::Rocket()
{

}

Rocket::Rocket(sf::Sprite s, sf::Vector2f playerPos, sf::Vector2f dir)
{
	hasHitTarget = false;
	explosion = false;
	rocketSpeed = 2.f;

	spriteRocket = s;
	frameRocket.left = 256.f;
	frameRocket.top = 1792.f;
	frameRocket.width = 64.f;
	frameRocket.height = 64.f;
	spriteRocket.setTextureRect(frameRocket);
	spriteRocket.setScale(0.4, 0.4);
	spriteRocket.setOrigin(32.f, 32.f);
	spriteRocket.setPosition(playerPos);

	position = playerPos;
	position.x += 5.f;
	position.y -= 10.f;

	direction = dir - position;

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0)
		direction /= length;
	direction.x *= rocketSpeed;
	direction.y *= rocketSpeed;

	//std::cout << direction.x << "   " << direction.y << std::endl;

	if (direction.x < 0 && direction.y < 0)
	{
		spriteRocket.setRotation(-135.f);
	}
	if (direction.x > 0 && direction.y > 0)
	{
		spriteRocket.setRotation(45.f);
	}
	if (direction.x < 0 && direction.y > 0)
	{
		spriteRocket.setRotation(135.f);
	}
	if (direction.x > 0 && direction.y < 0)
	{
		spriteRocket.setRotation(-45.f);
	}

	rocketTimer.restart();
	rocketAnimationTimer.restart();
}

void Rocket::updateRocket(sf::Image maskLevel)
{
	if (explosion == true)
	{
		if (rocketAnimationTimer.getElapsedTime().asSeconds() >= 0.06f)
		{
			frameRocket.left += 64.f;
			if (frameRocket.left >= 832.f)
			{
				spriteRocket.setColor(sf::Color::Transparent);
				hasHitTarget = true;
			}
			spriteRocket.setTextureRect(frameRocket);
			rocketAnimationTimer.restart();
		}
	}
	else
	{
		animationRocket();
		collisionDetection(maskLevel);
	}
}

void Rocket::animationRocket()
{
	if (rocketTimer.getElapsedTime().asSeconds() < 2.f)
	{
		spriteRocket.move(direction);

		if (rocketAnimationTimer.getElapsedTime().asSeconds() >= 0.06f)
		{
			frameRocket.left += 64.f;
			if (frameRocket.left >= 1024.f)
			{
				frameRocket.left = 832.f;
			}
			spriteRocket.setTextureRect(frameRocket);
			rocketAnimationTimer.restart();
		}
	}
	else
	{
		resetAnimExplosion();
	}
}

void Rocket::collisionDetection(sf::Image maskLevel)
{
	int pixelColored = maskLevel.getPixel(spriteRocket.getPosition().x, spriteRocket.getPosition().y).toInteger();

	switch (pixelColored)
	{
		//	BLACK
		case 255:
			resetAnimExplosion();
		break;
	}
}

void Rocket::resetAnimExplosion()
{
	frameRocket.top = 1600.f;
	frameRocket.left = 0.f;
	spriteRocket.setTextureRect(frameRocket);
	spriteRocket.setScale(1.f, 1.f);
	rocketAnimationTimer.restart();

	explosion = true;
}

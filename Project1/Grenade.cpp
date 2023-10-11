#include "Grenade.hpp"
#include <iostream>

Grenade::Grenade()
{

}

Grenade::Grenade(sf::Sprite s, sf::Vector2f playerPos, sf::Vector2f dir)
{
	hasHitTarget = false;
	explosion = false;
	grenadeSpeed = 2.f;

	grenadeSprite = s;
	grenadeFrame.left = 256.f;
	grenadeFrame.top = 1792.f;
	grenadeFrame.width = 64.f;
	grenadeFrame.height = 64.f;
	grenadeSprite.setTextureRect(grenadeFrame);
	grenadeSprite.setScale(0.4, 0.4);
	grenadeSprite.setOrigin(32.f, 32.f);
	grenadeSprite.setPosition(playerPos);

	position = playerPos;
	position.x += 5.f;
	position.y -= 10.f;

	direction = dir - position;

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0)
		direction /= length;
	direction.x *= grenadeSpeed;
	direction.y *= grenadeSpeed;

	//std::cout << direction.x << "   " << direction.y << std::endl;

	if (direction.x < 0 && direction.y < 0)
	{
		grenadeSprite.setRotation(-135.f);
	}
	if (direction.x > 0 && direction.y > 0)
	{
		grenadeSprite.setRotation(45.f);
	}
	if (direction.x < 0 && direction.y > 0)
	{
		grenadeSprite.setRotation(135.f);
	}
	if (direction.x > 0 && direction.y < 0)
	{
		grenadeSprite.setRotation(-45.f);
	}

	grenadeTimer.restart();
	grenadeAnimationTimer.restart();
}

void Grenade::updateGrenade(sf::Image maskLevel)
{
	if (explosion == true)
	{
		if (grenadeAnimationTimer.getElapsedTime().asSeconds() >= 0.06f)
		{
			grenadeFrame.left += 64.f;
			if (grenadeFrame.left >= 832.f)
			{
				grenadeSprite.setColor(sf::Color::Transparent);
				hasHitTarget = true;
			}
			grenadeSprite.setTextureRect(grenadeFrame);
			grenadeAnimationTimer.restart();
		}
	}
	else
	{
		animationGrenade();
		collisionDetection(maskLevel);
	}
}

void Grenade::animationGrenade()
{
	if (grenadeTimer.getElapsedTime().asSeconds() < 2.f)
	{
		grenadeSprite.move(direction);

		if (grenadeAnimationTimer.getElapsedTime().asSeconds() >= 0.06f)
		{
			grenadeFrame.left += 64.f;
			if (grenadeFrame.left >= 1024.f)
			{
				grenadeFrame.left = 832.f;
			}
			grenadeSprite.setTextureRect(grenadeFrame);
			grenadeAnimationTimer.restart();
		}
	}
	else
	{
		grenadeFrame.top = 1600.f;
		grenadeFrame.left = 0.f;
		grenadeSprite.setTextureRect(grenadeFrame);
		grenadeSprite.setScale(1.f, 1.f);
		grenadeAnimationTimer.restart();

		explosion = true;
	}
}

void Grenade::collisionDetection(sf::Image maskLevel)
{
	int pixelColored = maskLevel.getPixel(grenadeSprite.getPosition().x, grenadeSprite.getPosition().y).toInteger();

	switch (pixelColored)
	{
		//	BLACK
		case 255:

			grenadeFrame.top = 1600.f;
			grenadeFrame.left = 0.f;
			grenadeSprite.setTextureRect(grenadeFrame);
			grenadeSprite.setScale(1.f, 1.f);
			grenadeAnimationTimer.restart();
			explosion = true;
		break;
	}
}

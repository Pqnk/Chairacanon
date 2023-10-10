#include "Grenade.hpp"
#include <iostream>

Grenade::Grenade()
{

}

Grenade::Grenade(sf::Sprite s, sf::Vector2f playerPos, sf::Vector2f dir)
{
	hasHitTarget = false;
	grenadeSpeed = 3.f;

	grenadeSprite = s;
	grenadeFrame.left = 64.f;
	grenadeFrame.top = 1856.f;
	grenadeFrame.width = 64.f;
	grenadeFrame.height = 64.f;
	grenadeSprite.setTextureRect(grenadeFrame);
	grenadeSprite.setScale(0.6, 0.6);
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

	grenadeTimer.restart();
	grenadeAnimationTimer.restart();
}

void Grenade::updateGrenade(sf::Vector2f destinationPos)
{
	sf::Vector2f dest = grenadeSprite.getPosition() - destinationPos;
	if (	dest.x > -10
		&&	dest.x < 10
		&&	dest.y > -10
		&&	dest.y < 10
		)
	{
		hasHitTarget = true;
	}
	else
	{
		if (grenadeTimer.getElapsedTime().asSeconds() >= 3.f)
		{
			hasHitTarget = true;
		}
		else
		{
			grenadeSprite.move(direction);
		}
	}
}

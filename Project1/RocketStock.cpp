#include "RocketStock.hpp"

RocketStock::RocketStock()
{
}

RocketStock::RocketStock(sf::Sprite s)
{
	amunition = 5;
	isPickedUp = false;

	spriteRocket = s;
	frameRocket.left = 0.f;
	frameRocket.top = 1856.f;
	frameRocket.width = 64.f;
	frameRocket.height = 64.f;
	spriteRocket.setTextureRect(frameRocket);

	spriteRocket.setScale(0.6, 0.6);

	spriteRocket.setOrigin(32.f, 32.f);
}
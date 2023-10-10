#include "GrenadeStock.hpp"

GrenadeStock::GrenadeStock()
{
}

GrenadeStock::GrenadeStock(sf::Sprite s)
{
	amunition = 5;
	isPickedUp = false;

	grenadeSprite = s;
	grenadeFrame.left = 0.f;
	grenadeFrame.top = 1856.f;
	grenadeFrame.width = 64.f;
	grenadeFrame.height = 64.f;
	grenadeSprite.setTextureRect(grenadeFrame);

	grenadeSprite.setScale(0.6, 0.6);

	grenadeSprite.setOrigin(32.f, 32.f);
}
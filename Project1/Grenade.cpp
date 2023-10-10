#include "Grenade.hpp"

Grenade::Grenade(sf::Sprite s)
{
	amunition = 5;
	grenadeDamage = 10;
	isPickedUp = false;

	grenadeSprite = s;
	grenadeFrame.left = 0.f;
	grenadeFrame.top = 1856.f;
	grenadeFrame.width = 64.f;
	grenadeFrame.height = 64.f;
	grenadeSprite.setTextureRect(grenadeFrame);
}
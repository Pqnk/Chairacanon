#include "Weapons.hpp"

Weapons::Weapons() : damagePoints(0)
{
}

Weapons::~Weapons()
{
}

void Weapons::initWeapon()
{
	std::string path("Textures/Mickey2.png");
	sf::Vector2f scale(0.5f, 0.5f);
	sf::Vector2f position(0.f, 0.f);
	sf::Vector2f origin(0.f, 0.f);

	frameSprite.left = 0.f;
	frameSprite.top = 0.f;
	frameSprite.width = 66.f;
	frameSprite.height = 66.f;

	initSprite(path, scale, position, origin);
}

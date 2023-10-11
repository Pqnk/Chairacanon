#include "Building.hpp"

Building::Building(sf::Sprite s, sf::Vector2f position)
{
	isHitByRocket = false;

	spriteBuilding = s;
	frameBuilding.left = 0.f;
	frameBuilding.top = 1920.f;
	frameBuilding.width = 192.f;
	frameBuilding.height = 128.f;
	spriteBuilding.setTextureRect(frameBuilding);
	spriteBuilding.setScale(0.4, 0.4);
	spriteBuilding.setOrigin(32.f, 32.f);
	spriteBuilding.setPosition(position);

	buildingAnimationTimer.restart();

}

void Building::animationBuilding()
{
	frameBuilding.left = 192.f;
	spriteBuilding.setTextureRect(frameBuilding);
}

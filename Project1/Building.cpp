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
	spriteBuilding.setOrigin(192.f / 2.f, 128.f / 2.f);
	spriteBuilding.setPosition(position);

	buildingAnimationTimer.restart();

}

void Building::destroyingBuilding()
{
	frameBuilding.left = 192.f;
	spriteBuilding.setTextureRect(frameBuilding);
}

void Building::updatingBuildgin(std::vector<Grenade>& gre)
{
	sf::Vector2f posBuildingRelToRocket;

	for (auto& g : gre)
	{
		posBuildingRelToRocket = spriteBuilding.getPosition() - g.grenadeSprite.getPosition();

		if (	posBuildingRelToRocket.x < 20
				&& posBuildingRelToRocket.x > -20
				&& posBuildingRelToRocket.y < 5
				&& posBuildingRelToRocket.y > -20
			)
		{
			isHitByRocket = true;
			g.resetAnimExplosion();
		}

	}



}

#include "Tank.hpp"

Tank::Tank(sf::Sprite s, sf::Vector2f position)
{
	isHitByRocket = false;

	spriteTank = s;
	frameTank.left = 0.f;
	frameTank.top = 1920.f;
	frameTank.width = 192.f;
	frameTank.height = 128.f;
	spriteTank.setTextureRect(frameTank);
	spriteTank.setScale(0.4, 0.4);
	spriteTank.setOrigin(192.f / 2.f, 128.f / 2.f);
	spriteTank.setPosition(position);

	tankAnimationTimer.restart();

}

void Tank::destroyingTanks()
{
	frameTank.left = 192.f;
	spriteTank.setTextureRect(frameTank);
}

void Tank::updatingTanks(std::vector<Grenade>& gre)
{
	sf::Vector2f posBuildingRelToRocket;

	for (auto& g : gre)
	{
		posBuildingRelToRocket = spriteTank.getPosition() - g.grenadeSprite.getPosition();

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

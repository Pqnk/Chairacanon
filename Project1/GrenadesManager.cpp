#include "GrenadesManager.hpp"

GrenadesManager::GrenadesManager()
{
}

void GrenadesManager::initGrenadesManger(int numLevel, sf::Sprite s)
{
	switch(numLevel)
	{
		case 1 :
			Grenade blockGrenade1(s);
			blockGrenade1.grenadeSprite.setPosition(500, 500);
			addGrenade(blockGrenade1);

			Grenade blockGrenade2(s);
			blockGrenade2.grenadeSprite.setPosition(500, 550);
			addGrenade(blockGrenade2);

			break;
	}
}

void GrenadesManager::addGrenade(Grenade g)
{
	grenades.push_back(g);
}

void GrenadesManager::drawGrenade(sf::RenderTarget& window)
{
	for (auto& g : grenades)
	{
		window.draw(g.grenadeSprite);
	}
	eraseGrenades();
}

void GrenadesManager::updateGrenades(Player& player)
{
	for (auto& g : grenades)
	{
		grenadePosRelToPlayer = g.grenadeSprite.getPosition() - player.getSpritePosition();

		if (	grenadePosRelToPlayer.x	<  10
			&&	grenadePosRelToPlayer.x > -10
			&& grenadePosRelToPlayer.y	<  10
			&& grenadePosRelToPlayer.y	> -10	)
		{
			g.isPickedUp = true;
			player.setNumGrenades( player.getNumGrenades() + g.amunition);
		}
	}
}

void GrenadesManager::eraseGrenades()
{
	grenades.erase(std::remove_if(grenades.begin(), grenades.end(), [](Grenade& gre)
		{
			return gre.isPickedUp == true;
		})
		, grenades.end());

	for (auto& g : grenades)
	{
		if (g.isPickedUp == true)
		{
			grenades.erase(grenades.end());
		}
	}
}


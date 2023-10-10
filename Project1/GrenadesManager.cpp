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
			break;
	}
}

void GrenadesManager::addGrenade(Grenade g)
{
	grenades.push_back(g);
}


#include "GrenadesManager.hpp"

GrenadesManager::GrenadesManager()
{
}

//######################################################
//	Managing the STOCKS of grenade (the collectibles)
//######################################################
void GrenadesManager::initGrenadeStocksManager(int numLevel, sf::Sprite s)
{
	switch(numLevel)
	{
		case 1 :
			GrenadeStock blockGrenade1(s);
			blockGrenade1.grenadeSprite.setPosition(500, 500);
			addGrenadeStocks(blockGrenade1);

			GrenadeStock blockGrenade2(s);
			blockGrenade2.grenadeSprite.setPosition(500, 550);
			addGrenadeStocks(blockGrenade2);

			break;
	}
}

void GrenadesManager::addGrenadeStocks(GrenadeStock gs)
{
	grenadeStocks.push_back(gs);
}

void GrenadesManager::drawGrenadeStocks(sf::RenderTarget& window)
{
	for (auto& g : grenadeStocks)
	{
		window.draw(g.grenadeSprite);
	}
	eraseGrenadeStocks();
}

void GrenadesManager::updateGrenadeStocks(Player& player)
{
	for (auto& g : grenadeStocks)
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

void GrenadesManager::eraseGrenadeStocks()
{
	grenadeStocks.erase(std::remove_if(grenadeStocks.begin(), grenadeStocks.end(), [](GrenadeStock& gre)
		{
			return gre.isPickedUp == true;
		})
		, grenadeStocks.end());

	for (auto& g : grenadeStocks)
	{
		if (g.isPickedUp == true)
		{
			grenadeStocks.erase(grenadeStocks.end());
		}
	}
}


//######################################################
//	Managing the GRENADES THROWED
//######################################################
void GrenadesManager::addGrenadeThrowed(sf::Sprite s, Player& player, sf::Vector2f dir)
{
	if (grenadeThrowed.size() == 0)
	{
		player.setNumGrenades(player.getNumGrenades() - 1);
		Grenade g(s, player.getSpritePosition(), dir);
		grenadeThrowed.push_back(g);
	}

}

void GrenadesManager::updateGrenadesThrowed(sf::Image maskLevel)
{
	for (auto& g : grenadeThrowed)
	{
		if (g.hasHitTarget == false)
		{
			g.updateGrenade(maskLevel);
		}
		else
		{
			eraseGrenadesThrowed();
		}
	}
}

void GrenadesManager::eraseGrenadesThrowed()
{
	grenadeThrowed.clear();
}

void GrenadesManager::drawGrenadesThrowed(sf::RenderTarget& window)
{
	for (auto& g : grenadeThrowed)
	{
		window.draw(g.grenadeSprite);
	}
}


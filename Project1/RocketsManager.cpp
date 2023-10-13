#include "RocketsManager.hpp"

RocketsManager::RocketsManager()
{
}

//######################################################
//	Managing the STOCKS of grenade (the collectibles)
//######################################################
void RocketsManager::initRocketStocksManager(int numLevel, sf::Sprite s)
{
	if(numLevel == 1)
	{
		rocketStocks.clear();
		RocketStock rocketStock1(s);
		rocketStock1.spriteRocket.setPosition(500, 500);
		addRocketStocks(rocketStock1);

		RocketStock rocketStock2(s);
		rocketStock2.spriteRocket.setPosition(500, 550);
		addRocketStocks(rocketStock2);
	}

	if (numLevel == 2)
	{
		rocketStocks.clear();
		RocketStock rocketStock1(s);
		rocketStock1.spriteRocket.setPosition(500, 500);
		addRocketStocks(rocketStock1);

		RocketStock rocketStock2(s);
		rocketStock2.spriteRocket.setPosition(500, 550);
		addRocketStocks(rocketStock2);
	}
}

void RocketsManager::addRocketStocks(RocketStock gs)
{
	rocketStocks.push_back(gs);
}

void RocketsManager::drawRocketStocks(sf::RenderTarget& window)
{
	for (auto& g : rocketStocks)
	{
		window.draw(g.spriteRocket);
	}
	eraseRocketStocks();
}

void RocketsManager::updateRocketStocks(Player& player)
{
	for (auto& g : rocketStocks)
	{
		rocketPosRelToPlayer = g.spriteRocket.getPosition() - player.getSpritePosition();

		if (	rocketPosRelToPlayer.x	<  10
			&&	rocketPosRelToPlayer.x > -10
			&&	rocketPosRelToPlayer.y	<  10
			&&	rocketPosRelToPlayer.y	> -10	)
		{
			//g.soundPickUp.play();
			g.isPickedUp = true;
			player.setNumGrenades( player.getNumGrenades() + g.amunition);
		}
	}
}

void RocketsManager::eraseRocketStocks()
{
	rocketStocks.erase(std::remove_if(rocketStocks.begin(), rocketStocks.end(), [](RocketStock& gre)
		{
			return gre.isPickedUp == true;
		})
		, rocketStocks.end());

	for (auto& g : rocketStocks)
	{
		if (g.isPickedUp == true)
		{
			rocketStocks.erase(rocketStocks.end());
		}
	}
}


//######################################################
//	Managing the GRENADES THROWED
//######################################################
void RocketsManager::addRocketThrowed(sf::Sprite s, Player& player, sf::Vector2f dir)
{
	if (rocketsThrowed.size() == 0)
	{
		player.setNumGrenades(player.getNumGrenades() - 1);
		Rocket g(s, player.getSpritePosition(), dir);
		rocketsThrowed.push_back(g);
	}

}

void RocketsManager::updateRocketsThrowed(sf::Image maskLevel)
{
	for (auto& g : rocketsThrowed)
	{
		if (g.hasHitTarget == false)
		{
			g.updateRocket(maskLevel);
		}
		else
		{
			eraseRocketsThrowed();
		}
	}
}

void RocketsManager::eraseRocketsThrowed()
{
	rocketsThrowed.clear();
}

void RocketsManager::drawRocketsThrowed(sf::RenderTarget& window)
{
	for (auto& g : rocketsThrowed)
	{
		window.draw(g.spriteRocket);
	}
}


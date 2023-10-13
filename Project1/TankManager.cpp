#include "TankManager.hpp"

TankManager::TankManager()
{
}

//#######################
//	Managing tanks
//#######################
void TankManager::initTanksOnMap(int numLevel, sf::Sprite s)
{
	//	/////////////////
	// Level 1
	if (numLevel == 1)
	{
		tanks.clear();
		destroyedTanks.clear();

		//	//////////////////////////////////
		//	Tank 1
		sf::Vector2f posTank1(600.f, 600.f);
		Tank tank1(s, posTank1);
		tanks.push_back(tank1);

		//	//////////////////////////////////
		//	Tank 2
		sf::Vector2f posTank2(700.f, 600.f);
		Tank tank2(s, posTank2);
		tanks.push_back(tank2);

		tankNumber = tanks.size();
	}

	//	/////////////////
	// Level 2
	if (numLevel == 2)
	{
		tanks.clear();
		destroyedTanks.clear();

		//	//////////////////////////////////
		//	Tank 1
		sf::Vector2f posTank1(600.f, 300.f);
		Tank tank1(s, posTank1);
		tanks.push_back(tank1);

		//	//////////////////////////////////
		//	Tank 2
		sf::Vector2f posTank2(700.f, 300.f);
		Tank tank2(s, posTank2);
		tanks.push_back(tank2);

		tankNumber = tanks.size();
	}
}

void TankManager::drawTanks(sf::RenderTarget& window)
{

	for (auto& t : tanks)
	{
		window.draw(t.spriteTank);
	}

	for (auto& t : destroyedTanks)
	{
		window.draw(t.spriteTank);
	}

}

void TankManager::updateTanksOnMap(std::vector<Rocket>& rocket)
{
	for (auto& t : tanks)
	{
		if (t.isHitByRocket == false)
		{
			t.updatingTanks(rocket);
		}
		else
		{
			t.destroyingTanks();
			destroyedTanks.push_back(t);
			eraseTank();
			tankNumber = tanks.size();
		}
	}
}

void TankManager::eraseTank()
{
	tanks.erase(std::remove_if(tanks.begin(), tanks.end(), [](Tank& tank)
		{
			return tank.isHitByRocket == true;
		})
		, tanks.end());

	for (auto& e : tanks)
	{
		if (e.isHitByRocket == true)
		{
			tanks.erase(tanks.end());
		}
	}
}

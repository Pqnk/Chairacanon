#include "BuildingManager.hpp"

BuildingManager::BuildingManager()
{
}

//#######################
//	Managing tanks
//#######################
void BuildingManager::initTanksOnMap(int numLevel, sf::Sprite s)
{
	switch(numLevel)
	{
		//	/////////////////
		// Level 1
		case 1:

			//	//////////////////////////////////
			//	Tank 1
			sf::Vector2f posTank1(600.f, 600.f);
			Building tank1(s, posTank1);
			tanks.push_back(tank1);

			////	//////////////////////////////////
			////	Tank 2
			//sf::Vector2f posTank2(700.f, 600.f);
			//Building tank2(s, posTank2);
			//tanks.push_back(tank2);

			initialTankNumber = tanks.size();

		break;
	}
}

void BuildingManager::drawTanks(sf::RenderTarget& window)
{
	for (auto& t : tanks)
	{
		window.draw(t.spriteBuilding);
	}
}

void BuildingManager::updateTanksOnMap(std::vector<Grenade>& gre)
{
	for (auto& t : tanks)
	{
		if (t.isHitByRocket == false)
		{
			t.updatingBuildgin(gre);
		}
		else
		{
			t.destroyingBuilding();
			initialTankNumber -= 1;
		}
	}
}

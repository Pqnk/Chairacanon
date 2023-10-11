#include "Building.hpp"

class BuildingManager
{
	public :
		
		BuildingManager();

		//#######################
		//	Managing tanks
		//#######################
		void initTanksOnMap(int numLevel, sf::Sprite s);
		void drawTanks(sf::RenderTarget& window);
		void updateTanksOnMap(std::vector<Grenade>& gre);

		std::vector<Building> tanks;

		int initialTankNumber;
};


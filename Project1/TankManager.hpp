#include "Tank.hpp"

class TankManager
{
	public :
		
		TankManager();

		//#######################
		//	Managing tanks
		//#######################
		void initTanksOnMap(int numLevel, sf::Sprite s);
		void drawTanks(sf::RenderTarget& window);
		void updateTanksOnMap(std::vector<Grenade>& gre);
		void eraseTank();

		std::vector<Tank> tanks;
		std::vector<Tank> destroyedTanks;

		int tankNumber;
};


#include "Grenade.hpp"

class GrenadesManager
{
	public :

		GrenadesManager();

		void initGrenadesManger(int numlevel, sf::Sprite s);
		void addGrenade(Grenade g);
		void drawGrenade(sf::RenderTarget& window);
		void updateGrenades();
		void eraseGrenades();


	protected :

		std::vector<Grenade> grenades;
};


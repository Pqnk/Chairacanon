#include "Grenade.hpp"

class GrenadesManager
{
	public :

		GrenadesManager();

		void initGrenadesManger(int numlevel, sf::Sprite s);
		void addGrenade(Grenade g);


	protected :

		std::vector<Grenade> grenades;

};


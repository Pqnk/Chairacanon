#include "Grenade.hpp"
#include "Player.hpp"

class GrenadesManager
{
	public :

		GrenadesManager();

		void initGrenadesManger(int numlevel, sf::Sprite s);
		void addGrenade(Grenade g);
		void drawGrenade(sf::RenderTarget& window);
		void updateGrenades(Player& player);
		void eraseGrenades();


	protected :

		std::vector<Grenade> grenades;
		sf::Vector2f grenadePosRelToPlayer;
};


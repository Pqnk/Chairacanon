#include "Grenade.hpp"
#include "Player.hpp"

class GrenadesManager
{
	public :

		GrenadesManager();

		//######################################################
		//	Managing the STOCKS of grenade (the collectibles)
		//######################################################
		void initGrenadeStocksManager(int numlevel, sf::Sprite s);
		void addGrenadeStocks(GrenadeStock gs);
		void drawGrenadeStocks(sf::RenderTarget& window);
		void updateGrenadeStocks(Player& player);
		void eraseGrenadeStocks();

		//######################################################
		//	Managing the GRENADES THROWED
		//######################################################
		void addGrenadeThrowed(sf::Sprite s, Player& player, sf::Vector2f dir);
		void updateGrenadesThrowed();
		void eraseGrenadesThrowed();
		void drawGrenadesThrowed(sf::RenderTarget& window);


	protected :

		std::vector<GrenadeStock> grenadeStocks;
		sf::Vector2f grenadePosRelToPlayer;

		std::vector<Grenade> grenadeThrowed;
};


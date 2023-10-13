#include "Rocket.hpp"
#include "Player.hpp"

class RocketsManager
{
	public :

		RocketsManager();

		//######################################################
		//	Managing the STOCKS of grenade (the collectibles)
		//######################################################
		void initRocketStocksManager(int numlevel, sf::Sprite s);
		void addRocketStocks(RocketStock gs);
		void drawRocketStocks(sf::RenderTarget& window);
		void updateRocketStocks(Player& player);
		void eraseRocketStocks();

		//######################################################
		//	Managing the GRENADES THROWED
		//######################################################
		void addRocketThrowed(sf::Sprite s, Player& player, sf::Vector2f dir);
		void updateRocketsThrowed(sf::Image maskLevel);
		void eraseRocketsThrowed();
		void drawRocketsThrowed(sf::RenderTarget& window);

		std::vector<Rocket> rocketsThrowed;


	protected :

		std::vector<RocketStock> rocketStocks;
		sf::Vector2f rocketPosRelToPlayer;


};


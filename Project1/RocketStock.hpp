#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>

class RocketStock
{
	public : 

		RocketStock();
		RocketStock(sf::Sprite s);

		bool isPickedUp;
		int amunition;
		sf::Sprite spriteRocket;
		sf::IntRect frameRocket;
};


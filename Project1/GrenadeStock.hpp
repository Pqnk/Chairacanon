#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>

class GrenadeStock
{
	public : 

		GrenadeStock();
		GrenadeStock(sf::Sprite s);

		bool isPickedUp;
		int amunition;
		sf::Sprite grenadeSprite;
		sf::IntRect grenadeFrame;
};


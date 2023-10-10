#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>

class Grenade
{
	public : 

		Grenade(sf::Sprite s);

		int amunition;
		int grenadeDamage;

		sf::Sprite grenadeSprite;
		sf::IntRect grenadeFrame;

		bool isPickedUp;
};


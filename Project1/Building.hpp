#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>

class Building
{
	public : 

		Building(sf::Sprite s, sf::Vector2f position);

		void animationBuilding();

		sf::Sprite spriteBuilding;
		sf::IntRect frameBuilding;

		sf::Clock buildingAnimationTimer;

		bool isHitByRocket;


};


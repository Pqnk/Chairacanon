#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include "RocketsManager.hpp"

class Tank
{
	public : 

		Tank(sf::Sprite s, sf::Vector2f position);

		void destroyingTanks();

		void updatingTanks(std::vector<Rocket>& gre);

		sf::Sprite spriteTank;
		sf::IntRect frameTank;

		sf::Clock tankAnimationTimer;

		bool isHitByRocket;

};


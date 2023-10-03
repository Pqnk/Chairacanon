#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class StillObject
{
	public:

		StillObject();
		~StillObject();

		//###########################
		//	Initialisation
		//###########################
		void initStillObject(std::string path);

		//###########################
		//	Render
		//###########################
		void renderStillObject(sf::RenderTarget& target);

		//###########################
		//	Accessors
		//###########################
		sf::Sprite getSprite();

	protected:

		sf::Texture texture;
		sf::Sprite	sprite;
};


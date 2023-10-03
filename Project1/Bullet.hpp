#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Bullet
{
	public :

		Bullet(sf::Vector2f pos, sf::Vector2f dir);

		sf::RectangleShape bulletShape;

		sf::Texture texturebullet;
		sf::Sprite spriteBullet;
		sf::IntRect frameBullet;

		sf::Vector2f direction;
		sf::Vector2f position;

		void updateBullet();

		sf::Clock bulletTimer;
};


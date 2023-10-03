#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Level.hpp"
#include "AnimatedObject.hpp"

#ifndef DEF_CHARACTER
#define DEF_CHARACTER

class Character : public AnimatedObject
{
	public :

		Character();
		~Character();

		int getHealth();
		sf::Vector2f getVelocity();
		sf::Vector2f getScale();

		void setscale(sf::Vector2f newScale);
		void setVelocity(sf::Vector2f velocity);

		void damageHealth(int damage);

	protected :
		int health;
		sf::Vector2f scale;
		sf::Vector2f velocitySprite;
};

#endif


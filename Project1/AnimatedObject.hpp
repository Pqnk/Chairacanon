#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#ifndef DEF_ANIMATEDOBJECT
#define DEF_ANIMATEDOBJECT

class AnimatedObject
{
	public: 

		AnimatedObject();
		~AnimatedObject();

		//###########################
		//	Initialisation
		//###########################
		void initAnimationTimer();
		void initSprite(std::string path, sf::Vector2f scale, sf::Vector2f position, sf::Vector2f origin);

		//###########################
		//	Render
		//###########################
		void renderObject(sf::RenderTarget& target);

		//###########################
		//	Accessors
		//###########################
		sf::Sprite getSprite();
		sf::IntRect getFrameSprite();
		sf::IntRect getCurrentFrameSprite();
		sf::Vector2f getSpritePosition();
		sf::Vector2f getSpriteOrigin();
		sf::Clock getAnimationTimer();

		//###########################
		//	Setters
		//###########################
		void setSpritePosition(sf::Vector2f newPosition);


	protected : 

		sf::Clock animationTimer;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::IntRect frameSprite;
		sf::IntRect currentFrameSprite;
		std::string pathSprite;
};

#endif


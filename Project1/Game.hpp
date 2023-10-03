#pragma once

#include <iostream>
#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.hpp"
#include "AnimatedObject.hpp"
#include "Character.hpp"
#include "Cursor.hpp"
#include "Level.hpp"
#include "Camera.hpp"
#include "StillObject.hpp"
#include "LateralScreen.hpp"

#include "BulletManager.hpp"
#include "Bullet.hpp"
#include "SpriteManager.hpp"
#include "LevelManager.hpp"

#ifndef DEF_GAME
#define DEF_GAME

/*
	Class acting like the game engine
	Wrapper class
*/

class Game
{
	public:

		Game();
		virtual ~Game();

		//##############################
		//	Game Functions
		//##############################
		void update();
		void render();
		void pollEvents();
		bool getEndGame();
		const bool running() const;

	private:

		//##############################
		//	Private Game Functions
		//##############################
		void initVariables();
		void initWindow();

		//##############################
		//	Variables
		//##############################
		sf::RenderWindow* gameWindow;
		sf::VideoMode videoMode;
		sf::Event event;
		bool endGame;

		//##############################
		//	Game Objects
		//##############################
		Camera camera;
		Cursor cursor;
		Player player;
		Level level_01;
		LateralScreen latScreen;
		BulletManager bulletmanager;
		SpriteManager spriteManager;
		LevelManager levelManager;
};
#endif


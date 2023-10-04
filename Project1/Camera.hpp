#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Cursor.hpp"
#include "Level.hpp"
#include "Player.hpp"

class Camera
{
	public :

		Camera();
		~Camera();

		//##########################
		//	Init. & Update of Camera
		//##########################
		void initCameraView(sf::RenderTarget& target);
		void updateCamera(Level& map, Cursor& cursor, Player& player, sf::RenderTarget& window);

		//##########################
		//	Camera behavior
		//##########################
		void isCameraAtMapBorder(Level& map);
		void isPlayerAtCameraBorder(Player& player);
		void cursorAtCameraBorder(Cursor& cursor, sf::RenderTarget& window);
		void playerAtCameraBorder(Player& player);

		//##########################
		//	Accessors
		//##########################
		sf::View getCameraView();

	private :

		sf::View cameraView;
		float marginForCursor;
		float marginForPlayer;
		float marginForPlayerReposition;
		float velocityCamera;

		bool isViewAtMapTop;
		bool isViewAtMapLeft;
		bool isViewAtMapRight;
		bool isViewAtMapBottom;

		bool isPlayerAtMapTop;
		bool isPlayerAtMapLeft;
		bool isPlayerAtMapRight;
		bool isPlayerAtMapBottom;

		float leftLimiteView;
		float rightLimiteView;
		float topLimiteView;
		float bottomLimiteView;

		float leftLimiteMap;
		float rightLimiteMap;
		float topLimiteMap;
		float bottomLimiteMap;

		float offset;
};


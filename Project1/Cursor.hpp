#pragma once
#include "AnimatedObject.hpp"
#include "Player.hpp"
#include "Level.hpp"

#ifndef DEF_CURSOR
#define DEF_CURSOR

class Cursor : public AnimatedObject
{
	public :

		Cursor();
		~Cursor();

		//##########################
		//	Init. & Update of Cursor
		//##########################
		void initCursor();
		void updateCursor(sf::RenderWindow* gameWindow);

		//##########################
		//	Animations of Cursor
		//##########################
		void cursorAnimationOnClick();

		//##########################
		//	Accessors
		//##########################
		bool getIsClicking();
		bool getIsFirstFrame();
		sf::Vector2f getClickDirection();
		sf::Vector2f getLastClickPosition();
		sf::Vector2f getPosCursorOnWorld();
		sf::Vector2i getPosCursorOnGameWindow();
		sf::Vector2f getPosCursorOnCameraView();
		sf::Vector2f getRightClickPosition();

		//##########################
		//	Setters
		//##########################
		void setCursorPosition(sf::Vector2f position);
		void setClickDirection(sf::Vector2f playerVelocity, sf::Vector2f playerPosition);
		void setIsFirstFrame(bool b);
		void setIsClicking(bool b);
		void setIsClickingRight(bool b);
		void setPosCursorOnCameraView(sf::Vector2f position);
		void setRightClickPosition(sf::Vector2f c);


	private :

		bool isClicking;
		bool isClickingRight;
		bool isFirstFrame;

		sf::Vector2f posCursorOnWorld;
		sf::Vector2i posCursorOnGameWindow;
		sf::Vector2f posCursorOnCameraView;

		sf::Vector2f clickPosition;
		sf::Vector2f clickDirection;

		sf::Vector2f rightClickPosition;
};

#endif


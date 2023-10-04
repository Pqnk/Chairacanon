#pragma once

#include "Character.hpp"

#ifndef DEF_PLAYER
#define DEF_PLAYER

class Player : public Character
{
	public :

		Player();
		~Player();

		//##########################
		//	Init. & Update of the P.
		//##########################
		void initPlayer(sf::Sprite characterSprite);
		void updatePlayer(sf::Vector2f cursorPos, sf::Vector2f clickDir, sf::Vector2f rightClic, sf::Image maskLevel);

		//##########################
		//	Animation & Deplacement
		//##########################
		void movePlayer(sf::Vector2f target);
		void playerAnimation(sf::Vector2f cursorPos, sf::Vector2f rightClic);

		//##########################
		//	Collision Detection (Color)
		//##########################
		void collisionDetection(sf::Image maskLevel);

		//##########################
		//	Accessors
		//##########################
		bool getIsMoving();
		bool getIsShooting();

		//##########################
		//	Setters
		//##########################
		void setIsMoving(bool b);
		void setIsShooting(bool b);
		void setIsDead(bool b);


	protected :

		bool isMoving;
		bool isShooting;
		bool isDead;
};

#endif

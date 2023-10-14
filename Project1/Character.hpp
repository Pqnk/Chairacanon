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

		//##########################
		//	Accessors
		//##########################
		int getHealth();
		int getNumGrenades();
		sf::Vector2f getVelocity();
		sf::Vector2f getScale();

		bool getIsDead();
		bool getIsMoving();
		bool getIsShooting();
		bool getCanShoot();

		//##########################
		//	Setters
		//##########################
		void setscale(sf::Vector2f newScale);
		void setVelocity(sf::Vector2f velocity);
		void setIsDead(bool b);
		void setIsMoving(bool b);
		void setIsShooting(bool b);
		void setCanShoot(bool b);

		void setNumGrenades(int n);

		//##########################
		//	Dammage manager
		//##########################
		void damageHealth(int damage);

		void updateSpriteColor();

		bool isFirstDamage;
		sf::Clock damageTimer;
		sf::SoundBuffer bufferDamage;
		sf::Sound soundDamage;

	protected :

		int health;
		int numGrenades;
		sf::Vector2f scale;
		sf::Vector2f velocitySprite;

		bool isDead;
		bool isMoving;
		bool isShooting;
		bool isBlocked;
		bool canShoot;

		bool isFirstFrame;
		bool isGettingDamage;



};

#endif


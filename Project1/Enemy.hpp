#include "Character.hpp"

class Enemy : public Character
{
	public:

		Enemy();
		~Enemy();

		//##########################
		//	Init. & Update of Enemy
		//##########################
		void initEnemy(sf::Sprite &characterSprite);
		void updateEnemy(sf::Vector2f &playerPos);

		//##########################
		//	Animation
		//##########################
		void enemyAnimation();
		void enemyDetectingPlayer(sf::Vector2f &playerPos);

		//##########################
		//	Accessors
		//##########################
		void setPlayerDetected(bool b);

		//##########################
		//	Accessors
		//##########################
		bool getPlayerDetected();

	protected :

		bool playerDetected;

		sf::Vector2f playerPosRelativToEnemy;
};


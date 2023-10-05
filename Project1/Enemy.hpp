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
		void updateEnemy();

		//##########################
		//	Animation
		//##########################
		void enemyAnimation();
		void enemyDetectingPlayer();
};


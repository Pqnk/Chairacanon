#include "Character.hpp"
#include "Player.hpp"
 
using namespace std;

class Enemy : public Character
{
	public:

		Enemy();
		~Enemy();

		//##########################
		//	Init. & Update of Enemy
		//##########################
		void initEnemy(sf::Sprite &characterSprite);
		//void updateEnemy(sf::Vector2f &playerPos, sf::Image& maskLevel);
		void updateEnemy(Player &player, sf::Image& maskLevel);

		//##########################
		//	Animation
		//##########################
		void enemyAnimation();
		void enemyDeathAnimation();
		void enemyDetectingPlayer(sf::Vector2f &playerPos);
		void collisionDetection(sf::Image& maskLevel, sf::Vector2f& direction);

		//##########################
		//	Setters
		//##########################
		void setPlayerDetected(bool b);

		//##########################
		//	Accessors
		//##########################
		bool getPlayerDetected();
		bool getWaitinForErase();

	protected :

		bool playerDetected;
		sf::Vector2f playerPosRelativToEnemy;
		bool waitingForErase;
};


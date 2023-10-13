#include "RocketStock.hpp"

class Rocket : public RocketStock
{
	public :

		Rocket();
		Rocket(sf::Sprite s, sf::Vector2f playerPos, sf::Vector2f dir);

		sf::Vector2f position;
		sf::Vector2f direction;
		float rocketSpeed;

		sf::Clock rocketTimer;
		sf::Clock rocketAnimationTimer;

		void updateRocket(sf::Image maskLevel);
		void animationRocket();
		void collisionDetection(sf::Image maskLevel);
		void resetAnimExplosion();

		bool hasHitTarget;
		bool explosion;
};


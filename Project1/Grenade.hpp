#include "GrenadeStock.hpp"

class Grenade : public GrenadeStock
{
	public :

		Grenade();
		Grenade(sf::Sprite s, sf::Vector2f playerPos, sf::Vector2f dir);

		sf::Vector2f position;
		sf::Vector2f direction;
		float grenadeSpeed;

		sf::Clock grenadeTimer;
		sf::Clock grenadeAnimationTimer;

		void updateGrenade(sf::Image maskLevel);
		void animationGrenade();
		void collisionDetection(sf::Image maskLevel);
		void resetAnimExplosion();

		bool hasHitTarget;
		bool explosion;
};


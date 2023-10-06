#include "Character.hpp"

Character::Character() : health(0), scale(1.f,1.f), isDead(false), isMoving(false), isShooting(false), canShoot(true), isBlocked(false)
{
}

Character::~Character()
{
}


//##################################################
// Accessors
//##################################################
int Character::getHealth()
{
	return health;
}

sf::Vector2f Character::getVelocity()
{
	return velocitySprite;
}

sf::Vector2f Character::getScale()
{
	return scale;
}

bool Character::getIsDead()
{
	return isDead;
}

bool Character::getIsMoving()
{
	return isMoving;
}

bool Character::getIsShooting()
{
	return isShooting;
}

bool Character::getCanShoot()
{
	return canShoot;
}


//##################################################
//	Setters
//##################################################
void Character::setscale(sf::Vector2f newScale)
{
	scale = newScale;
}

void Character::setVelocity(sf::Vector2f velocity)
{
	velocitySprite = velocity;
}

void Character::setIsDead(bool b)
{
	isDead = b;
}

void Character::setIsMoving(bool b)
{
	isMoving = b;
}

void Character::setIsShooting(bool b)
{
	isShooting = b;
}

void Character::setCanShoot(bool b)
{
	canShoot = b;
}


//##################################################
//	Update Attributes
//##################################################
void Character::damageHealth(int damage)
{
	health -= damage;

	if (health <= 0)
	{
		isDead = true;
	}
}

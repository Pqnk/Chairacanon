#include "Character.hpp"

Character::Character() : health(0), scale(1.f,1.f), isDead(false), isMoving(false), isShooting(false), canShoot(true), isBlocked(false), isFirstFrame(true), numGrenades(0), isFirstDamage(false), isGettingDamage(false)
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

int Character::getNumGrenades()
{
	return numGrenades;
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

void Character::setNumGrenades(int n)
{
	numGrenades = n;
}


//##################################################
//	Update Attributes
//##################################################
void Character::damageHealth(int damage)
{
	soundDamage.play();
	soundDamage.setPlayingOffset(sf::seconds(0.5));

	isGettingDamage = true;
	if (isFirstDamage == false)
	{
		isFirstDamage = true;
		damageTimer.restart();
	}

	health -= damage;

	if (health <= 0)
	{
		isDead = true;
	}

}

void Character::updateSpriteColor()
{
	if (isGettingDamage == true && damageTimer.getElapsedTime().asSeconds() <= 0.5f)
	{
		sprite.setColor(sf::Color::Red);
	}
	else
	{
		sprite.setColor(sf::Color::White);
		isFirstDamage = false;
		isGettingDamage = false;
	}

}

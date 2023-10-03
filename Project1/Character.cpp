#include "Character.hpp"

Character::Character() : health(0), scale(1.f,1.f)
{
}

Character::~Character()
{
}

//##################################################
//	Update Attributes
//##################################################
void Character::damageHealth(int damage)
{
	health -= damage;
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
#include "AnimatedObject.hpp"

AnimatedObject::AnimatedObject() : frameSprite(0.f,0.f,0.f,0.f)
{
}

AnimatedObject::~AnimatedObject()
{
}

//##################################################
// Initialisation
//##################################################
void AnimatedObject::initAnimationTimer()
{
	animationTimer.restart();
}

void AnimatedObject::initSprite(std::string path, sf::Vector2f scale, sf::Vector2f position, sf::Vector2f origin)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setTextureRect(frameSprite);
	sprite.setScale(scale.x, scale.y);
	sprite.setPosition(position.x, position.y);
	sprite.setOrigin(origin.x, origin.y);
}


//##################################################
// Render
//##################################################
void AnimatedObject::renderObject(sf::RenderTarget& target)
{
	/*
	*	@return void
	*	Draw the sprite of the game object on the game window.
	*/

	target.draw(sprite);
}


//##################################################
// Accessors
//##################################################
sf::Sprite AnimatedObject::getSprite()
{
	return sprite;
}

sf::IntRect AnimatedObject::getFrameSprite()
{
	return frameSprite;
}

sf::IntRect AnimatedObject::getCurrentFrameSprite()
{
	return currentFrameSprite;
}

sf::Vector2f AnimatedObject::getSpritePosition()
{
	return sprite.getPosition();
}

sf::Vector2f AnimatedObject::getSpriteOrigin()
{
	return sprite.getOrigin();
}

sf::Clock AnimatedObject::getAnimationTimer()
{
	return animationTimer;
}

//##################################################
// Setters
//##################################################
void AnimatedObject::setSpritePosition(sf::Vector2f newPosition)
{
	sprite.setPosition(newPosition);
}

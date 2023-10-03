#include "StillObject.hpp"

StillObject::StillObject()
{
}

StillObject::~StillObject()
{
}

//###########################
//	Initialisation
//###########################
void StillObject::initStillObject(std::string path)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}


//#######################################################################################################
//	Render
//#######################################################################################################
void StillObject::renderStillObject(sf::RenderTarget& target)
{
	target.draw(sprite);
}


//#######################################################################################################
//	Accessors
//#######################################################################################################
sf::Sprite StillObject::getSprite()
{
	return sprite;
}

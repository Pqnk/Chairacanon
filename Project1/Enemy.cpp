#include "Enemy.hpp"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}


//#######################################################################################################
//	Initialisation & Update of Enemy
//#######################################################################################################
void Enemy::initEnemy(sf::Sprite &characterSprite)
{
	sf::Vector2f position(600.f, 500.f);
	sf::Vector2f origin(32.f, 50.f);
	sf::Vector2f speed(1.f, 1.f);

	health = 10;

	scale.x = 0.5f;
	scale.y = 0.5f;

	frameSprite.left = 0.f;
	frameSprite.top = 1280.f;
	frameSprite.width = 64.f;
	frameSprite.height = 64.f;

	currentFrameSprite.left = 0.f;
	currentFrameSprite.top = 1280.f;
	currentFrameSprite.width = 64.f;
	currentFrameSprite.height = 64.f;

	//	Sprite from the SpriteManager class
	sprite = characterSprite;

	sprite.setTextureRect(frameSprite);
	sprite.setOrigin(origin);
	sprite.setPosition(position);
	sprite.setScale(scale);

	setVelocity(speed);
}

void Enemy::updateEnemy()
{
	enemyAnimation();
}


//#######################################################################################################
//	Updating Animation & Deplacement of the Enemy
//#######################################################################################################
void Enemy::enemyAnimation()
{
	if (animationTimer.getElapsedTime().asSeconds() >= 0.1f)
	{
		//	/////////////////////////////////////////
		//	Idle animation
		if (isMoving == false && isDead == false && isShooting == false)
		{
			currentFrameSprite.top = 1280.f;
			currentFrameSprite.left += 64.f;

			if (currentFrameSprite.left >= 512.f)
			{
				currentFrameSprite.left = 0.f;
				animationTimer.restart();
			}
		}
		animationTimer.restart();
		sprite.setTextureRect(currentFrameSprite);
	}
}

void Enemy::enemyDetectingPlayer()
{

}

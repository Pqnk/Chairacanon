#include "Enemy.hpp"

Enemy::Enemy() : playerDetected(false), waitingForErase(false)
{
	isDead = false;
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
	sf::Vector2f speed(0.5f, 0.5f);

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

void Enemy::updateEnemy(sf::Vector2f &playerPos, sf::Image& maskLevel)
{

	if (isDead == true)
	{
		enemyDeathAnimation();
	}
	else 
	{
		enemyAnimation();
		enemyDetectingPlayer(playerPos);

		if (playerDetected == true)
		{
			sf::Vector2f direction = playerPosRelativToEnemy;
			float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

			if (length != 0)
			{
				direction /= length;
			}

			direction.x *= getVelocity().x;
			direction.y *= getVelocity().y;

			float threshold = 15.f;

			//	Cheking if the position is near the destination
			if (length <= threshold or isBlocked == true)
			{
				setSpritePosition(sprite.getPosition());
				isBlocked = false;
			}
			else
			{
				sprite.move(direction);
			}

			collisionDetection(maskLevel, direction);
		}
	}
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
		if (playerDetected == false && isDead == false)
		{
			currentFrameSprite.top = 1280.f;
			currentFrameSprite.left += 64.f;
			if (currentFrameSprite.left >= 512)
			{
				currentFrameSprite.left = 0.f;
				animationTimer.restart();
			}
		}
		
		//	/////////////////////////////////////////
		//	Attack animation
		if (playerDetected == true && isDead == false)
		{
			currentFrameSprite.top = 1344.f;
			currentFrameSprite.left += 64.f;
			if (currentFrameSprite.left >= 768.f)
			{
				currentFrameSprite.left = 0.f;
				animationTimer.restart();			
			}
		}

		animationTimer.restart();
		sprite.setTextureRect(currentFrameSprite);
	}
}

void Enemy::enemyDeathAnimation()
{
	if (animationTimer.getElapsedTime().asSeconds() >= 0.1f)
	{
		currentFrameSprite.top = 1472.f;
		currentFrameSprite.left += 64.f;
		if (currentFrameSprite.left >= 768.f)
		{
			waitingForErase = true;
		}
		animationTimer.restart();
		sprite.setTextureRect(currentFrameSprite);
	}
}

void Enemy::enemyDetectingPlayer(sf::Vector2f &playerPos)
{
	playerPosRelativToEnemy = playerPos - sprite.getPosition();

	if (	playerPosRelativToEnemy.x > -100 
		and playerPosRelativToEnemy.x < 100 
		and playerPosRelativToEnemy.y > -100 
		and playerPosRelativToEnemy.y < 100
		)
	{
		playerDetected = true;
	}
	else
	{
		playerDetected = false;
	}
}

void Enemy::collisionDetection(sf::Image& maskLevel, sf::Vector2f& direction)
{
	sf::Vector2f newSpeed;
	int pixelColored = maskLevel.getPixel(sprite.getPosition().x, sprite.getPosition().y).toInteger();
	int pixelColOffset = maskLevel.getPixel(sprite.getPosition().x + 10.f * direction.x, sprite.getPosition().y + 10.f * direction.y).toInteger();

	switch (pixelColored)
	{
		//	GREEN
	case 16711935:
		newSpeed = sf::Vector2f(0.5f, 0.5f);
		setVelocity(newSpeed);
		canShoot = true;
		break;

		//	PINK
	case 4278255615:
		newSpeed = sf::Vector2f(0.2f, 0.2f);
		setVelocity(newSpeed);
		canShoot = true;
		break;

		//	BLUE
	default:
		newSpeed = sf::Vector2f(0.2f, 0.2f);
		setVelocity(newSpeed);
		canShoot = false;
		break;
	}

	switch (pixelColOffset)
	{
		//	BLACK
	case 255:
		isBlocked = true;
		break;
	}
}


//#######################################################################################################
//	Setters
//#######################################################################################################
void Enemy::setPlayerDetected(bool b)
{
	playerDetected = b;
}


//#######################################################################################################
//	Accessors
//#######################################################################################################
bool Enemy::getPlayerDetected()
{
	return playerDetected;
}

bool Enemy::getWaitinForErase()
{
	return waitingForErase;
}


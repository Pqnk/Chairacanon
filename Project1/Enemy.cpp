#include "Enemy.hpp"

Enemy::Enemy() : playerDetected(false), waitingForErase(false), isNotFirstFrame(false)
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
	ploufen = false;

	bufferDamageEn.loadFromFile("Sounds/Damage_Enemy.wav");
	soundDamageEn.setBuffer(bufferDamageEn);

	sf::Vector2f position(600.f, 500.f);
	sf::Vector2f origin(32.f, 50.f);
	sf::Vector2f speed(0.5f, 0.5f);

	health = 10;

	scale.x = 0.5f;
	scale.y = 0.5f;

	frameSprite.left = 0.f;
	//frameSprite.top = 1280.f;
	frameSprite.top = 0.f;
	frameSprite.width = 64.f;
	frameSprite.height = 64.f;

	currentFrameSprite.left = 0.f;
	//currentFrameSprite.top = 1280.f;
	frameSprite.top = 0.f;
	currentFrameSprite.width = 64.f;
	currentFrameSprite.height = 64.f;

	//	Sprite from the SpriteManager class
	sprite = characterSprite;

	sprite.setTextureRect(frameSprite);
	sprite.setOrigin(origin);
	sprite.setPosition(position);
	sprite.setScale(scale);

	//sprite.setColor(sf::Color::Green);

	setVelocity(speed);
}

void Enemy::updateEnemy(Player &player, sf::Image& maskLevel)
{

	sf::Vector2f playerPos = player.getSpritePosition();

	if (isDead == true)
	{
		soundDamageEn.play();
		if (isNotFirstFrame == false)
		{
			currentFrameSprite.left = 0.f;
			sprite.setTextureRect(currentFrameSprite);
			isNotFirstFrame = true;
		}
		enemyDeathAnimation();
	}
	else
	{
		enemyAnimation();
		enemyDetectingPlayer(playerPos);

		if (playerDetected == true)
		{
			direction = playerPosRelativToEnemy;
			float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

			if (length != 0)
			{
				direction /= length;
			}

			direction.x *= getVelocity().x;
			direction.y *= getVelocity().y;

			float threshold = 15.f;

			//	Cheking if the ENEMY arrived at the PLAYER
			if (length <= threshold)
			{
				setSpritePosition(sprite.getPosition());

				//	If so, the ENEMY is DEAD and ah damaged the PLAYER
				player.damageHealth(5);
				isDead = true;
			}
			else
			{
				if (isBlocked == true)
				{
					setSpritePosition(sprite.getPosition());
					isBlocked = false;
				}
				else
				{
					sprite.move(direction);
				}
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
			//currentFrameSprite.top = 1280.f;
			//currentFrameSprite.left += 64.f;
			//if (currentFrameSprite.left >= 512)
			//{
			//	currentFrameSprite.left = 0.f;
			//	animationTimer.restart();
			//}

			currentFrameSprite.top = 0.f;
			currentFrameSprite.left += 64.f;
			if (currentFrameSprite.left >= 768.f)
			{
				currentFrameSprite.left = 0.f;
				animationTimer.restart();
			}

		}
		
		//	/////////////////////////////////////////
		//	Moving animation
		if (playerDetected == true && isDead == false)
		{
			//	//////////////////////////
			//	Player Sprite Going : UP
			if (direction.x > -30 && direction.x < 30 && direction.y < 0)
			{
				currentFrameSprite.top = 65.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 1024.f)
				{
					currentFrameSprite.left = 0.f;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Going : DOWN
			if (direction.x > -30 && direction.x < 30 && direction.y > 0)
			{
				currentFrameSprite.top = 512.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 1024.f)
				{
					currentFrameSprite.left = 0.f;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Going : LEFT
			if (direction.x < 0 && direction.y < 30 && direction.y > -30)
			{
				currentFrameSprite.top = 384.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 1024.f)
				{
					currentFrameSprite.left = 0.f;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Going : RIGHT
			if (direction.x > 0 && direction.y < 30 && direction.y > -30)
			{
				currentFrameSprite.top = 192.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 1024.f)
				{
					currentFrameSprite.left = 0.f;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Going : UP RIGHT
			if (direction.x > 0 && direction.x > 30 && direction.y < -30)
			{
				currentFrameSprite.top = 128.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 1024.f)
				{
					currentFrameSprite.left = 0.f;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Going : UP LEFT
			if (direction.x < 0 && direction.x < -30 && direction.y < -30)
			{
				currentFrameSprite.top = 320.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 1024.f)
				{
					currentFrameSprite.left = 0.f;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Going : DOWN RIGHT
			if (direction.y > 0 && direction.x > 30 && direction.y > 30)
			{
				currentFrameSprite.top = 256.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 1024.f)
				{
					currentFrameSprite.left = 0.f;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Going : DOWN LEFT
			if (direction.y > 0 && direction.x < -30 && direction.y > 30)
			{
				currentFrameSprite.top = 448.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 1024.f)
				{
					currentFrameSprite.left = 0.f;
					animationTimer.restart();
				}
			}

			//currentFrameSprite.top = 1344.f;
			//currentFrameSprite.left += 64.f;
			//if (currentFrameSprite.left >= 768.f)
			//{
			//	currentFrameSprite.left = 0.f;
			//	animationTimer.restart();			
			//}
		}

		//	/////////////////////////////////////////
		//	Plouf animation
		if (ploufen == true)
		{
			currentFrameSprite.top = 1152.f;
			currentFrameSprite.left += 64.f;
			if (currentFrameSprite.left >= 256.f)
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
	soundDamageEn.play();

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
		ploufen = false;
		break;

		//	PINK
	case 4278255615:
		newSpeed = sf::Vector2f(0.2f, 0.2f);
		setVelocity(newSpeed);
		canShoot = true;
		ploufen = false;
		break;

		//	BLUE
	default:
		newSpeed = sf::Vector2f(0.2f, 0.2f);
		setVelocity(newSpeed);
		canShoot = false;
		ploufen = true;
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


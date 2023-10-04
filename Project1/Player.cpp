#include "Player.hpp"

//#######################################################################################################
//	Constructor / Destructor
//#######################################################################################################
Player::Player() : isMoving(false), isShooting(false), isDead(false)
{
}

Player::~Player()
{
}


//#######################################################################################################
//	Initialisation & Update of the Player
//#######################################################################################################
void Player::initPlayer(sf::Sprite characterSprite)
{
	sf::Vector2f position(500.f, 600.f);
	sf::Vector2f origin(32.f, 50.f);
	sf::Vector2f speed(0.7f, 0.7f);

	health = 50;

	scale.x = 0.5f;
	scale.y = 0.5f;

	frameSprite.left = 0.f;
	frameSprite.top = 0.f;
	frameSprite.width = 64.f;
	frameSprite.height = 64.f;

	currentFrameSprite.left = 0.f;
	currentFrameSprite.top = 0.f;
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

void Player::updatePlayer(sf::Vector2f cursorPos, sf::Vector2f clickDir, sf::Vector2f rightClic)
{
	/**
	@return void

	Calculate the distance between the position of the lact click and the sprite.
	- if it is inferior to 5 pixel, the sprite stop at its last position
	- if not, the sprite moves toward the last click position
	*/

	if (health > 0)
	{
		sf::Vector2f spritePos;
		spritePos.x = getSpritePosition().x;
		spritePos.y = getSpritePosition().y;

		playerAnimation(cursorPos, rightClic);

		float distance = std::sqrt(std::pow(spritePos.x - cursorPos.x, 2) + std::pow(spritePos.y - cursorPos.y, 2));

		float threshold = 5.f;

		//	Cheking if the position is near the clickPosition
		if (distance <= threshold)
		{
			setSpritePosition(spritePos);
			setIsMoving(false);
		}
		else
		{
			movePlayer(clickDir);
			setIsShooting(false);
		}
	}
	else
	{
		isDead = true;
	}
}


//#######################################################################################################
//	Animation & Deplacement of the Player
//#######################################################################################################
void Player::movePlayer(sf::Vector2f target)
{
	sf::Vector2f newP;
	newP.x = getSpritePosition().x + target.x;
	newP.y = getSpritePosition().y + target.y;
	setSpritePosition(newP);
}

void Player::playerAnimation(sf::Vector2f cursorPos, sf::Vector2f rightClic)
{
	//	Left Click relative to the character
	sf::Vector2f dir;
	dir.x = cursorPos.x - getSpritePosition().x;
	dir.y = cursorPos.y - getSpritePosition().y;

	//	Right Click relative to the character
	sf::Vector2f rightDir;
	rightDir.x = rightClic.x - getSpritePosition().x;
	rightDir.y = rightClic.y - getSpritePosition().y;

	if (animationTimer.getElapsedTime().asSeconds() >= 0.1f)
	{
		//	/////////////////////////////////////////
		//	Idle animation
		if (isMoving == false && isDead == false && isShooting == false) 
		{
			currentFrameSprite.top = 0.f;
			currentFrameSprite.left += 64.f;

			if (currentFrameSprite.left >= 768.f)
			{
				currentFrameSprite.left = 0.f;
				animationTimer.restart();
			}
		}

		//	/////////////////////////////////////////
		//	Walking animation
		if (isMoving == true && isShooting == false)
		{
			//	//////////////////////////
			//	Player Sprite Going : UP
			if (dir.x > -30 && dir.x < 30 && dir.y < 0)
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
			if (dir.x > -30 && dir.x < 30 && dir.y > 0)
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
			if (dir.x < 0 && dir.y < 30 && dir.y > -30)
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
			if (dir.x > 0 && dir.y < 30 && dir.y > -30)
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
			if (dir.x > 0 && dir.x > 30 && dir.y < -30)
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
			if (dir.x < 0 && dir.x < -30 && dir.y < -30)
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
			if (dir.y > 0 && dir.x > 30 && dir.y > 30)
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
			if (dir.y > 0 && dir.x < -30 && dir.y > 30)
			{
				currentFrameSprite.top = 448.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 1024.f)
				{
					currentFrameSprite.left = 0.f;
					animationTimer.restart();
				}
			}
		}

		//	/////////////////////////////////////////
		//	Shooting animation
		if (isMoving == false && isShooting == true)
		{

			//	//////////////////////////
			//	Player Sprite Shooting : UP
			if (rightDir.x > -30 && rightDir.x < 30 && rightDir.y < 0)
			{
				currentFrameSprite.top = 576.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 960.f)
				{
					currentFrameSprite.left = 0.f;
					isShooting = false;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Shooting : DOWN
			if (rightDir.x > -30 && rightDir.x < 30 && rightDir.y > 0)
			{
				currentFrameSprite.top = 768.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 960.f)
				{
					currentFrameSprite.left = 0.f;
					isShooting = false;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Shooting : LEFT
			if (rightDir.x < 0 && rightDir.y < 30 && rightDir.y > -30)
			{
				currentFrameSprite.top = 832.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 960.f)
				{
					currentFrameSprite.left = 0.f;
					isShooting = false;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Shooting : RIGHT
			if (rightDir.x > 0 && rightDir.y < 30 && rightDir.y > -30)
			{
				currentFrameSprite.top = 640.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 960.f)
				{
					currentFrameSprite.left = 0.f;
					isShooting = false;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Shooting : UP RIGHT
			if (rightDir.x > 0 && rightDir.x > 30 && rightDir.y < -30)
			{
				currentFrameSprite.top = 576.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 960.f)
				{
					currentFrameSprite.left = 0.f;
					isShooting = false;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Shooting : UP LEFT
			if (rightDir.x < 0 && rightDir.x < -30 && rightDir.y < -30)
			{
				currentFrameSprite.top = 896.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 960.f)
				{
					currentFrameSprite.left = 0.f;
					isShooting = false;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Shooting : DOWN RIGHT
			if (rightDir.y > 0 && rightDir.x > 30 && rightDir.y > 30)
			{
				currentFrameSprite.top = 768.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 960.f)
				{
					currentFrameSprite.left = 0.f;
					isShooting = false;
					animationTimer.restart();
				}
			}

			//	//////////////////////////
			//	Player Sprite Shooting : DOWN LEFT
			if (rightDir.y > 0 && rightDir.x < -30 && rightDir.y > 30)
			{
				currentFrameSprite.top = 768.f;
				currentFrameSprite.left += 64.f;

				if (currentFrameSprite.left >= 960.f)
				{
					currentFrameSprite.left = 0.f;
					isShooting = false;
					animationTimer.restart();
				}
			}
		}

		//	/////////////////////////////////////////
		//	Dying Animation
		if (isMoving == false && isDead == true)
		{
			currentFrameSprite.top = 960.f;
			currentFrameSprite.left += 64.f;

			if (currentFrameSprite.left >= 1024.f)
			{
				currentFrameSprite.left = 0.f;
				animationTimer.restart();
				isDead = false;
			}
		}

		animationTimer.restart();
		sprite.setTextureRect(currentFrameSprite);
	}
}


//#######################################################################################################
//	Accessors
//#######################################################################################################
bool Player::getIsMoving()
{
	return isMoving;
}

bool Player::getIsShooting()
{
	return isShooting;
}

//#######################################################################################################
//	Setters
//#######################################################################################################
void Player::setIsMoving(bool b)
{
	isMoving = b;
}

void Player::setIsShooting(bool b)
{
	isShooting = b;
}

void Player::setIsDead(bool b)
{
	isDead = b;
}



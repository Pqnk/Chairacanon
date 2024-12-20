#include "Player.hpp"

//#######################################################################################################
//	Constructor / Destructor
//#######################################################################################################
Player::Player()
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
	//bufferDamage.loadFromFile("Sounds/Damage.mp3");
	//soundDamage.setBuffer(bufferDamage);

	isNotfirstFrame = false;
	isDead = false;
	isPlouf = false;
	//sf::Vector2f position(500.f, 600.f);
	sf::Vector2f position(660.f, 250.f);
	sf::Vector2f origin(32.f, 50.f);
	sf::Vector2f speed(1.f, 1.f);

	health = 10;
	numGrenades = 0;

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

void Player::updatePlayer(sf::Vector2f leftClic, sf::Vector2f rightClic, sf::Image maskLevel)
{
	/**
	@return void

	Calculate the distance between the position of the lact click and the sprite.
	- if it is inferior to 5 pixel, the sprite stop at its last position
	- if not, the sprite moves toward the last click position
	*/

	if (health > 0)
	{
		playerAnimation(leftClic, rightClic);

		sf::Vector2f direction = leftClic - sprite.getPosition();
		float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		
		if (length != 0)
		{
			direction /= length;
		}
		
		direction.x *= getVelocity().x;
		direction.y *= getVelocity().y;

		float threshold = 5.f;

		//	Cheking if the position is near the destination
		if (length <= threshold or isBlocked == true)
		{
			setSpritePosition(sprite.getPosition());
			setIsMoving(false);
			isBlocked = false;
		}
		else
		{
			setIsMoving(true);
			sprite.move(direction);
			setIsShooting(false);
		}

		collisionDetection(maskLevel, direction);
	}
	else
	{
		isDead = true;
	}
}


//#######################################################################################################
//	Updating the Animation & Deplacement of the Player
//#######################################################################################################
void Player::playerAnimation(sf::Vector2f leftClic, sf::Vector2f rightClic)
{
	//	Left Click relative to the character
	sf::Vector2f dir;
	dir.x = leftClic.x - getSpritePosition().x;
	dir.y = leftClic.y - getSpritePosition().y;

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
			}
		}

		//	/////////////////////////////////////////
		//	Plouf Animation
		if (isPlouf == true)
		{
			currentFrameSprite.top = 1216.f;
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

void Player::playerDeathAnimation()
{
	if (isNotfirstFrame == false)
	{
		currentFrameSprite.top = 960.f;
		currentFrameSprite.left = 0.f;
		sprite.setTextureRect(currentFrameSprite);
		animationTimer.restart();
		isNotfirstFrame = true;
	}
	else
	{
		if (animationTimer.getElapsedTime().asSeconds() >= 0.15f)
		{
			currentFrameSprite.top = 960.f;
			currentFrameSprite.left += 64.f;
			if (currentFrameSprite.left >= 1024.f)
			{
				currentFrameSprite.left = 960.f;
			}

			animationTimer.restart();
			sprite.setTextureRect(currentFrameSprite);
		}
	}
}

void Player::collisionDetection(sf::Image maskLevel, sf::Vector2f direction)
{
	sf::Vector2f newSpeed;
	int pixelColored = maskLevel.getPixel(sprite.getPosition().x, sprite.getPosition().y).toInteger();
	int pixelColOffset = maskLevel.getPixel(sprite.getPosition().x + 10.f * direction.x, sprite.getPosition().y + 10.f * direction.y).toInteger();

	switch (pixelColored)
	{
		//	GREEN
		case 16711935 :
			newSpeed = sf::Vector2f(1.f, 1.f);
			setVelocity(newSpeed);
			canShoot = true;
			isPlouf = false;
		break;

		//	PINK
		case 4278255615:
			newSpeed = sf::Vector2f(0.5f, 0.5f);
			setVelocity(newSpeed);
			canShoot = true;
			isPlouf = false;
		break;

		//	BLUE
		default :
			newSpeed = sf::Vector2f(0.5f, 0.5f);
			setVelocity(newSpeed);
			canShoot = false;
			isPlouf = true;
		break;
	}

	switch (pixelColOffset)
	{
		//	BLACK
		case 255:
			isBlocked = true;
			isPlouf = false;
		break;
	}
}
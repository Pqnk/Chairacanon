#include "Cursor.hpp"

Cursor::Cursor() : isClicking(false), isClickingRight(false), isFirstFrame(true), clickDirection(0.f,0.f)
{
}

Cursor::~Cursor()
{
}

//#######################################################################################################
//	Initialisation & Update of Cursor
//#######################################################################################################
void Cursor::initCursor()
{
	texture.loadFromFile("Textures/Cursor.png");

	sprite.setTexture(texture);

	frameSprite.left = 0;
	frameSprite.top = 0;
	frameSprite.width = 130;
	frameSprite.height = 135;

	currentFrameSprite.left = 0;
	currentFrameSprite.top = 0;
	currentFrameSprite.width = 130;
	currentFrameSprite.height = 135;

	sprite.setTextureRect(frameSprite);

	sprite.setScale(0.1f, 0.1f);
}

void Cursor::updateCursor(sf::RenderWindow* gameWindow)
{
	posCursorOnGameWindow = sf::Mouse::getPosition(*gameWindow);
	posCursorOnWorld = gameWindow->mapPixelToCoords(posCursorOnGameWindow);
	setCursorPosition(posCursorOnWorld);

	cursorAnimationOnClick();
}


//#######################################################################################################
//	Animations of Cursor
//#######################################################################################################
void Cursor::cursorAnimationOnClick()
{
	//	////////////////////////////////////////////////////
	//	Left Clicking
	if (isClicking == true && isFirstFrame == true)
	{
		currentFrameSprite.top = 0.f;
		currentFrameSprite.left = 130.f;
		sprite.setTextureRect(this->currentFrameSprite);
		isFirstFrame = false;
		isClicking = false;
		animationTimer.restart();
	}
	else
	{
		if (isClicking == false && isFirstFrame == false && animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			currentFrameSprite.left = 0.f;
			sprite.setTextureRect(currentFrameSprite);
			isFirstFrame = true;
			isClicking = false;
		}
	}

	//	////////////////////////////////////////////////////
	//	Right Clicking
	if (isClickingRight == true)
	{
		currentFrameSprite.top = 145.f;
		currentFrameSprite.left = 10.f;
		sprite.setTextureRect(this->currentFrameSprite);
		isClickingRight = false;
		animationTimer.restart();
	}
	else
	{
		if (animationTimer.getElapsedTime().asSeconds() >= 1.f)
		{
			currentFrameSprite.top = 0.f;
			sprite.setTextureRect(currentFrameSprite);
		}
	}
}


//#######################################################################################################
//	Accessors
//#######################################################################################################
bool Cursor::getIsClicking()
{
	return isClicking;
}

bool Cursor::getIsFirstFrame()
{
	return isFirstFrame;
}

sf::Vector2f Cursor::getClickDirection()
{
	return clickDirection;
}

sf::Vector2f Cursor::getLastClickPosition()
{
	return clickPosition;
}

sf::Vector2i Cursor::getPosCursorOnGameWindow()
{
	return posCursorOnGameWindow;
}

sf::Vector2f Cursor::getPosCursorOnCameraView()
{
	return posCursorOnCameraView;
}

sf::Vector2f Cursor::getRightClickPosition()
{
	return rightClickPosition;
}

sf::Vector2f Cursor::getPosCursorOnWorld()
{
	return posCursorOnWorld;
}


//#######################################################################################################
//	Setters
//#######################################################################################################
void Cursor::setIsClicking(bool b)
{
	isClicking = b;
}

void Cursor::setIsClickingRight(bool b)
{
	isClickingRight = b;
}

void Cursor::setPosCursorOnCameraView(sf::Vector2f position)
{
	posCursorOnCameraView = position;
}

void Cursor::setRightClickPosition(sf::Vector2f c)
{
	rightClickPosition = c;
}

void Cursor::setIsFirstFrame(bool b)
{
	isFirstFrame = b;
}

void Cursor::setCursorPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}


void Cursor::setClickDirection(sf::Vector2f playerVelocity, sf::Vector2f playerPosition)
{
	/*
		Get the position of the mouse when the event 'Left Click' happen.
		Then :
		-	Calculate the vector of the direction the sprite has to follow (clickDirection).
		-	Calculate the length of this vector (pythagore). And normalize the vector clickDirection dividing it by the length.
		-	Then multiply the x and y value of the vector clickDirection by the velocity of the player.
	*/

	clickPosition = posCursorOnWorld;
	clickDirection = clickPosition - playerPosition;

	float length = std::sqrt(clickDirection.x * clickDirection.x + clickDirection.y * clickDirection.y);

	if (length != 0)
	{
		clickDirection /= length; // Normalisation
	}

	clickDirection.x = playerVelocity.x * clickDirection.x;
	clickDirection.y = playerVelocity.y * clickDirection.y;
}

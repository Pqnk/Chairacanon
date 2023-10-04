#include "Camera.hpp"

Camera::Camera() : marginForCursor(150.f), marginForPlayer(120.f), marginForPlayerReposition(50.f), velocityCamera(1.7f), offset(5.f)
{
}

Camera::~Camera()
{
}


//#######################################################################################################
//	Initialisation & Update of Camera
//#######################################################################################################
void Camera::initCameraView(sf::RenderTarget& target)
{
	/*
	*	@return void
	*	-	Setting the size and the center of the camera relative to the map and window.
	*	-	Setting also the double view of the game and the lateral menu.
	*/

	cameraView.setCenter(sf::Vector2f(500.f, 600.f));
	cameraView.setSize(600, 300);
}

void Camera::updateCamera(Level& map, Cursor& cursor, Player& player, sf::RenderTarget& window)
{
	isPlayerAtCameraBorder(player);
	isCameraAtMapBorder(map);
	cursorAtCameraBorder(cursor, window);
	playerAtCameraBorder(player);
}


//#######################################################################################################
//	Camera View behavior
//#######################################################################################################
void Camera::isCameraAtMapBorder(Level& map)
{
	leftLimiteView = cameraView.getCenter().x - cameraView.getSize().x / 2;
	rightLimiteView = cameraView.getCenter().x + cameraView.getSize().x / 2;
	topLimiteView = cameraView.getCenter().y - cameraView.getSize().y / 2;
	bottomLimiteView = cameraView.getCenter().y + cameraView.getSize().y / 2;

	leftLimiteMap = map.getSpriteLevel().getGlobalBounds().left;
	rightLimiteMap = map.getSpriteLevel().getGlobalBounds().left + map.getSpriteLevel().getGlobalBounds().width;
	topLimiteMap = map.getSpriteLevel().getGlobalBounds().top;
	bottomLimiteMap = map.getSpriteLevel().getGlobalBounds().top + map.getSpriteLevel().getGlobalBounds().height;

	//	Left
	if (leftLimiteView + 150 <= leftLimiteMap + offset)
	{
		isViewAtMapLeft = true;
	}
	else
	{
		isViewAtMapLeft = false;
	}

	//	Right
	if (rightLimiteView >= rightLimiteMap - offset)
	{
		isViewAtMapRight = true;
	}
	else
	{
		isViewAtMapRight = false;
	}

	//	Top
	if (topLimiteView <= topLimiteMap + offset)
	{
		isViewAtMapTop = true;
	}
	else
	{
		isViewAtMapTop = false;
	}

	//	Bottom
	if (bottomLimiteView >= bottomLimiteMap - offset)
	{
		isViewAtMapBottom = true;
	}
	else
	{
		isViewAtMapBottom = false;
	}
}

void Camera::isPlayerAtCameraBorder(Player& player)
{
	float xSprite = player.getSpritePosition().x;
	float ySprite = player.getSpritePosition().y;

	float xCenterView = cameraView.getCenter().x + 70;
	float yCenterView = cameraView.getCenter().y;

	if (xSprite - xCenterView < - marginForPlayer - 70)
	{
		isPlayerAtMapLeft = true;
	}
	else
	{
		isPlayerAtMapLeft = false;
	}

	if (xSprite - xCenterView > marginForPlayer + 70 )
	{
		isPlayerAtMapRight = true;
	}
	else
	{
		isPlayerAtMapRight = false;
	}

	if (ySprite - yCenterView < - marginForPlayer + 20 )
	{
		isPlayerAtMapTop = true;
	}
	else
	{
		isPlayerAtMapTop = false;
	}

	if (ySprite - yCenterView > marginForPlayer + 20)
	{
		isPlayerAtMapBottom = true;
	}
	else
	{
		isPlayerAtMapBottom = false;
	}

}

void Camera::cursorAtCameraBorder(Cursor& cursor, sf::RenderTarget& window)
{
	//	///////////////////////////////////////////////////////////////////////////////////
	//	When the cursor gets close to the LEFT border of the WINDOW -> the CAMERA moves to the LEFT
	if (cursor.getPosCursorOnGameWindow().x > window.getSize().x / 4.f && cursor.getPosCursorOnGameWindow().x < window.getSize().x / 4.f + marginForCursor && isViewAtMapLeft == false)
	{
		cameraView.move(-2.f, 0.f);
	}

	//	///////////////////////////////////////////////////////////////////////////////////
	//	When the cursor gets close to the RIGHT border of the WINDOW -> the CAMERA moves to the RIGHT
	if (cursor.getPosCursorOnGameWindow().x >= window.getSize().x -  marginForCursor && isViewAtMapRight == false)
	{
		cameraView.move(2.f, 0.f);
	}

	//	///////////////////////////////////////////////////////////////////////////////////
	//	When the cursor gets close to the TOP border of the WINDOW -> the CAMERA moves to the TOP
	if ((cursor.getPosCursorOnGameWindow().y <  marginForCursor) && (cursor.getPosCursorOnGameWindow().x > window.getSize().x / 4.f) && isViewAtMapTop == false)
	{
		cameraView.move(0.f, -2.f);
	}

	//	///////////////////////////////////////////////////////////////////////////////////
	//	When the cursor gets close to the BOTTOM border of the WINDOW -> the CAMERA moves to the BOTTOM
	if ((cursor.getPosCursorOnGameWindow().y >= window.getSize().y - marginForCursor) && (cursor.getPosCursorOnGameWindow().x > window.getSize().x / 4.f) && isViewAtMapBottom == false)
	{
		cameraView.move(0.f, 2.f);
	}
}

void Camera::playerAtCameraBorder(Player& player)
{
	if (isPlayerAtMapLeft == true && isViewAtMapLeft == false)
	{
		cameraView.move(-2, 0.f);
	}

	if (isPlayerAtMapRight == true && isViewAtMapRight == false)
	{
		cameraView.move(2, 0.f);
	}

	if (isPlayerAtMapTop == true && isViewAtMapTop == false)
	{
		cameraView.move(0.f, -2);
	}

	if (isPlayerAtMapBottom == true && isViewAtMapBottom == false)
	{
		cameraView.move(0.f, 2);
	}
}


//#######################################################################################################
//	Accessors
//#######################################################################################################
sf::View Camera::getCameraView()
{
	return cameraView;
}
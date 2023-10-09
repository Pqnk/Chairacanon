#include "LateralScreen.hpp"

LateralScreen::LateralScreen()
{
}

LateralScreen::~LateralScreen()
{
}


//##########################
//	Initial. of lat. Screen
//##########################
void LateralScreen::initLateralScreen(sf::Sprite latScreen, Camera& cam, sf::Sprite earth, sf::Sprite numbers)
{
	animationTimeLatScreen.restart();

	earthSprite = earth;
	earthFrame.left = 5.0;
	earthFrame.top = 5.0;
	earthFrame.width = 270.0;
	earthFrame.height = 220.0;
	earthSprite.setTextureRect(earthFrame);
	earthSprite.setScale(0.4f, 0.4f);

	numberSprite = numbers;
	numberFrame.left = 64.0;
	numberFrame.top = 0.0;
	numberFrame.width = 64.0;
	numberFrame.height = 64.0;
	numberSprite.setTextureRect(numberFrame);
	numberSprite.setScale(0.4f, 0.4f);


	latScreenSprite = latScreen;
	latScreenSprite.setScale(0.4f, 0.4f);
	latScreenSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2
	);
}


//##########################
//	Animation of lat.Screen
//##########################
void LateralScreen::animationLatScreen()
{
	if (animationTimeLatScreen.getElapsedTime().asSeconds() >= 0.5f)
	{
		earthFrame.left += 277.0f;
		earthFrame.top = 5.0f;

		if(earthFrame.left >= 2970.f)
		{
			earthFrame.left = 5.0f;
		}

		earthSprite.setTextureRect(earthFrame);
		animationTimeLatScreen.restart();
	}
}


//##########################
//	Render of lat. Screen
//##########################
void LateralScreen::renderShape(Camera& cam, sf::RenderTarget& window)
{
	animationLatScreen();

	//	///////////////////////////////////////////////////////////////////////////
	//	Setting the position of the Lateral screen, and drawing it
	latScreenSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2
	);
	window.draw(latScreenSprite);

	//	///////////////////////////////////////////////////////////////////////////
	//	Setting the position of the LEVEL NUMBER, and drawing it
	numberSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2 + 90,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2 + 33
	);
	window.draw(numberSprite);

	//	///////////////////////////////////////////////////////////////////////////
	//	Setting the position of the EARTH SPRITE, and drawing it
	earthSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2 + 30,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2 + 210
	);
	window.draw(earthSprite);
}

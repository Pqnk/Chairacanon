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

	latScreenSprite = latScreen;
	latScreenSprite.setScale(0.4f, 0.4f);

	latScreenSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2
	);

	numberSprite = numbers;
}


//##########################
//	Animation of lat.Screen
//##########################
void LateralScreen::animationLatScreen()
{
}


//##########################
//	Render of lat. Screen
//##########################
void LateralScreen::renderShape(Camera& cam, sf::RenderTarget& window)
{
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
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2
	);
	window.draw(numberSprite);
}

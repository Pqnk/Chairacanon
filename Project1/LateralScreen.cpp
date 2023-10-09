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

	numLevelSprite = numbers;
	numLevelFrame.left = 64.0;
	numLevelFrame.top = 0.0;
	numLevelFrame.width = 64.0;
	numLevelFrame.height = 64.0;
	numLevelSprite.setTextureRect(numLevelFrame);
	numLevelSprite.setScale(0.4f, 0.4f);

	numHealthSprite = numbers;
	numHealthFrame.left = 640;
	numHealthFrame.top = 0.0;
	numHealthFrame.width = 64.0;
	numHealthFrame.height = 64.0;
	numHealthSprite.setTextureRect(numHealthFrame);
	numHealthSprite.setScale(0.4f, 0.4f);

	numGrenadesSprite = numbers;
	numGrenadesFrame.left = 0.0;
	numGrenadesFrame.top = 0.0;
	numGrenadesFrame.width = 64.0;
	numGrenadesFrame.height = 64.0;
	numGrenadesSprite.setTextureRect(numGrenadesFrame);
	numGrenadesSprite.setScale(0.4f, 0.4f);



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

		if(earthFrame.top == 5.0f && earthFrame.left >= 3047.f)
		{
			earthFrame.left = 5.0f;
			earthFrame.top = 231.0f;
		}
		if (earthFrame.top == 231.0f && earthFrame.left >= 2493.f)
		{
			earthFrame.left = 5.0f;
			earthFrame.top = 457.0f;
		}
		if (earthFrame.top == 457.0f && earthFrame.left >= 2493.f)
		{
			earthFrame.left = 5.0f;
			earthFrame.top = 5.0f;
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
	numLevelSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2 + 90,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2 + 33
	);
	window.draw(numLevelSprite);

	//	///////////////////////////////////////////////////////////////////////////
	//	Setting the position of the HEALTH, and drawing it
	numHealthSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2 + 128,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2 + 90
	);
	window.draw(numHealthSprite);

	//	///////////////////////////////////////////////////////////////////////////
	//	Setting the position of the GRENADES NUMBER, and drawing it
	numGrenadesSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2 + 9,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2 + 90
	);
	window.draw(numGrenadesSprite);

	//	///////////////////////////////////////////////////////////////////////////
	//	Setting the position of the EARTH SPRITE, and drawing it
	earthSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2 + 28,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2 + 190
	);
	window.draw(earthSprite);
}

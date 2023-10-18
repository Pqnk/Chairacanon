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

	numEnemiesSprite = numbers;
	numEnemiesFrame.left = 0.0;
	numEnemiesFrame.top = 0.0;
	numEnemiesFrame.width = 64.0;
	numEnemiesFrame.height = 64.0;
	numEnemiesSprite.setTextureRect(numEnemiesFrame);
	numEnemiesSprite.setScale(0.3f, 0.3f);

	numBuildingsSprite = numbers;
	numBuildingsFrame.left = 0.0;
	numBuildingsFrame.top = 0.0;
	numBuildingsFrame.width = 64.0;
	numBuildingsFrame.height = 64.0;
	numBuildingsSprite.setTextureRect(numBuildingsFrame);
	numBuildingsSprite.setScale(0.3f, 0.3f);

	latScreenSprite = latScreen;
	latScreenSprite.setScale(0.4f, 0.4f);
	latScreenSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2
	);
}

//##########################
//	Update lat. Screen
//##########################
void LateralScreen::updateLateralScreen(int playerHeath, int numGrenades, int numLevel, int numEnemies, int numBuildings)
{
	switch(playerHeath)
	{
		case 0 : 
			numHealthFrame.left = 0.0;
			break;
		case 1:
			numHealthFrame.left = 64.0;
			break;
		case 2:
			numHealthFrame.left = 128.0;
			break;
		case 3:
			numHealthFrame.left = 192.0;
			break;
		case 4:
			numHealthFrame.left = 256.0;
			break;
		case 5:
			numHealthFrame.left = 320.0;
			break;
		case 6:
			numHealthFrame.left = 394.0;
			break;
		case 7:
			numHealthFrame.left = 448.0;
			break;
		case 8:
			numHealthFrame.left = 512.0;
			break;
		case 9:
			numHealthFrame.left = 576.0;
			break;
		case 10:
			numHealthFrame.left = 640.0;
			break;
	}
	numHealthSprite.setTextureRect(numHealthFrame);

	switch (numGrenades)
	{
	case 0:
		numGrenadesFrame.left = 0.0;
		break;
	case 1:
		numGrenadesFrame.left = 64.0;
		break;
	case 2:
		numGrenadesFrame.left = 128.0;
		break;
	case 3:
		numGrenadesFrame.left = 192.0;
		break;
	case 4:
		numGrenadesFrame.left = 256.0;
		break;
	case 5:
		numGrenadesFrame.left = 320.0;
		break;
	case 6:
		numGrenadesFrame.left = 394.0;
		break;
	case 7:
		numGrenadesFrame.left = 448.0;
		break;
	case 8:
		numGrenadesFrame.left = 512.0;
		break;
	case 9:
		numGrenadesFrame.left = 576.0;
		break;
	case 10:
		numGrenadesFrame.left = 640.0;
		break;
	}
	numGrenadesSprite.setTextureRect(numGrenadesFrame);

	switch (numLevel)
	{
	case 0:
		numLevelFrame.left = 0.0;
		break;
	case 1:
		numLevelFrame.left = 64.0;
		break;
	case 2:
		numLevelFrame.left = 128.0;
		break;
	}
	numLevelSprite.setTextureRect(numLevelFrame);

	switch (numEnemies)
	{
	case 0:
		numEnemiesFrame.left = 0.0;
		break;
	case 1:
		numEnemiesFrame.left = 64.0;
		break;
	case 2:
		numEnemiesFrame.left = 128.0;
		break;
	case 3:
		numEnemiesFrame.left = 192.0;
		break;
	case 4:
		numEnemiesFrame.left = 256.0;
		break;
	case 5:
		numEnemiesFrame.left = 320.0;
		break;
	case 6:
		numEnemiesFrame.left = 394.0;
		break;
	case 7:
		numEnemiesFrame.left = 448.0;
		break;
	case 8:
		numEnemiesFrame.left = 512.0;
		break;
	case 9:
		numEnemiesFrame.left = 576.0;
		break;
	case 10:
		numEnemiesFrame.left = 640.0;
		break;
	}
	numEnemiesSprite.setTextureRect(numEnemiesFrame);

	switch (numBuildings)
	{
	case 0:
		numBuildingsFrame.left = 0.0;
		break;
	case 1:
		numBuildingsFrame.left = 64.0;
		break;
	case 2:
		numBuildingsFrame.left = 128.0;
		break;
	case 3:
		numBuildingsFrame.left = 64.0*3.0;
		break;
	}
	numBuildingsSprite.setTextureRect(numBuildingsFrame);
}

//##########################
//	Animation of lat.Screen
//##########################
void LateralScreen::animationLatScreen()
{
	//	/////////////////////////////////////////////////////////////////
	//	Animation of the earth sprite
	if (animationTimeLatScreen.getElapsedTime().asSeconds() >= 2.f)
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
void LateralScreen::renderShape(Camera& cam, sf::RenderTarget& window, int playerHeath, int numGrenades, int numLevel, int numEnemies, int numBuildings)
{
	animationLatScreen();
	updateLateralScreen(playerHeath, numGrenades, numLevel, numEnemies, numBuildings);

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
	//	Setting the position of the ENEMIES NUMBER, and drawing it
	numEnemiesSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2 + 9,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2 + 119
	);
	window.draw(numEnemiesSprite);

	//	///////////////////////////////////////////////////////////////////////////
	//	Setting the position of the BUILDINGS NUMBER, and drawing it
	numBuildingsSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2 + 9,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2 + 137
	);
	window.draw(numBuildingsSprite);

	//	///////////////////////////////////////////////////////////////////////////
	//	Setting the position of the EARTH SPRITE, and drawing it
	earthSprite.setPosition(
		cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2 + 28,
		cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2 + 190
	);
	window.draw(earthSprite);
}

sf::Sprite LateralScreen::getPlaneteSprite()
{
	return earthSprite;
}

#include "Game.hpp"


//#######################################################################################################
//	Constructor / Destructor
//#######################################################################################################
Game::Game()
{
	/*
	*	@Constructors of class GAME
	*	-	Set the base Cursos invisible
	*	-	Initialisation of Cursor's Animation Timer
	*	-	Initialisation of Player's Animation Timer
	*/

	this->initWindow();
	this->initVariables();

	this->gameWindow->setMouseCursorVisible(false);
	this->cursor.initAnimationTimer();
	this->player.initAnimationTimer();
}

Game::~Game()
{
	delete this->gameWindow;
}

//#######################################################################################################
//	Initialisation Functions
//#######################################################################################################
void Game::initWindow()
{
	this->videoMode.width = 1600;
	this->videoMode.height = 800;
	this->gameWindow = new sf::RenderWindow(this->videoMode, "Chairacanon", sf::Style::Titlebar | sf::Style::Close);
	this->gameWindow->setFramerateLimit(60);
}

void Game::initVariables()
{
	/*
	*	@return void
	*
	*	Initiate  :
	*	-	1 : The LEVEL 01
	*	-	2 : The PLAYER
	*	-	3 : The CAMERA
	*	-	4 :	The CURSOR
	*/

	this->endGame = false;

	this->isLevel1Loaded = false;
	this->isMapShowing = false;

	this->canQuitGameOverScreen = false;

	this->numberLevel = 0;

	this->camera.initCameraView(*this->gameWindow);

	//	Sprite Manager : Loading All Sprites of the game	
	this->spriteManager.initSpriteManager();

	//	Level Manager : Saving all the level's sprites in a vector 
	this->levelManager.initLevels(
		this->spriteManager.getMainMenuSprite(),
		this->spriteManager.getButtonsSprite(),
		this->spriteManager.getLevel1Sprite(),
		this->spriteManager.getLevel1MaskImage(),
		this->spriteManager.getLevel1CloudSprite(),
		this->spriteManager.getLevel2Sprite(),
		this->spriteManager.getLevel2MaskImage(),
		this->spriteManager.getGameOverSprite()
	);

	this->cursor.initCursor();

	//	Initialisation of Sounds and music
	bufferShooting.loadFromFile("Sounds/Shoot.mp3");
	soundShooting.setBuffer(bufferShooting);
	bufferVictory.loadFromFile("Sounds/Win.mp3");
	soundVictory.setBuffer(bufferVictory);
	bufferGameOver.loadFromFile("Sounds/Death.mp3");
	soundGameOver.setBuffer(bufferGameOver);

	music.openFromFile("Music/Menu_Theme_Fast.mp3");
	music.play();
	music.setPlayingOffset(sf::seconds(1));
}

void Game::initLevel1()
{
	this->latScreen.initLateralScreen(
		this->spriteManager.getLateralScreenSprite(),
		this->camera,
		this->spriteManager.getEarthSprite(),
		this->spriteManager.getNumbersSprite()
	);

	//	Player : Initialisation
	this->player.initPlayer(
		this->spriteManager.getCharacterSprite()
	);

	//	Enemies : Initialisation
	this->enemyManager.initEnemyManager(
		this->spriteManager.getCharacterSprite()
	);
	this->enemyManager.initEnemiesOnLevel(this->numberLevel);

	//	Tank : Initialisation
	this->tankManager.initTanksOnMap(
		this->numberLevel,
		this->spriteManager.getCharacterSprite()
	);

	//	Grenades : Initialisation
	this->rocketsManager.initRocketStocksManager(
		this->numberLevel,
		this->spriteManager.getCharacterSprite()
	);

	/*
*	Initialisation of LEFT CLICK POSITION at the Player position
*	At each frame, the player access the left click position to update it's position.
*	This is a temporary sollution, so the player doesn't go the the (0,0) map origin at the begining
*/
	this->cursor.setLeftClickPosition(
		this->player.getSprite().getPosition()
	);

	this->gameWindow->setView(this->camera.getCameraView());

	this->isLevel1Loaded = true;

	music.openFromFile("Music/Chairacanon_Theme.mp3");
	music.setVolume(20);
	music.play();

}

void Game::initLevel2()
{
	this->numberLevel = 2;

	this->latScreen.initLateralScreen(
		this->spriteManager.getLateralScreenSprite(),
		this->camera,
		this->spriteManager.getEarthSprite(),
		this->spriteManager.getNumbersSprite()
	);

	//	Player : Initialisation
	this->player.initPlayer(
		this->spriteManager.getCharacterSprite()
	);

	//	Enemies : Initialisation
	this->enemyManager.initEnemyManager(
		this->spriteManager.getCharacterSprite()
	);
	this->enemyManager.initEnemiesOnLevel(this->numberLevel);

	//	Tank : Initialisation
	this->tankManager.initTanksOnMap(
		this->numberLevel,
		this->spriteManager.getCharacterSprite()
	);

	//	Grenades : Initialisation
	this->rocketsManager.initRocketStocksManager(
		this->numberLevel,
		this->spriteManager.getCharacterSprite()
	);

	/*
*	Initialisation of LEFT CLICK POSITION at the Player position
*	At each frame, the player access the left click position to update it's position.
*	This is a temporary sollution, so the player doesn't go the the (0,0) map origin at the begining
*/
	this->cursor.setLeftClickPosition(
		this->player.getSprite().getPosition()
	);

	this->gameWindow->setView(this->camera.getCameraView());

	music.openFromFile("Music/Chairacanon_Theme.mp3");
	music.setVolume(20);
	music.play();
}


//#######################################################################################################
//	Game
//#######################################################################################################
void Game::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		/*
		*	-	Update the Player
		*	-	Update the Cursor
		*	-	Update the Camera (View) 
		*/

		//	//////////////////////////////////////////
		//	Main Menu
		if (this->numberLevel == 0)
		{
			this->cursor.updateCursor(this->gameWindow);
			this->cursor.setSpriteScale(0.5f);

			//	When overing the PLAY BUTTON
			if (this->levelManager.levels[this->numberLevel].getButton1Level().getGlobalBounds().contains(this->cursor.getSpritePosition().x, this->cursor.getSpritePosition().y))
			{
				this->levelManager.levels[this->numberLevel].setColorButton1();
			}
			else
			{
				this->levelManager.levels[this->numberLevel].resetColorButton1();
			}

			//	When overing the QUIT BUTTON
			if (this->levelManager.levels[this->numberLevel].getButton2Level().getGlobalBounds().contains(this->cursor.getSpritePosition().x, this->cursor.getSpritePosition().y))
			{
				this->levelManager.levels[this->numberLevel].setColorButton2();
			}
			else
			{
				this->levelManager.levels[this->numberLevel].resetColorButton2();
			}
		}

		//	//////////////////////////////////////////
		//	Levels 1 
		if (this->numberLevel == 1 || this->numberLevel == 2)
		{
				this->player.updatePlayer(
					this->cursor.getLeftClickPosition(),
					this->cursor.getRightClickPosition(),
					this->levelManager.levels[numberLevel].getMaskLevel()
				);
				this->player.updateSpriteColor();
				this->enemyManager.updateEnemies(
					this->player,
					this->levelManager.levels[numberLevel].getMaskLevel()
				);
				this->bulletmanager.updateBullets(
					this->enemyManager.enemies,
					this->levelManager.levels[numberLevel].getMaskLevel()
				);
				this->rocketsManager.updateRocketStocks(
					this->player
				);
				this->rocketsManager.updateRocketsThrowed(
					this->levelManager.levels[numberLevel].getMaskLevel()
				);
				this->tankManager.updateTanksOnMap(
					this->rocketsManager.rocketsThrowed
				);
				this->cursor.setSpriteScale(0.1f);
				this->cursor.updateCursor(this->gameWindow);
				this->camera.updateCamera(
					this->levelManager.levels[numberLevel],
					this->cursor,
					this->player,
					*this->gameWindow
				);
				this->levelManager.levels[1].updateLevelElements(*this->gameWindow);

			//	Game Over condition
			if (this->player.getHealth() <= 0)
			{
				music.stop();
				soundGameOver.play();

				this->numberLevel = 3;
				gameOverTimer.restart();
			}

		}

		//	//////////////////////////////////////////
		//	GameOver Screen
		if (this->numberLevel == 3)
		{
			this->player.playerDeathAnimation();
			this->cursor.updateCursor(this->gameWindow);
		}

	}
}

void Game::render()
{
	/*
	*	@return void
	* 
	*	- Clear old frame
	*	- render objets
	*	- display frame in window
	* 
	*	Render objects in this order : 
	*	-	1 : Set the view
	*	-	2 : Draw Level (to have it in the background)
	*	-	3 : Draw Game Objects
	*	-	4 :	Draw the Cursor (to habe it above)
	*/

	//	//////////////////////////////////////////
	//	Main Menu
	if (this->numberLevel == 0)
	{
		this->gameWindow->setView(this->gameWindow->getDefaultView());
		this->levelManager.renderLevel(*this->gameWindow, this->numberLevel);
		this->cursor.renderObject(*this->gameWindow);
	}

	//	//////////////////////////////////////////
	//	Levels 1 & 2
	if (this->numberLevel == 1 || this->numberLevel == 2)
	{
		this->gameWindow->setView(this->camera.getCameraView());
		this->levelManager.renderLevel(*this->gameWindow, numberLevel);
		this->enemyManager.drawEnemy(*this->gameWindow);
		this->tankManager.drawTanks(*this->gameWindow);
		this->rocketsManager.drawRocketStocks(*this->gameWindow);
		this->player.renderObject(*this->gameWindow);
		this->bulletmanager.drawBullet(*this->gameWindow);
		this->rocketsManager.drawRocketsThrowed(*this->gameWindow);
		if (this->isMapShowing == true)
		{
			showMapAndPosition();
			this->gameWindow->draw(spriteMap);
			this->gameWindow->draw(spriteCrossMap);
		}
		this->latScreen.renderShape(
			this->camera,
			*this->gameWindow,
			this->player.getHealth(),
			this->player.getNumGrenades(),
			this->numberLevel,
			this->enemyManager.enemies.size(),
			this->tankManager.tankNumber
		);

		if (this->enemyManager.enemies.size() == 0 && this->tankManager.tankNumber == 0)
		{
			//soundVictory.play();
			music.stop();
			this->spriteManager.renderVictory(this->camera, *this->gameWindow);

			if (victoryTimer.getElapsedTime().asSeconds() > 3)
			{
				if (this->numberLevel == 2)
				{
					this->numberLevel = 0;
					this->isLevel1Loaded = false;
				}
				else
				{
					initLevel2();
				}
			}
		}
		else
		{
			victoryTimer.restart();
		}
		this->cursor.renderObject(*this->gameWindow);
	}

	//	//////////////////////////////////////////
	//	GameOver Screen
	if (this->numberLevel == 3)
	{
		gameWindow->clear();

		this->player.renderObject(*this->gameWindow);

		if (gameOverTimer.getElapsedTime().asSeconds() >= 3.f)
		{
			this->spriteManager.renderGameOver(this->camera, *this->gameWindow);
			if (gameOverTimer.getElapsedTime().asSeconds() >= 5.f)
			{
				gameWindow->clear();
				this->numberLevel = 0;
				this->isLevel1Loaded = false;
			}
			this->cursor.renderObject(*this->gameWindow);
		}
	}

	this->gameWindow->display();
}

void Game::pollEvents()
{
	/*
		@return void

		pollEvent(..) : used to verify if events happenned during the game
		The variable 'event' is filled right when something is happenning
	*/

	while (this->gameWindow->pollEvent(this->event))
	{
		if (this->numberLevel == 0)
		{
			switch (this->event.type)
			{
			case	sf::Event::Closed:
				this->gameWindow->close();
				break;

			case	sf::Event::MouseButtonPressed:

				//	//////////////////////////////////////////////
				//	When clicking on PLAY button
				if (event.mouseButton.button == sf::Mouse::Left
					&& this->levelManager.levels[this->numberLevel].getButton1Level().getGlobalBounds().contains(this->cursor.getSpritePosition().x, this->cursor.getSpritePosition().y))
				{
					numberLevel = 1;
					if (this->isLevel1Loaded == false)
					{
						initLevel1();
					}
					this->cursor.setPosCursorOnWorld(this->player.getSprite().getPosition());
				}

				//	//////////////////////////////////////////////
				//	When clicking on QUIT button
				if (event.mouseButton.button == sf::Mouse::Left
					&& this->levelManager.levels[this->numberLevel].getButton2Level().getGlobalBounds().contains(this->cursor.getSpritePosition().x, this->cursor.getSpritePosition().y))
				{
					this->gameWindow->close();
				}
			}
		}

		if (this->numberLevel == 1 || this->numberLevel == 2)
		{
			switch (this->event.type)
			{
			case	sf::Event::Closed:
				this->gameWindow->close();
				break;

			case	sf::Event::KeyPressed:
				if (this->event.key.code == sf::Keyboard::Escape)
				{
					this->numberLevel = 0;
				}

			case	sf::Event::MouseButtonPressed:

				//	/////////////////////////////////////////////////		
				//	When the user is Clicking LEFT in the cameraView
				if (	(this->cursor.getPosCursorOnGameWindow().x > this->gameWindow->getSize().x / 4)
						&& event.mouseButton.button == sf::Mouse::Left 
					)
					{
						this->cursor.setIsClicking(true);
						this->cursor.setLeftClickPosition(this->cursor.getPosCursorOnWorld());
					}

				//	/////////////////////////////////////////////////		
				//	When the user is Clicking RIGHT in the cameraView
				if (	this->player.getCanShoot() == true
						&& (this->cursor.getPosCursorOnGameWindow().x > this->gameWindow->getSize().x / 4)
						&& event.mouseButton.button == sf::Mouse::Right
					)
				{
					soundShooting.play();
					this->cursor.setIsClickingRight(true);
					this->cursor.setRightClickPosition(this->cursor.getPosCursorOnWorld());
					this->player.setIsShooting(true);
					Bullet bullet(
						this->player.getSpritePosition(),
						this->cursor.getPosCursorOnWorld(),
						this->spriteManager.getCharacterSprite()
					);
					bulletmanager.addBullet(bullet);
				}

				//	/////////////////////////////////////////////////		
				//	When the user is Clicking MIDDLE in the cameraView
				if (
					(this->cursor.getPosCursorOnGameWindow().x > this->gameWindow->getSize().x / 4)
					&& event.mouseButton.button == sf::Mouse::Middle
					)
				{
					if (this->player.getNumGrenades() > 0)
					{
						soundShooting.play();
						this->cursor.setIsClickingRight(true);
						this->cursor.setRightClickPosition(this->cursor.getPosCursorOnWorld());
						this->rocketsManager.addRocketThrowed(
							this->spriteManager.getCharacterSprite(),
							this->player,
							this->cursor.getPosCursorOnWorld()
						);
					}
				}

				//	/////////////////////////////////////////////////		
				//	When the user is Clicking on the PLANETE SPRITE
				if (
					(this->latScreen.getPlaneteSprite().getGlobalBounds().contains(this->cursor.getSpritePosition().x, this->cursor.getSpritePosition().y))
					&& event.mouseButton.button == sf::Mouse::Left
					)
				{
					isMapShowing = !isMapShowing;
				}
			
			}
		}

		if (this->numberLevel == 3 && canQuitGameOverScreen == true)
		{
			switch (this->event.type)
			{
				case	sf::Event::Closed:
						this->gameWindow->close();
				break;

				case	sf::Event::KeyPressed:
					if (this->event.key.code == sf::Keyboard::Escape)
					{
						this->numberLevel = 0;
					}
			}
		}
}
}

bool Game::getEndGame()
{
	return this->endGame;
}

const bool Game::running() const
{
	return this->gameWindow->isOpen();
}

void Game::showMapAndPosition()
{
	spriteMap = this->spriteManager.getLevel1Sprite();
	textMap = this->spriteManager.getLevel1Texture();

	spriteMap.setScale(
		(this->camera.getCameraView().getSize().x / textMap.getSize().x), 
		(this->camera.getCameraView().getSize().y / textMap.getSize().y)
	);
	spriteMap.setPosition(
		(this->camera.getCameraView().getCenter().x - this->camera.getCameraView().getSize().x / 2.0f) + 150,
		this->camera.getCameraView().getCenter().y - this->camera.getCameraView().getSize().y / 2.0f
	);	
	//spriteMap.setColor(sf::Color::Blue);


	textureCrossMap.loadFromFile("Textures/Pika.png");
	spriteCrossMap.setTexture(textureCrossMap);
	spriteCrossMap.setScale(0.05, 0.05);
	spriteCrossMap.setPosition(
		spriteMap.getPosition().x + (player.getSpritePosition().x * spriteMap.getScale().x),
		spriteMap.getPosition().y + (player.getSpritePosition().y * spriteMap.getScale().y)
	);
}

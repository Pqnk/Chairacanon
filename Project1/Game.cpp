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
		this->spriteManager.getLevel2MaskImage()
	);

	this->cursor.initCursor();
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
	this->enemyManager.initEnemiesOnLevel(1);

	//	Tank : Initialisation
	this->tankManager.initTanksOnMap(
		this->numberLevel,
		this->spriteManager.getCharacterSprite()
	);

	//	Grenades : Initialisation
	this->grenadeManager.initGrenadeStocksManager(
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
		if (numberLevel == 0)
		{
			this->cursor.updateCursor(this->gameWindow);
			this->cursor.setSpriteScale(0.5f);
		}

		//	//////////////////////////////////////////
		//	Levels 1 and 2
		if (numberLevel > 0 && numberLevel < 3)
		{
			this->player.updatePlayer(
				this->cursor.getLeftClickPosition(),
				this->cursor.getRightClickPosition(),
				this->levelManager.levels[numberLevel].getMaskLevel()
			);
			this->enemyManager.updateEnemies(
				this->player,
				this->levelManager.levels[numberLevel].getMaskLevel()
			);
			this->bulletmanager.updateBullets(
				this->enemyManager.enemies,
				this->levelManager.levels[numberLevel].getMaskLevel()
			);
			this->grenadeManager.updateGrenadeStocks(
				this->player
			);
			this->grenadeManager.updateGrenadesThrowed(
				this->levelManager.levels[numberLevel].getMaskLevel()
			);
			this->tankManager.updateTanksOnMap(
				this->grenadeManager.grenadeThrowed
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

			//	Endgame condition
			if (this->player.getHealth() <= 0)
				this->endGame = true;
		}

		//	//////////////////////////////////////////
		//	GameOver Screen
		if (numberLevel == 3)
		{

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
	if (numberLevel == 0)
	{
		this->gameWindow->setView(this->gameWindow->getDefaultView());
		this->levelManager.renderLevel(*this->gameWindow, numberLevel);
		this->cursor.renderObject(*this->gameWindow);
	}

	//	//////////////////////////////////////////
	//	Levels 1 and 2
	if (numberLevel > 0 && numberLevel < 3)
	{
		this->gameWindow->setView(this->camera.getCameraView());
		this->levelManager.renderLevel(*this->gameWindow, numberLevel);
		this->enemyManager.drawEnemy(*this->gameWindow);
		this->tankManager.drawTanks(*this->gameWindow);
		this->grenadeManager.drawGrenadeStocks(*this->gameWindow);
		this->player.renderObject(*this->gameWindow);
		this->bulletmanager.drawBullet(*this->gameWindow);
		this->grenadeManager.drawGrenadesThrowed(*this->gameWindow);
		this->latScreen.renderShape(
			this->camera,
			*this->gameWindow,
			this->player.getHealth(),
			this->player.getNumGrenades(),
			this->numberLevel,
			this->enemyManager.enemies.size(),
			this->tankManager.initialTankNumber
		);

		this->cursor.renderObject(*this->gameWindow);

	}

	//	//////////////////////////////////////////
	//	GameOver Screen
	if (numberLevel == 3)
	{

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

			if (numberLevel == 0)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					numberLevel = 1;
					if (isLevel1Loaded == false)
					{
						initLevel1();

					}
				}
			}

			if (numberLevel > 0 && numberLevel < 3)
			{
				//	/////////////////////////////////////////////////		
				//	When the user is Clicking LEFT in the cameraView
				if (
						(this->cursor.getPosCursorOnGameWindow().x > this->gameWindow->getSize().x / 4) 
						&& event.mouseButton.button == sf::Mouse::Left
					)
				{
					this->cursor.setIsClicking(true);
					this->cursor.setLeftClickPosition(this->cursor.getPosCursorOnWorld());
				}

				//	/////////////////////////////////////////////////		
				//	When the user is Clicking RIGHT in the cameraView
				if (
						this->player.getCanShoot() == true 
						&& (this->cursor.getPosCursorOnGameWindow().x > this->gameWindow->getSize().x / 4) 
						&& event.mouseButton.button == sf::Mouse::Right
					)
				{
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
						this->cursor.setIsClickingRight(true);
						this->cursor.setRightClickPosition(this->cursor.getPosCursorOnWorld());
						this->grenadeManager.addGrenadeThrowed(
							this->spriteManager.getCharacterSprite(),
							this->player,
							this->cursor.getPosCursorOnWorld()
						);
					}
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
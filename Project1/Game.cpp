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

		this->player.updatePlayer(
			this->cursor.getLeftClickPosition(),
			this->cursor.getRightClickPosition(),
			this->levelManager.levels[1].getMaskLevel()
		);
		this->enemyManager.updateEnemies(
			this->player.getSpritePosition(), 
			this->levelManager.levels[1].getMaskLevel());
		this->bulletmanager.updateBullets();
		this->cursor.updateCursor(this->gameWindow);
		this->camera.updateCamera(this->levelManager.levels[1], this->cursor, this->player, *this->gameWindow);
		this->levelManager.levels[1].updateLevelElements(*this->gameWindow);
	}

	//	Endgame condition
	if (this->player.getHealth() <= 0)
		this->endGame = true;
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

	this->gameWindow->setView(this->camera.getCameraView());
	this->levelManager.renderLevel(*this->gameWindow, 1);
	this->player.renderObject(*this->gameWindow);
	this->enemyManager.drawEnemy(*this->gameWindow);
	this->bulletmanager.drawBullet(*this->gameWindow);
	this->latScreen.renderShape(this->camera, *this->gameWindow);

	this->cursor.renderObject(*this->gameWindow);
	this->gameWindow->display();
}

bool Game::getEndGame()
{
	return this->endGame;
}

const bool Game::running() const
{
	return this->gameWindow->isOpen();
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

			case	sf::Event::KeyPressed :
				if (this->event.key.code == sf::Keyboard::Escape)
				{
					this->gameWindow->close();
				}

				//	/////////////////////////////////////////////////		
				//	Test de mort
				if (this->event.key.code == sf::Keyboard::D)
				{
					this->player.setIsDead(true);
				}
				break;

			case	sf::Event::MouseButtonPressed :

				//	/////////////////////////////////////////////////		
				//	When the user is Clicking LEFT in the cameraView
				if (	(this->cursor.getPosCursorOnGameWindow().x > this->gameWindow->getSize().x / 4	)	&&	event.mouseButton.button == sf::Mouse::Left)
				{
					this->cursor.setIsClicking(true);
					this->cursor.setLeftClickPosition(this->cursor.getPosCursorOnWorld());
				}

				//	/////////////////////////////////////////////////		
				//	When the user is Clicking RIGHT in the cameraView
				if ( this->player.getCanShoot() == true && (this->cursor.getPosCursorOnGameWindow().x > this->gameWindow->getSize().x / 4	)		&&	event.mouseButton.button == sf::Mouse::Right)
				{
					this->cursor.setIsClickingRight(true);
					this->cursor.setRightClickPosition(this->cursor.getPosCursorOnWorld());
					this->player.setIsShooting(true);
					Bullet bullet(this->player.getSpritePosition(), this->cursor.getPosCursorOnWorld(), this->spriteManager.getCharacterSprite());
					bulletmanager.addBullet(bullet);
				}
		}
	}
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
	this->camera.initCameraView(*this->gameWindow);

	//	Sprite Manager : Loading All Sprites of the game	
	this->spriteManager.initSpriteManager();

	//	Level Manager : Saving all the level's sprites in a vector 
	this->levelManager.initLevels(
			this->spriteManager.getMainMenuSprite(),
			this->spriteManager.getLevel1Sprite(),
			this->spriteManager.getLevel1MaskImage(),
			this->spriteManager.getLevel1CloudSprite(),
			this->spriteManager.getLevel2Sprite(),
			this->spriteManager.getLevel2MaskImage()
	);

	this->latScreen.initLateralScreen(this->camera, *this->gameWindow);

	//	Player : Initialisation
	this->player.initPlayer(this->spriteManager.getCharacterSprite());

	//	Enemies : Initialisation
	this->enemyManager.initEnemyManager(this->spriteManager.getCharacterSprite());
	this->enemyManager.initEnemiesOnLevel(1);

	this->cursor.initCursor();

	/*	
	*	Initialisation of LEFT CLICK POSITION at the Player position
	*	At each frame, the player access the left click position to update it's position.
	*	This is a temporary sollution, so the player doesn't go the the (0,0) map origin at the begining
	*/
	this->cursor.setLeftClickPosition(this->player.getSprite().getPosition());	// TO REPLACE

	this->gameWindow->setView(this->camera.getCameraView());
}
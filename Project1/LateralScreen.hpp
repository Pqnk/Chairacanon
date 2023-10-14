#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Camera.hpp"

class LateralScreen
{
	public :

		LateralScreen();
		~LateralScreen();

		//##########################
		//	Initial. of lat. Screen
		//##########################
		void initLateralScreen(sf::Sprite latScreen, Camera& cam, sf::Sprite earth, sf::Sprite numbers);
		
		//##########################
		//	Update lat. Screen
		//##########################
		void updateLateralScreen(int playerHeath, int numGrenades, int numLevel, int numEnemies, int numBuildings);

		//##########################
		//	Animation of lat.Screen
		//##########################
		void animationLatScreen();

		//##########################
		//	Render of lat. Screen
		//##########################
		void renderShape(Camera& cam, sf::RenderTarget& window, int playerHeath, int numGrenades, int numLevel, int numEnemies, int numBuildings);

		//##########################
		//	Accessor
		//##########################
		sf::Sprite getPlaneteSprite();

	protected :

		sf::Clock animationTimeLatScreen;
		sf::Sprite latScreenSprite;
		sf::Sprite earthSprite;
		sf::IntRect earthFrame;

		sf::Sprite numLevelSprite;
		sf::IntRect numLevelFrame;

		sf::Sprite numHealthSprite;
		sf::IntRect numHealthFrame;

		sf::Sprite numGrenadesSprite;
		sf::IntRect numGrenadesFrame;

		sf::Sprite numEnemiesSprite;
		sf::IntRect numEnemiesFrame;

		sf::Sprite numBuildingsSprite;
		sf::IntRect numBuildingsFrame;
};


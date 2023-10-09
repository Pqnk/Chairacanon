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


		//##########################
		//	Animation of lat.Screen
		//##########################
		void animationLatScreen();

		//##########################
		//	Render of lat. Screen
		//##########################
		void renderShape(Camera& cam, sf::RenderTarget& window);

	protected :

		sf::Clock animationTimeLatScreen;
		sf::Sprite latScreenSprite;
		sf::Sprite earthSprite;
		sf::IntRect earthFrame;
		sf::Sprite numberSprite;
		sf::IntRect numberFrame;

};


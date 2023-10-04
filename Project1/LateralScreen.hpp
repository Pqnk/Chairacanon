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

		void initLateralScreen(Camera& cam, sf::RenderTarget& target);
		void renderShape(Camera& cam, sf::RenderTarget& target);

	protected :

		sf::RectangleShape sidePanel;
};


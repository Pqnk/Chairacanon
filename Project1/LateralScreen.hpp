#pragma once
#include "StillObject.hpp"
#include "Camera.hpp"

class LateralScreen : public StillObject
{
	public :

		LateralScreen();
		~LateralScreen();

		void initLateralScreen(Camera& cam, sf::RenderTarget& target);
		void renderShape(Camera& cam, sf::RenderTarget& target);

	protected :

		sf::RectangleShape sidePanel;
};


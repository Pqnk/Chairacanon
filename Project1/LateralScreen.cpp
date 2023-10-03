#include "LateralScreen.hpp"

LateralScreen::LateralScreen()
{
}

LateralScreen::~LateralScreen()
{
}

void LateralScreen::initLateralScreen(Camera& cam, sf::RenderTarget& target)
{
	sidePanel.setPosition(cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2, cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2);
	sidePanel.setSize(sf::Vector2f(cam.getCameraView().getSize().x / 4.f, cam.getCameraView().getSize().y));
	sidePanel.setFillColor(sf::Color::White);
}

void LateralScreen::renderShape(Camera& cam, sf::RenderTarget& target)
{
	sidePanel.setPosition(cam.getCameraView().getCenter().x - cam.getCameraView().getSize().x / 2, cam.getCameraView().getCenter().y - cam.getCameraView().getSize().y / 2);
	target.draw(sidePanel);
}

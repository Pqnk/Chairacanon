#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class SpriteManager
{
	public :

		SpriteManager();

		void initSpriteManager();
		void initCharacterSprite();
		void initLevelSprite();
		void initLateralScreenSprite();
		void initCloudSprite();
		void initEarthSprite();
		void initNumbersSprite();
		void initButtonsSprite();

		sf::Sprite getCharacterSprite();
		sf::Sprite getMainMenuSprite();
		sf::Sprite getLateralScreenSprite();
		sf::Sprite getLevel1Sprite();
		sf::Image getLevel1MaskImage();
		sf::Sprite getLevel1CloudSprite();
		sf::Sprite getLevel2Sprite();
		sf::Image getLevel2MaskImage();
		sf::Sprite getEarthSprite();
		sf::Sprite getNumbersSprite();
		sf::Sprite getButtonsSprite();

	private :

		sf::Texture characterImage;
		sf::Sprite characterSprite;

		sf::Texture mainMenuImage;
		sf::Sprite mainMenuSprite;

		sf::Texture lateralScreenImage;
		sf::Sprite lateralScreenSprite;

		sf::Texture level1Image;
		sf::Sprite level1Sprite;
		sf::Image level1MaskImage;

		sf::Texture level2Image;
		sf::Sprite level2Sprite;
		sf::Image level2MaskImage;

		sf::Texture cloudImage;
		sf::Sprite cloudSprite;

		sf::Texture earthImage;
		sf::Sprite earthSprite;

		sf::Texture numbersImage;
		sf::Sprite numbersSprite;

		sf::Texture buttonsImage;
		sf::Sprite buttonsSprite;
};


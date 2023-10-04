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

		sf::Sprite getCharacterSprite();
		sf::Sprite getMainMenuSprite();
		sf::Sprite getLateralScreenSprite();
		sf::Sprite getLevel1Sprite();
		sf::Sprite getLevel1MaskSprite();
		sf::Sprite getLevel2Sprite();

	private :

		sf::Texture characterImage;
		sf::Sprite characterSprite;

		sf::Texture mainMenuImage;
		sf::Sprite mainMenuSprite;

		sf::Texture lateralScreenImage;
		sf::Sprite lateralScreenSprite;

		sf::Texture level1Image;
		sf::Sprite level1Sprite;

		sf::Texture level1MaskImage;
		sf::Sprite level1MaskSprite;

		sf::Texture level2Image;
		sf::Sprite level2Sprite;
};


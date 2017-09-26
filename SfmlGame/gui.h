#pragma once
#include<time.h>
#include"view.h"
#include "player.h"

class gui
{
private:
	sf::Font _font;
	sf::Text _score;
	sf::Text _armor;
	sf::Text _hp;

	player* _player;
	view _view;

	//entity _hurt;
	//entity _coin;

	entity _select;


	sf::Image _img;
	sf::Texture _imgText;
	sf::Sprite _imgSprite;
	
	sf::Image _black;
	sf::Texture _blackText;
	sf::Sprite _blackSprite;

	sf::Text _backText;
	sf::Text _exitText;

	sf::RenderWindow* _window;
	
	bool _checkMenu=false;
	bool _isBiger;
	int _menuNum = 0;

public:
	gui();
	void setPlayerGui(player* pl);
	void window(bool isbiger);
	
	void setRenderWindow(sf::RenderWindow& window);
	
	void menu(sf::RenderWindow& window);
	bool isWorkMenu();
	
	void Draw(sf::RenderWindow& window);

	void drawBlack(sf::RenderWindow & window);
	
};


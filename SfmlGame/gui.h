#pragma once
#include<time.h>
#include"view.h"
#include "player.h"
#include "inventary.h"
#include"game_map.h"
#include"enamies.h"
#include"menusettings.h"
#include"SFML\Audio.hpp"

class gui
{
private:
	sf::Font _font;
	sf::Font _font2;
	sf::Text _score;
	sf::Text _armor;
	sf::Text _hp;

	player* _player;
	view _view;

	
	sf::Text _musicSText;
	sf::Text _leftMSText;
	sf::Text _righMtStext;

	//entity _hurt;
	//entity _coin;

	entity _select;


	sf::Image _img;
	sf::Texture _imgText;
	sf::Sprite _imgSprite;
	////////////////////////////////
	sf::Image _over;
	sf::Texture _overText;
	sf::Sprite _overSprite;
	sf::Text _timeText;
	sf::Text _scoreText;
	sf::Text _retryText;
	sf::Text _retryTextGui;
	///////////////////////////////

	sf::Image _black;
	sf::Texture _blackText;
	sf::Sprite _blackSprite;

	sf::Image _end;
	sf::Texture _endText;
	sf::Sprite _endSprite;


	sf::Text _backText;
	sf::Text _exitText;

	sf::RenderWindow* _window;

	sf::Clock _gameTimeClock;//переменная игрового времени, будем здесь хранить время игры 
	int _hGT=0;
	int _mGT = 0;
	int _sGT = 0;

	bool _checkMenu=false;
	bool _isDead = false;
	bool _isBiger;
	int _menuNum = 0;

	inventary _inventary;

	bool _isPlay = true;
	sf::Music* _music;

public:
	gui();

	void setFont();
	void setText();
	void setImage();
	void setPlayerGui(player* pl);
	void window(bool isbiger);
	void setMusic(bool sm)
	{
		_isPlay = sm;
		if (_isPlay)
		{
			_musicSText.setString("music on");
		}
		else
		{
			_musicSText.setString("music off");
		}
	}
	void setMusic(sf::Music& sm)
	{
		_music = &sm;
	}
	void setRenderWindow(sf::RenderWindow& window);
	
	void menu(sf::RenderWindow& window);
	bool isWorkMenu();

	void gameOver(sf::RenderWindow & window);
	
	void Draw(sf::RenderWindow& window);

	void drawBlack(sf::RenderWindow & window);
	
};


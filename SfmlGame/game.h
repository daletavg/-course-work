#pragma once

#include "player.h"
#include "menu.h"
#include "game_map.h"
#include "enamies.h"
#include "gui.h"
using  namespace sf;


class game
{
private:
	RenderWindow window;
	player _player;
	menu _menuGame;
	game_map _gameMap;
	enamies _bots;


	gui _gui;


	Clock _clock;
	float _time;
	sf::Font _font;
	sf::Text _level;

public:
	game();
	void updateClock();
	void updateGame();

	void updateItem();
	
};


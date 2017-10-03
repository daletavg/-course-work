#include "game.h"






game::game()
{
	window.create(VideoMode(800, 600), "Game");
	sf::Image icon;
	icon.loadFromFile("image/icon.png");
	window.setIcon(20, 28, icon.getPixelsPtr());
	_menuGame.setRenderWindow(window);
	_gui.setRenderWindow(window);
	if (_menuGame.menuGame() == 2) {
		return;
	}
	_gui.setMusic(_menuGame.getMusic());
	_gui.setMusic(_menuGame.getOnOff());
	_gui.window(_menuGame.isBigerWindow());
	window.clear();

	_gameMap.initLevel();
	_gameMap.addGameMap(&_gameMap);
	_player.setPlayer("rogue.png", 40, 111, 31, 42, _gameMap.getSpawn().left, _gameMap.getSpawn().top);
	_player.addWindow(window);
	
	_player.setMap(&_gameMap);
	_player.setTime(&_time);
	_player.setEnamies(&_bots);
	_gui.setPlayerGui(&_player);

	_bots.setTime(&_time);
	_bots.setMap(&_gameMap);
	_bots.initBots();

	updateGame();

}

void game::updateClock()
{
	_time = _clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
	_clock.restart();
	_time = _time / 800;
}

void game::updateGame()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		updateClock();///Clock updater



		window.clear();
		
		updateItem();///game character, map update
		
		_gameMap.drawAbovePlayer(window);
		
		_gui.drawBlack(window);
		if (!_gui.isWorkMenu()&& !_player.isEnd())
		{
			_player.moveCharacter();
		}
		_gui.Draw(window);
		_gui.menu(window);
		

		window.display();
	}
}

void game::updateItem()
{

	_gameMap.Draw(window);
	_bots.Draw(window);
	_player.Draw(window);

}

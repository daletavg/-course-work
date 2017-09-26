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
	_gui.window(_menuGame.isBigerWindow());
	window.clear();

	_gameMap.initLevel();
	_player.setPlayer("rogue.png", 43, 120, 33, 45, _gameMap.getSpawn().left, _gameMap.getSpawn().top);
	_player.addWindow(window);
	
	_player.setMap(&_gameMap);
	_player.setTime(&_time);
	_gui.setPlayerGui(&_player);

	updateGame();

}

void game::updateClock()
{
	_time = _clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
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
		if (!_gui.isWorkMenu())
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
	_player.Draw(window);

}

#include "menu.h"





menu::menu()
{
	loadMenu();
}
void menu::setMusic()
{
	_music.openFromFile("music//game.ogg");
	_music.setLoop(true);
	_music.play();
}
void menu::loadSurface()
{

	_img.loadFromFile("image//surface.png");
	_imgText.loadFromImage(_img);
	_imgSprite.setTexture(_imgText);
	_imgSprite.setPosition(230, 25);
	_imgSprite.scale(4, 4);
}

void menu::loadText()
{
	_font.loadFromFile("fonts/arcade.ttf");

	_newGText.setFont(_font);
	_newGText.setCharacterSize(50);
	_newGText.setString("New Game");
	_newGText.setPosition(_xNew, _yNew);

	_settingsGText.setFont(_font);
	_settingsGText.setCharacterSize(50);
	_settingsGText.setString("Settings");
	_settingsGText.setPosition(_xSettings, _ySettings);

	_exitGText.setFont(_font);
	_exitGText.setCharacterSize(50);
	_exitGText.setString("Exit");
	_exitGText.setPosition(_xExit, _yExit);

	_settings.setSpriteBorder(_imgSprite);
	addPosition(0, 70);
}

void menu::loadMenu()
{
	setMusic();
	loadSurface();
	loadText();

	
}
void menu::Draw(RenderWindow & window)
{
	
	window.draw(_imgSprite);
	window.draw(_settingsGText);
	window.draw(_newGText);
	window.draw(_exitGText);
}
void menu::setRenderWindow(RenderWindow & window)
{
	_window = &window;
	_settings.setRenderWindow(window);
}

bool menu::isBigerWindow()
{
	return _settings.isBiger();
}
void menu::addPosition(float x, float y)
{
	_xNew += x;
	_yNew += y;
	_xSettings += x;
	_ySettings += y;
	_xExit += x;
	_yExit += y;
	_newGText.setPosition(_xNew, _yNew);
	_settingsGText.setPosition(_xSettings, _ySettings);
	_exitGText.setPosition(_xExit, _yExit);
}
int menu::menuGame()
{

	bool isGame = false;
	while (_window->isOpen())
	{
		sf::Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				_window->close();
			}
		}

		menuNum = 0;
		_window->clear();
		if (_settings.isBiger()) {
			if (IntRect(_xNew + 40, _yNew + 50, 210, 30).contains(Mouse::getPosition(*_window)))
			{
				_newGText.setColor(Color::Blue); menuNum = 1;
			}
			else { _newGText.setColor(Color::White); }
			if (IntRect(_xSettings + 40, _ySettings + 50, 220, 30).contains(Mouse::getPosition(*_window)))
			{
				_settingsGText.setColor(Color::Blue); menuNum = 2;
			}
			else { _settingsGText.setColor(Color::White); }
			if (IntRect(_xExit + 40, _yExit + 60, 120, 30).contains(Mouse::getPosition(*_window)))
			{
				_exitGText.setColor(Color::Blue); menuNum = 3;
			}
			else { _exitGText.setColor(Color::White); }
		}
		else
		{
			if (IntRect(_xNew, _yNew + 20, 210, 30).contains(Mouse::getPosition(*_window)))
			{
				_newGText.setColor(Color::Blue); menuNum = 1;
			}
			else { _newGText.setColor(Color::White); }
			if (IntRect(_xSettings, _ySettings + 20, 220, 30).contains(Mouse::getPosition(*_window)))
			{
				_settingsGText.setColor(Color::Blue); menuNum = 2;
			}
			else { _settingsGText.setColor(Color::White); }
			if (IntRect(_xExit, _yExit + 20, 120, 30).contains(Mouse::getPosition(*_window)))
			{
				_exitGText.setColor(Color::Blue); menuNum = 3;
			}
			else { _exitGText.setColor(Color::White); }
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { cout << "new game" << endl; return menuNum; }
			if (menuNum == 2) { cout << "settings" << endl; _isSettings = true; break; }
			if (menuNum == 3) { cout << "exit" << endl; _window->close(); return menuNum; }
		}

		Draw(*_window);

		_window->display();
	}
	_window->clear();
	if (_isSettings)
	{
		_isSettings = false;
		_settings.setMusic(getMusic());
		_settings.menuGame();
		menuGame();

		return menuNum;
	}
	return 0;
}

sf::Music & menu::getMusic()
{
	return _music;
}


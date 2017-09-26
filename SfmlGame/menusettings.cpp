#include "menusettings.h"





menusettings::menusettings()
{
	loadMenu();
}
void menusettings::setSpriteBorder(Sprite & _sprite)
{
	_imgSprite = &_sprite;
}
void menusettings::loadMenu()
{



	_font.loadFromFile("fonts/arcade.ttf");//передаем нашему шрифту файл шрифта
	_font2.loadFromFile("fonts/pixel.ttf");

	_videoSText.setFont(_font);
	_videoSText.setCharacterSize(50);
	_videoSText.setString("Display");
	_videoSText.setPosition(_xVideo, _yVideo);

	_sizeSText.setFont(_font);
	_sizeSText.setCharacterSize(40);
	_sizeSText.setString("800x600");
	_sizeSText.setPosition(_xSize, _ySize);

	_rightStext.setFont(_font2);
	_rightStext.setCharacterSize(40);
	_rightStext.setString(">");
	_rightStext.setPosition(_xRight, _yLeftRight);

	_leftSText.setFont(_font2);
	_leftSText.setCharacterSize(40);
	_leftSText.setString("<");
	_leftSText.setPosition(_xLeft, _yLeftRight);

	_musicSText.setFont(_font);
	_musicSText.setCharacterSize(50);
	_musicSText.setString("Music");
	_musicSText.setPosition(_xMusic, _yMusicOnOff);

	_onoffSText.setFont(_font);
	_onoffSText.setCharacterSize(40);
	_onoffSText.setString("on");
	_onoffSText.setPosition(_xOnoff, _yLeftRightM);

	_righMtStext.setFont(_font2);
	_righMtStext.setCharacterSize(40);
	_righMtStext.setString(">");
	_righMtStext.setPosition(_xRightM, _yLeftRightM);

	_leftMSText.setFont(_font2);
	_leftMSText.setCharacterSize(40);
	_leftMSText.setString("<");
	_leftMSText.setPosition(_xLeftM, _yLeftRightM);


	_backSText.setFont(_font);
	_backSText.setCharacterSize(50);
	_backSText.setString("Back");
	_backSText.setPosition(_xBack, _yBack);
	addPosition(0, 60);
}
void menusettings::addPosition(float x, float y)
{
	_xVideo += x;
	_yVideo += y;
	_xSize += x;
	_ySize += y;
	_xLeft += x;
	_xRight += x;
	_yLeftRight += y;
	_xMusic += x;
	_xOnoff += x;
	_yMusicOnOff += y;
	_xBack += x;
	_yBack += y;
	_xLeftM += x;
	_xRightM += x;
	_yLeftRightM += y;
	_videoSText.setPosition(_xVideo, _yVideo);
	_sizeSText.setPosition(_xSize, _ySize);
	_rightStext.setPosition(_xRight, _yLeftRight);
	_leftSText.setPosition(_xLeft, _yLeftRight);
	_musicSText.setPosition(_xMusic, _yMusicOnOff);
	_onoffSText.setPosition(_xOnoff, _yLeftRightM);
	_backSText.setPosition(_xBack, _yBack);
	_righMtStext.setPosition(_xRightM, _yLeftRightM);
	_leftMSText.setPosition(_xLeftM, _yLeftRightM);
}
void menusettings::Draw(RenderWindow & window)
{
	window.draw(*_imgSprite);
	window.draw(_videoSText);
	window.draw(_sizeSText);
	window.draw(_rightStext);
	window.draw(_leftSText);
	window.draw(_musicSText);
	window.draw(_onoffSText);
	window.draw(_backSText);
	window.draw(_righMtStext);
	window.draw(_leftMSText);
}
void menusettings::setRenderWindow(RenderWindow & window)
{
	_window = &window;
}
int menusettings::menuGame()
{
	int menuNum;
	bool isGame = false;
	while (_window->isOpen())
	{

		sf::Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window->close();
		}

		menuNum = 0;
		_window->clear();

		//if (IntRect(305, 120, 210, 30).contains(Mouse::getPosition(window)))
		//{
		//	_newGText.setColor(Color::Blue); menuNum = 1;
		//}
		//else { _newGText.setColor(Color::White); }

		if (_sizeSText.getString() == "800x600") {
			if (IntRect(_xLeft, _yLeftRight + 20, 15, 30).contains(Mouse::getPosition(*_window)))
			{
				_leftSText.setColor(Color::Blue); menuNum = 1;
			}
			else { _leftSText.setColor(Color::White); }



			if (IntRect(_xRight, _yLeftRight + 20, 15, 30).contains(Mouse::getPosition(*_window)))
			{
				_rightStext.setColor(Color::Blue); menuNum = 2;
			}
			else { _rightStext.setColor(Color::White); }


			if (IntRect(_xBack, _yBack + 20, 120, 30).contains(Mouse::getPosition(*_window)))
			{
				_backSText.setColor(Color::Blue); menuNum = 5;
			}
			else { _backSText.setColor(Color::White); }


			if (IntRect(_xLeftM, _yLeftRightM + 20, 15, 30).contains(Mouse::getPosition(*_window)))
			{
				_leftMSText.setColor(Color::Blue); menuNum = 3;
			}
			else { _leftMSText.setColor(Color::White); }



			if (IntRect(_xRightM, _yLeftRightM + 20, 15, 30).contains(Mouse::getPosition(*_window)))
			{
				_righMtStext.setColor(Color::Blue); menuNum = 4;
			}
			else { _righMtStext.setColor(Color::White); }
		}
		if (_sizeSText.getString() == "900x700") {
			if (IntRect(_xLeft + 40, _yLeftRight + 40, 15, 30).contains(Mouse::getPosition(*_window)))
			{
				_leftSText.setColor(Color::Blue); menuNum = 1;
			}
			else { _leftSText.setColor(Color::White); }



			if (IntRect(_xRight + 60, _yLeftRight + 60, 15, 30).contains(Mouse::getPosition(*_window)))
			{
				_rightStext.setColor(Color::Blue); menuNum = 2;
			}
			else { _rightStext.setColor(Color::White); }


			if (IntRect(_xBack + 50, _yBack + 80, 120, 30).contains(Mouse::getPosition(*_window)))
			{
				_backSText.setColor(Color::Blue); menuNum = 5;
			}
			else { _backSText.setColor(Color::White); }


			if (IntRect(_xLeftM + 40, _yLeftRightM + 60, 15, 30).contains(Mouse::getPosition(*_window)))
			{
				_leftMSText.setColor(Color::Blue); menuNum = 3;
			}
			else { _leftMSText.setColor(Color::White); }



			if (IntRect(_xRightM + 60, _yLeftRightM + 60, 15, 30).contains(Mouse::getPosition(*_window)))
			{
				_righMtStext.setColor(Color::Blue); menuNum = 4;
			}
			else { _righMtStext.setColor(Color::White); }
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				if (_sizeSText.getString() == "900x700")
				{
					_sizeSText.setString("800x600");
					_window->setSize(Vector2u(800, 600));

				}
			}
			if (menuNum == 2) {
				if (_sizeSText.getString() == "800x600")
				{
					_sizeSText.setString("900x700");
					_window->setSize(Vector2u(900, 700));

				}
			}
			if (menuNum == 3) {
				if (_onoffSText.getString() == "on")
				{
					_onoffSText.setString("off");
				}
			}
			if (menuNum == 4) {
				if (_onoffSText.getString() == "off")
				{
					_onoffSText.setString("on");
				}
			}
			if (menuNum == 5) { return menuNum; }


		}

		Draw(*_window);

		_window->display();
	}
	return 0;
}

bool menusettings::isBiger()
{
	if (_sizeSText.getString() == "800x600")
		return false;
	else
		return true;
}


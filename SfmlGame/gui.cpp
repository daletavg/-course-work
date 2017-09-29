#include "gui.h"






gui::gui()
{
	_font.loadFromFile("fonts/arcade.ttf");//передаем нашему шрифту файл шрифта
	_font2.loadFromFile("fonts/pixel.ttf");
	_score.setFont(_font);
	_score.setCharacterSize(20);
	_hp.setFont(_font);
	_hp.setCharacterSize(20);
	_armor.setFont(_font);
	_armor.setCharacterSize(20);

	_scoreText.setFont(_font2);
	_scoreText.setCharacterSize(60);
	_retryText.setFont(_font);
	_retryText.setString("RETRY");
	_retryText.setCharacterSize(50);
	_timeText.setFont(_font2);
	_timeText.setCharacterSize(60);


	_select.setEntity("sеlect", "select.png", 0, 0, 800, 600, 0, 0);
	_select.setSprite();
	///////////////////////////////////////////////

	_img.loadFromFile("image//surface.png");
	_imgText.loadFromImage(_img);
	_imgSprite.setTexture(_imgText);
	_imgSprite.scale(4, 4);
	///////////////////////////////////////////////
	_end.loadFromFile("image//endgame.png");
	_endText.loadFromImage(_end);
	_endSprite.setTexture(_endText);
	///////////////////////////////////////////////
	_black.loadFromFile("image//black.png");
	_blackText.loadFromImage(_black);
	_blackSprite.setTexture(_blackText);
	///////////////////////////////////////////////
	_over.loadFromFile("image//gameover.png");
	 _overText.loadFromImage(_over);
	_overSprite.setTexture(_overText);
	///////////////////////////////////////////////


	_backText.setFont(_font);
	_backText.setCharacterSize(50);
	_backText.setString("Back");
	///////////////////////////////////////////////

	_exitText.setFont(_font);
	_exitText.setCharacterSize(50);
	_exitText.setString("Exit");
	///////////////////////////////////////////////

}

void gui::setPlayerGui(player * pl)
{
	_player = pl;
	_score.setString(pl->getScore() + "s");
	_hp.setString(pl->getHp() + " hp");
}

void gui::window(bool isbiger)
{
	_isBiger = isbiger;
}

void gui::setRenderWindow(sf::RenderWindow & window)
{
	_window = &window;
}

void gui::menu(sf::RenderWindow & window)
{

	int x = _view.getViewX();
	int y = _view.getViewY();

	sf::Vector2i mouse = sf::Mouse::getPosition();
	if (_player->getHp() == 0)
	{
		if (!_isBiger) {
		
			if (sf::IntRect(340,490, 130, 37).contains(sf::Mouse::getPosition(window)))
			{
					_retryText.setColor(sf::Color::Blue); _menuNum = 3;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (_menuNum == 3)
				{
					_gameTimeClock.restart();
					_hGT = 0;
					_mGT = 0;
					_sGT = 0;
					_player->reloadGame();
					_menuNum = 0;
				}

			}

		}
		if (_isBiger) {

			if (sf::IntRect(390, 580, 130, 37).contains(sf::Mouse::getPosition(window)))
			{
				_retryText.setColor(sf::Color::Blue); _menuNum = 3;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (_menuNum == 3)
				{
					_gameTimeClock.restart();
					_hGT = 0;
					_mGT = 0;
					_sGT = 0;
					_player->reloadGame();
					_menuNum = 0;
				}

			}

		}


		_retryText.setPosition(_view.getVeiw().x - 60, _view.getVeiw().y + 180);
		window.draw(_retryText);

	}

	if (!_isBiger) {
		if (sf::IntRect(751, 9, 42, 37).contains(sf::Mouse::getPosition(window)))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				_checkMenu = true;
			}
		}
		if (_checkMenu)
		{

			if (sf::IntRect(350, 120, 120, 30).contains(sf::Mouse::getPosition(window)))
			{
				_backText.setColor(sf::Color::Blue); _menuNum = 1;

			}
			else {
				_backText.setColor(sf::Color::White);
				_menuNum = 0;
			}
			if (sf::IntRect(350, 170, 110, 30).contains(sf::Mouse::getPosition(window)))
			{
				_exitText.setColor(sf::Color::Blue); _menuNum = 2;

			}
			else {
				_exitText.setColor(sf::Color::White);

			}


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (_menuNum == 1)
				{
					_checkMenu = false;
					_menuNum = 0;
				}
				if (_menuNum == 2)
				{
					_checkMenu = false;
					_menuNum = 0;
					_window->close();
				}
			}

			_imgSprite.setPosition((_view.getVeiw().x - 400) + 230, (_view.getVeiw().y - 300) + 25);
			_backText.setPosition((_view.getVeiw().x - 400) + 350, (_view.getVeiw().y - 300) + 100);
			_exitText.setPosition((_view.getVeiw().x - 400) + 350, (_view.getVeiw().y - 300) + 150);

			window.draw(_imgSprite);
			window.draw(_backText);
			window.draw(_exitText);


		}
	}
	if (_isBiger) {
		if (sf::IntRect(851, 9, 52, 47).contains(sf::Mouse::getPosition(window)))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				_checkMenu = true;
			}
		}
		if (_checkMenu)
		{

			if (sf::IntRect(380, 140, 120, 30).contains(sf::Mouse::getPosition(window)))
			{
				_backText.setColor(sf::Color::Blue); _menuNum = 1;

			}
			else {
				_backText.setColor(sf::Color::White);
				_menuNum = 0;
			}
			if (sf::IntRect(380, 190, 110, 30).contains(sf::Mouse::getPosition(window)))
			{
				_exitText.setColor(sf::Color::Blue); _menuNum = 2;

			}
			else {
				_exitText.setColor(sf::Color::White);

			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (_menuNum == 1)
				{
					_checkMenu = false;
					_menuNum = 0;
				}
				if (_menuNum == 2)
				{
					_checkMenu = false;
					_menuNum = 0;
					_window->close();
				}
			}

			_imgSprite.setPosition((_view.getVeiw().x - 400) + 230, (_view.getVeiw().y - 300) + 25);
			_backText.setPosition((_view.getVeiw().x - 400) + 350, (_view.getVeiw().y - 300) + 100);
			_exitText.setPosition((_view.getVeiw().x - 400) + 350, (_view.getVeiw().y - 300) + 150);

			window.draw(_imgSprite);
			window.draw(_backText);
			window.draw(_exitText);


		}
	}

}

bool gui::isWorkMenu()
{
	return _checkMenu;
}
void gui::gameOver(sf::RenderWindow& window) 
{
	if (_player->getHp() == 0)
	{

		_overSprite.setPosition(_view.getVeiw().x - 400, _view.getVeiw().y - 300);
		char tmp[20];
		sprintf_s(tmp, "%i", _player->getScore());
		_scoreText.setPosition(_view.getVeiw().x, _view.getVeiw().y + 70);
		_scoreText.setColor(sf::Color(61, 61, 61));
		_scoreText.setString(tmp);
		sprintf_s(tmp, "%i:%i:%i", _hGT, _mGT, _sGT);
		_timeText.setColor(sf::Color(61, 61, 61));
		_timeText.setPosition(_view.getVeiw().x, _view.getVeiw().y + 120);
		_timeText.setString(tmp);
		_retryText.setColor(sf::Color(61, 61, 61));
		

		window.draw(_overSprite);
		window.draw(_scoreText);
		window.draw(_timeText);

	}
	else
	{
		_sGT = _gameTimeClock.getElapsedTime().asSeconds();
		if (_sGT >= 60)
		{
			_mGT++;
			_sGT = 0;
		}
		if (_mGT >= 60)
		{
			_hGT++;
			_mGT = 0;
		}
	}

}
void gui::Draw(sf::RenderWindow & window)
{
	if (_player->isEnd())
	{
		_endSprite.setPosition(_view.getVeiw().x - 400, _view.getVeiw().y - 300);
		window.draw(_endSprite);
		return;
	}
	char tmp[20];
	sprintf_s(tmp, "%i", _player->getScore());
	_score.setString(tmp);
	sprintf_s(tmp, "%i hp", _player->getHp());
	_hp.setString(tmp);
	sprintf_s(tmp, "%i", _player->getArmor());
	_armor.setString(tmp);

	_view.setView(window);
	_view.getCoord(_player->getCoordX(), _player->getCoorgY());

	_hp.setPosition(_view.getVeiw().x - 335, _view.getVeiw().y - 280);
	_armor.setPosition(_view.getVeiw().x - 335, _view.getVeiw().y - 230);

	_score.setPosition(_view.getVeiw().x - 335, _view.getVeiw().y - 175);

	
	_select.setSprite(_view.getVeiw().x - 400, _view.getVeiw().y - 300);
	_select.Draw(window);
	
	gameOver(window);

	window.draw(_hp);
	window.draw(_score);
	window.draw(_armor);
}
void gui::drawBlack(sf::RenderWindow & window)
{
	_blackSprite.setPosition(_view.getVeiw().x - 400, _view.getVeiw().y - 300);
	window.draw(_blackSprite);
}
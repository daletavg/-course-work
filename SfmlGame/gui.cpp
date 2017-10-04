#include "gui.h"






gui::gui()
{
	
	setText();
	setImage();
	//for (size_t i = 0; i < 4; i++)
	//{
	//	bottleHealth* bl = new bottleHealth("bottleHealth", "items.png", sf::FloatRect(0,0, 25, 36), 49, 289, 25, 36);
	//	_inventary.pushOnInventary(bl);
	//}
	

}

void gui::setFont()
{
	_font.loadFromFile("fonts/arcade.ttf");
	_font2.loadFromFile("fonts/pixel.ttf");
}

void gui::setText()
{


	setFont();

	_musicSText.setFont(_font);
	_musicSText.setCharacterSize(50);
	
	_leftMSText.setFont(_font2);
	_leftMSText.setCharacterSize(50);
	_leftMSText.setString("<");

	_righMtStext.setFont(_font2);
	_righMtStext.setCharacterSize(50);
	_righMtStext.setString(">");
	////////////////////////////////////////////

	_retryTextGui.setFont(_font);
	_retryTextGui.setString("RETRY");
	_retryTextGui.setCharacterSize(50);
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


	_backText.setFont(_font);
	_backText.setCharacterSize(50);
	_backText.setString("Back");
	///////////////////////////////////////////////

	_exitText.setFont(_font);
	_exitText.setCharacterSize(50);
	_exitText.setString("Exit");
}

void gui::setImage()
{
	_select.setEntity("sålect", "select.png", 0, 0, 800, 600, 0, 0);
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


	///////////////////////////////////////////////
}

void gui::setPlayerGui(player * pl)
{
	_inventary.setPlayer(pl);
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
	_inventary.setWindow(window);
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
					_retryText.setColor(sf::Color::Blue); _menuNum = 9;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (_menuNum == 9)
				{
					_inventary.delInventory();
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
				_retryText.setColor(sf::Color::Blue); _menuNum = 9;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (_menuNum == 9)
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
	else
	{
		_inventary.checkAct();
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
			///////////////////////////////////////////////
			if (sf::IntRect(330, 170, 130, 30).contains(sf::Mouse::getPosition(window)))
			{
				_retryTextGui.setColor(sf::Color::Blue); _menuNum = 2;

			}
			else {
				_retryTextGui.setColor(sf::Color::White);

			}
			///////////////////////////////////////////////
			if (sf::IntRect(275, 220, 20, 30).contains(sf::Mouse::getPosition(window)))
			{
				_leftMSText.setColor(sf::Color::Blue); _menuNum = 4;

			}
			else {
				_leftMSText.setColor(sf::Color::White);

			}
			if (sf::IntRect(535, 220, 20, 30).contains(sf::Mouse::getPosition(window)))
			{
				_righMtStext.setColor(sf::Color::Blue); _menuNum = 5;

			}
			else {
				_righMtStext.setColor(sf::Color::White);

			}
			///////////////////////////////////////////////
			if (sf::IntRect(350, 250, 110, 30).contains(sf::Mouse::getPosition(window)))
			{
				_exitText.setColor(sf::Color::Blue); _menuNum = 3;

			}
			else {
				_exitText.setColor(sf::Color::White);

			}
			///////////////////////////////////////////////


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (_menuNum == 1)
				{
					_checkMenu = false;
					_menuNum = 0;
				}
				if (_menuNum == 2)
				{
					_inventary.delInventory();
					_gameTimeClock.restart();
					_hGT = 0;
					_mGT = 0;
					_sGT = 0;
					_player->reloadGame();
					_menuNum = 0;
					_player->setIsEnd(false);
				}
				if (_menuNum == 3)
				{
					_checkMenu = false;
					_menuNum = 0;
					_window->close();
				}
				if (_menuNum == 5)
				{
					if (_musicSText.getString() == "music off")
					{
						_music->play();
						_musicSText.setString("music on");
					}
				}
				if (_menuNum == 4)
				{
					if (_musicSText.getString()=="music on")
					{
						_music->stop();
						_musicSText.setString("music off");
					}
				}
				

			}

 			_imgSprite.setPosition((_view.getVeiw().x - 400) + 230, (_view.getVeiw().y - 300) + 25);
			_backText.setPosition((_view.getVeiw().x - 400) + 345, (_view.getVeiw().y - 300) + 100);
			_retryTextGui.setPosition((_view.getVeiw().x - 400) + 335, (_view.getVeiw().y - 300) + 145);
			/////////////////////////
			_musicSText.setPosition((_view.getVeiw().x - 400) + 305, (_view.getVeiw().y - 300) + 190);
			_leftMSText.setPosition((_view.getVeiw().x - 400) + 280, (_view.getVeiw().y - 300) + 190);
			_righMtStext.setPosition((_view.getVeiw().x - 400) + 540, (_view.getVeiw().y - 300) + 190);
			/////////////////////////
			_exitText.setPosition((_view.getVeiw().x - 400) + 350, (_view.getVeiw().y - 300) + 235);

			window.draw(_imgSprite);
			window.draw(_backText);
			window.draw(_exitText);
			window.draw(_retryTextGui);
			window.draw(_musicSText);
			window.draw(_righMtStext);
			window.draw(_leftMSText);
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
			//////////////////////////////////
			if (sf::IntRect(380, 140, 120, 30).contains(sf::Mouse::getPosition(window)))
			{
				_backText.setColor(sf::Color::Blue); _menuNum = 1;

			}
			else {
				_backText.setColor(sf::Color::White);
				_menuNum = 0;
			}
			//////////////////////////////////
			if (sf::IntRect(380, 190, 130, 30).contains(sf::Mouse::getPosition(window)))
			{
				_retryTextGui.setColor(sf::Color::Blue); _menuNum = 2;

			}
			else {
				_retryTextGui.setColor(sf::Color::White);

			}
			///////////////////////////////////////////////
			if (sf::IntRect(325, 240, 20, 30).contains(sf::Mouse::getPosition(window)))
			{
				_leftMSText.setColor(sf::Color::Blue); _menuNum = 4;

			}
			else {
				_leftMSText.setColor(sf::Color::White);

			}
			if (sf::IntRect(610, 240, 20, 30).contains(sf::Mouse::getPosition(window)))
			{
				_righMtStext.setColor(sf::Color::Blue); _menuNum = 5;

			}
			else {
				_righMtStext.setColor(sf::Color::White);

			}
			///////////////////////////////////////////////
			///////////////////////////////////
			if (sf::IntRect(380, 290, 110, 30).contains(sf::Mouse::getPosition(window)))
			{
				_exitText.setColor(sf::Color::Blue); _menuNum = 3;

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
					_inventary.delInventory();
					_gameTimeClock.restart();
					_hGT = 0;
					_mGT = 0;
					_sGT = 0;
					_player->reloadGame();
					_menuNum = 0;
					_player->setIsEnd(false);
				}
				if (_menuNum == 3)
				{
					_checkMenu = false;
					_menuNum = 0;
					_window->close();
				}
				if (_menuNum == 5)
				{
					if (_musicSText.getString() == "music oof")
					{
						_music->play();
						_musicSText.setString("music on");
					}
				}
				if (_menuNum == 4)
				{
					if (_musicSText.getString() == "music on")
					{
						_music->stop();
						_musicSText.setString("music oof");
					}
				}
			}

			_imgSprite.setPosition((_view.getVeiw().x - 400) + 230, (_view.getVeiw().y - 300) + 25);
			_backText.setPosition((_view.getVeiw().x - 400) + 350, (_view.getVeiw().y - 300) + 100);
			/////////////////////////
			_musicSText.setPosition((_view.getVeiw().x - 400) + 305, (_view.getVeiw().y - 300) + 190);
			_leftMSText.setPosition((_view.getVeiw().x - 400) + 280, (_view.getVeiw().y - 300) + 190);
			_righMtStext.setPosition((_view.getVeiw().x - 400) + 540, (_view.getVeiw().y - 300) + 190);
			/////////////////////////
			_retryTextGui.setPosition((_view.getVeiw().x - 400) + 335, (_view.getVeiw().y - 300) + 145);
			_exitText.setPosition((_view.getVeiw().x - 400) + 350, (_view.getVeiw().y - 300) + 235);

			window.draw(_imgSprite);
			window.draw(_backText);
			window.draw(_exitText);
			window.draw(_retryTextGui);
			window.draw(_musicSText);
			window.draw(_righMtStext);
			window.draw(_leftMSText);

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
		char tmp[20];
		sprintf_s(tmp, "%i", _player->getScore());
		_scoreText.setPosition(_view.getVeiw().x, _view.getVeiw().y + 70);
		_scoreText.setColor(sf::Color::White);
		_scoreText.setString(tmp);
		window.draw(_scoreText);

		return;
	}
	_inventary.updateInventary();
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
	_inventary.Draw(_player->getCoordX()-157, _player->getCoorgY()+240);
}
void gui::drawBlack(sf::RenderWindow & window)
{
	_blackSprite.setPosition(_view.getVeiw().x - 400, _view.getVeiw().y - 300);
	window.draw(_blackSprite);
}
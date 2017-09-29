#pragma once
#include "frame.h"
class sword :
	public frame
{
	sf::Font _font;
	sf::Text _sw;
public:
	sword(sf::String name, sf::String image, Object object, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, object.rect.left, object.rect.top);
		setRectPos(object.rect.left, object.rect.top, width, height);
		setSprite();
		setDraw(true);

		_font.loadFromFile("fonts/arcade.ttf");
		_sw.setFont(_font);
		_sw.setCharacterSize(20);
		_sw.setString("we have a sword");
	}
	sword(sf::String name, sf::String image, sf::FloatRect rect, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, rect.left, rect.top);
		setRectPos(rect.left, rect.top, width, height);
		setSprite();
		setDraw(true);

		_font.loadFromFile("fonts/arcade.ttf");
		_sw.setFont(_font);
		_sw.setCharacterSize(20);
		_sw.setString("we have a sword");
	}
	sword(const sword& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		setName(fr._Name);
		if (_isDraw)
		{
			setEntity(fr._Name, fr._pathImage, fr._imageX, fr._imageY, fr._width, fr._height, fr._posX, fr._posY);
		}
	}
	bool checkSword(sf::RenderWindow& window, int damage, float x, float y)
	{
		if (damage >= 25)
		{
			_sw.setPosition(x - 50, y + 100);
			window.draw(_sw);
			return false;
		}
		return true;
	}
	int getDamage() {
		return 25;
	}
};


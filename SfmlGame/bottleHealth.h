#pragma once
#include "frame.h"
class bottleHealth :
	public frame
{
private:
	int _buff = 0;
	sf::Font _font;
	sf::Text _sw;
public:
	bottleHealth(sf::String name, sf::String image, Object object, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, object.rect.left, object.rect.top);
		setRectPos(object.rect.left, object.rect.top, width, height);
		setSprite();
		setDraw(true);
		_buff = (rand() % 20) + 10;;
		_font.loadFromFile("fonts/pixel.ttf");
		_sw.setFont(_font);
		_sw.setCharacterSize(20);
		_sw.setString("   use press(E)\niventary press(F)");
	}
	bottleHealth(sf::String name, sf::String image, sf::FloatRect rect, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, rect.left, rect.top);
		setRectPos(rect.left, rect.top, width, height);
		setSprite();
		setDraw(true);
		_buff = (rand() % 20) + 10;

		_font.loadFromFile("fonts/pixel.ttf");
		_sw.setFont(_font);
		_sw.setCharacterSize(20);
		_sw.setString("   use press(E)\n iventary press(F)");
	}
	bottleHealth(const bottleHealth& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		_buff = fr._buff;
		setName(fr._Name);
		if (_isDraw)
		{
			setEntity(fr._Name, fr._pathImage, fr._imageX, fr._imageY, fr._width, fr._height, fr._posX, fr._posY);
		}
	}
	void Draw(sf::RenderWindow& window, float x, float y)
	{
		_sw.setPosition(x - 50, y + 100);
		window.draw(_sw);
	}
	int getBuff() {
		return _buff;
	}

};


#pragma once
#include "frame.h"
class plate :
	public frame
{
private:
	sf::String _platePath;
	sf::Image _plate;
	sf::Texture _plateT;
	sf::Sprite _plateS;

	int _numPlate;
public:
	plate() = default;
	plate(sf::String name, Object object) {
		setName(name);
		setRectPos(object.rect.left, object.rect.top, object.rect.width, object.rect.height);
		setDraw(false);
	}
	plate(const plate& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		setName(fr._Name);
		
		addPlate(fr._numPlate, fr._platePath);
		if (_isDraw)
		{
			setEntity(fr._Name, fr._pathImage, fr._imageX, fr._imageY, fr._width, fr._height, fr._posX, fr._posY);
		}

	}
	void addPlate(int num,sf::String path) {
		_numPlate = num;
		
		_platePath = path;
		_plate.loadFromFile("image/"+path);
		_plateT.loadFromImage(_plate);
		_plateS.setTexture(_plateT);
		
	}
	void drawPlate(sf::RenderWindow* window, float x, float y) {
		_plateS.setPosition(x, y);
		window->draw(_plateS);
	}


};


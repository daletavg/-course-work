#pragma once
#include "frame.h"

class boxbot :
	public frame
{
	float _xP;
	float _yP;

public:
	boxbot(sf::String name, Object object) {
		setName(name);
		setRectPos(object.rect.left, object.rect.top, object.rect.width, object.rect.height);
		setDraw(false);
	}
	boxbot(const boxbot& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		setName(fr._Name);
		if (_isDraw)
		{
			setEntity(fr._Name, fr._pathImage, fr._imageX, fr._imageY, fr._width, fr._height, fr._posX, fr._posY);
		}
	}
	void setPlayerCoord(float x, float y) {
		_xP = x;
		_yP = y;
	}
	float getPlayerX() {
		return _xP;
	}
	float getPlayerY() {
		return _yP;
	}

	
};


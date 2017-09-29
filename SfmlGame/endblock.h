#pragma once
#include "frame.h"
class endblock :
	public frame
{
public:
	endblock(sf::String name, Object object) {
		setName(name);
		setRectPos(object.rect.left, object.rect.top, object.rect.width, object.rect.height);
		setDraw(false);
	}
	endblock(const endblock& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		setName(fr._Name);
		if (_isDraw)
		{
			setEntity(fr._Name, fr._pathImage, fr._imageX, fr._imageY, fr._width, fr._height, fr._posX, fr._posY);
		}

	}
	bool getEnd() {
		return true;
	}
};


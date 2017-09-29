#pragma once
#include "frame.h"
class key :
	public frame
{
public:
	key(sf::String name, sf::String image, Object object, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, object.rect.left, object.rect.top);
		setRectPos(object.rect.left, object.rect.top, width, height);
		setSprite();
		setDraw(true);
		
	}
	key(sf::String name, sf::String image, sf::FloatRect rect, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, rect.left, rect.top);
		setRectPos(rect.left, rect.top, width, height);
		setSprite();
		setDraw(true);
		
	}
	key(const key& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		setName(fr._Name);
		if (_isDraw)
		{
			setEntity(fr._Name, fr._pathImage, fr._imageX, fr._imageY, fr._width, fr._height, fr._posX, fr._posY);
		}
	}
};


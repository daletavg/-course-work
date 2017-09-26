#pragma once
#include "entity.h"
#include <vector>
using std::vector;
class frame :
	public entity
{
protected:
	sf::FloatRect _rectPos;
	bool _isDraw = true;
	bool _isCollision = false;
public:
	frame()=default;
	frame(sf::String name, sf::String image, Object object, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, object.rect.left, object.rect.top);
		setRectPos(object.rect.left, object.rect.top, width, height);
		setDraw(true);
	}
	frame(sf::String name, Object object ) {
		setName(name);
		setRectPos(object.rect.left, object.rect.top, object.rect.width, object.rect.height);
		setDraw(false);
	}
	frame(const frame& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		setName(fr._Name);
		if (_isDraw)
		{
			setEntity(fr._Name, fr._pathImage, fr._imageX, fr._imageY,fr._width, fr._height, fr._posX, fr._posY);
		}
		
	}
	void setRectPos(float left, float top, float width, float height) {
		_rectPos.left = left;
		_rectPos.top = top;
		_rectPos.width = width;
		_rectPos.height = height;
	}
	void setRectPos(sf::FloatRect pos) {
		_rectPos.left = pos.left;
		_rectPos.top = pos.top;
		_rectPos.width = pos.width;
		_rectPos.height = pos.height;
	}
	void setCollision(bool iscol) {
		_isCollision = iscol;
	}
	bool getCollision() {
		return _isCollision;
	}
	void setDraw(bool isdraw) {
		_isDraw = isdraw;
	}
	bool getDraw() {
		return _isDraw;
	}
	void setSprite() {
		if (_isDraw)
		{
			entity::setSprite();
		}
	}


	virtual void Draw(sf::RenderWindow& window) {
		if (_isDraw)
		{
			window.draw(_Sprite);
		}
	}
	
	sf::FloatRect getRectPos() {
		return _rectPos;
	}


	frame& operator=(frame& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		forcopy(fr);
		return *this;

	}
};


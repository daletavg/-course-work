#pragma once
#include "frame.h"
class door :
	public frame
{
private:
	entity _openDoor;
	bool _isOpen = false;
public:
	door(sf::String name, sf::String image, Object object, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, object.rect.left, object.rect.top);
		setRectPos(object.rect.left, object.rect.top, width, height);
		setDraw(true);
	}
	door(sf::String name, sf::String image, sf::FloatRect rect, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, rect.left, rect.top);
		setRectPos(rect.left, rect.top, width, height);
		setSprite();
		setDraw(true);
		
	}
	door(const door& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		setName(fr._Name);
		if (_isDraw)
		{
			setEntity(fr._Name, fr._pathImage, fr._imageX, fr._imageY, fr._width, fr._height, fr._posX, fr._posY);
		}
	}
	void setOpenDoor(sf::String name, sf::String image, Object object, float ImageX, float ImageY, float width, float height) {
		_openDoor.setEntity(name, image, ImageX, ImageY, width, height, object.rect.left, object.rect.top);
		_openDoor.setSprite();
	}
	void setOpenDoor(sf::String name, sf::String image, sf::FloatRect rect, float ImageX, float ImageY, float width, float height) {
		_openDoor.setEntity(name, image, ImageX, ImageY, width, height, rect.left, rect.top);
		_openDoor.setSprite();
	}
	void setOpen(bool open) {
		_isOpen = open;
		if(open)
		{
			setName("open");
		}
		else
		{
			setName("door");
		}
	}
	virtual void Draw(sf::RenderWindow& window) {
		if (_isOpen){
			_openDoor.Draw(window);
			
		}
		else {
			if (_isDraw)
			{
				window.draw(_Sprite);
			}
		}
		
	}


};


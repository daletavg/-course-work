#pragma once
#include "frame.h"
#include "nullblock.h"
#include"bottleHealth.h"
#include "coins.h"
#include"hauberkArmor.h"
#include"sword.h"

class chess :
	public frame
{
private:

public:
	chess(sf::String name, sf::String image, Object object, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, object.rect.left, object.rect.top);
		setRectPos(object.rect.left, object.rect.top, width, height);
		setDraw(true);
	}
	chess(const chess& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		setName(fr._Name);
		if (_isDraw)
		{
			setEntity(fr._Name, fr._pathImage, fr._imageX, fr._imageY, fr._width, fr._height, fr._posX, fr._posY);
		}
	}
	frame* getItems() {
		setDraw(false);
	/*	int id = rand() % 10;
		frame* f = new frame();
		if (id==0|| id == 5|| id == 8 || id == 4 || id == 3  ) {
			bottleHealth* bl = new bottleHealth("bottleHealth", "items.png", sf::FloatRect(_posX, _posY, 25, 36), 49, 289, 25, 36);
			f = bl;
		}
		if (id == 1 || id == 2||  id == 6|| id == 7|| id == 8) {
			coins* cn = new coins("coins", "items.png", sf::FloatRect(_posX, _posY, 38, 36), 248, 43, 38, 36);
			f = cn;
		}*/
		//hauberkArmor* f = new hauberkArmor("hauberkArmor", "items.png", sf::FloatRect(_posX, _posY, 36, 31), 84, 128, 36, 31);
		//sword* f = new sword("sword", "items.png", sf::FloatRect(_posX, _posY, 36, 31), 84, 5, 34, 33);
		//coins* f = new coins("coins", "items.png", sf::FloatRect(_posX, _posY, 38, 36), 248, 43, 38, 36);
		bottleHealth* f = new bottleHealth("bottleHealth", "items.png", sf::FloatRect(_posX, _posY, 25, 36), 49, 289, 25, 36);

		return f;
	}


};


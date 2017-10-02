#pragma once
#include "frame.h"
enum armors
{
	leather = 0,
	hauberk = 46,
};
class armor :
	public frame 
{
protected:
	sf::Font _font;
	sf::Text _arm;
public:
	armor(sf::String name, sf::String image, Object object, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, object.rect.left, object.rect.top);
		setRectPos(object.rect.left, object.rect.top, width, height);
		setSprite();
		setDraw(true);

		_font.loadFromFile("fonts/pixel.ttf");
		_arm.setFont(_font);
		_arm.setCharacterSize(20);
		_arm.setString("  ARMOR IS FULL");
	}
	armor(sf::String name, sf::String image, sf::FloatRect rect, float ImageX, float ImageY, float width, float height) {
		setEntity(name, image, ImageX, ImageY, width, height, rect.left, rect.top);
		setRectPos(rect.left, rect.top, width, height);
		setSprite();
		setDraw(true);
		
		_font.loadFromFile("fonts/pixel.ttf");
		_arm.setFont(_font);
		_arm.setCharacterSize(20);
		_arm.setString("  ARMOR IS FULL");
	}
	armor(const armor& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		setName(fr._Name);
		if (_isDraw)
		{
			setEntity(fr._Name, fr._pathImage, fr._imageX, fr._imageY, fr._width, fr._height, fr._posX, fr._posY);
		}
	}
	virtual bool checkArmor(sf::RenderWindow& window, int armor, float x, float y) = 0;
	virtual int getArmor() = 0;
	virtual armors getArmorType() = 0;
};


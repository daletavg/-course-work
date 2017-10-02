#pragma once
#include "armor.h"
class hauberkArmor :
	public armor
{

public:
	hauberkArmor(sf::String name, sf::String image, Object object, float ImageX, float ImageY, float width, float height) :
		armor(name, image, object, ImageX, ImageY, width, height) {}
	hauberkArmor(sf::String name, sf::String image, sf::FloatRect rect, float ImageX, float ImageY, float width, float height):
		armor( name, image,  rect,ImageX, ImageY, width,height){}
	virtual int getArmor() override
	{
		return 50;
	}
	virtual armors getArmorType() override {
		
		return hauberk;
	}
	virtual bool checkArmor(sf::RenderWindow& window, int armor, float x, float y) override
	{
		if (armor>=50)
		{
			_arm.setPosition(x-50, y+100);
			window.draw(_arm);
			return false;
		}

		return true;
	}
};


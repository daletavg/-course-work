#pragma once
#include"game_map.h"
#include "frame.h"
#include "door.h"
class opengold :
	public frame
{
	sf::Font _font;
	sf::Text _text;
public:
	opengold(sf::String name, Object object) {
		setName(name);
		setRectPos(object.rect.left, object.rect.top, object.rect.width, object.rect.height);
		setDraw(false);

		_font.loadFromFile("fonts/arcade.ttf");
		_text.setFont(_font);
		_text.setCharacterSize(20);
		_text.setString("you dont have key");
	}
	opengold(const opengold& fr) {
		_isDraw = fr._isDraw;
		_isCollision = fr._isCollision;
		_rectPos = fr._rectPos;
		setName(fr._Name);
		if (_isDraw)
		{
			setEntity(fr._Name, fr._pathImage, fr._imageX, fr._imageY, fr._width, fr._height, fr._posX, fr._posY);
		}

	}

	bool isOpen(sf::RenderWindow& window, bool isopen, float x, float y, game_map* gm)
	{
		if (!isopen)
		{
			_text.setPosition(x - 50, y + 100);
			window.draw(_text);
			return false;
		}
		for (int i = 0; i < gm->getBlock().size(); i++)
		{
			sf::FloatRect rect = getRectPos();
			sf::FloatRect rect2 = gm->getBlockRect(i);
			if (rect.intersects(rect2))
			{
				if (getName() == "opengoldright")
				{
					if (gm->getName(i) == "lockdoor")
					{
						door* fr = new door("door", "Tileset.png", sf::FloatRect(gm->getBlock(i)->getCoordX(), gm->getBlock(i)->getCoorgY(), 48, 48), 1008, 48, 48, 48);
						fr->setOpenDoor("door", "Tileset.png", sf::FloatRect(gm->getBlock(i)->getCoordX(), gm->getBlock(i)->getCoorgY(), 48, 48), 144, 432, 48, 48);
						gm->reBlock(fr, i);
					}
				}
				else
				{

					if (gm->getName(i) == "lockdoor")
					{
						door* fr = new door("door", "Tileset.png", sf::FloatRect(gm->getBlock(i)->getCoordX(), gm->getBlock(i)->getCoorgY(), 48, 48), 1008, 48, 48, 48);
						fr->setOpenDoor("door", "Tileset.png", sf::FloatRect(gm->getBlock(i)->getCoordX(), gm->getBlock(i)->getCoorgY(), 48, 48), 1200, 48, 48, 48);
						gm->reBlock(fr, i);
					}
				}

			}
		}
		return true;
	}
};


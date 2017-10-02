#pragma once
#include "entity.h"
#include "player.h"
#include"nullblock.h"
#include <vector>
using std::vector;
class inventary
{
private:
	vector<entity*> _inventary;
	sf::RenderWindow* _window;
	int _pos[4] = { 20,103,187,270 };
	bool _isFull = false;
	player* _player;
	void checkAct(int index)
	{
		if (_inventary[index]->getName() == "bottleHealth")
		{
			bottleHealth*b = dynamic_cast<bottleHealth*>(_inventary[index]);
			if (_player->addHealth(b->getBuff()))
			{
				_inventary[index] = NullBlock;
			}
		}
		if (_inventary[index]->getName() == "hauberkArmor")
		{
			hauberkArmor*h = dynamic_cast<hauberkArmor*>(_inventary[index]);
			if (h->checkArmor(*_window, _player->getArmor(), _player->getCoordX(), _player->getCoorgY()))
			{
				_player->addArmor(h->getArmor());
				_player->setArmorType(h->getArmorType());
				_inventary[index] = NullBlock;
			}
		}
	}
public:
	inventary();
	void setWindow(sf::RenderWindow& window)
	{
		_window = &window;
	}
	void setPlayer(player* pl)
	{
		_player = pl;
	}
	void delInventory()
	{
		for (size_t i = 0; i < 4; i++)
		{
			_inventary[i] = NullBlock;
		}
	}
	entity* returnObject(int index)
	{
		return _inventary[index];
	}
	
	void checkAct()
	{
		if (Keyboard::isKeyPressed(Keyboard::Num1))
		{
			checkAct(0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num2))
		{
			checkAct(1);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num3))
		{
			checkAct(2);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num4))
		{
			checkAct(3);
		}
	}

	void pushOnInventary(entity* obj)
	{
		if (obj->getName() == "nullblock")
		{
			return;
		}
		if (isFull())
		{
			return;
		}
		for (size_t i = 0; i < 4; i++)
		{
			if (_inventary[i]->getName()=="nullblock")
			{
				
				_inventary[i] = obj;
				break;
			}
			
		}

	}
	bool isFull()
	{
		int counter = 0;
		for (size_t i = 0; i < 4; i++)
		{
			if (_inventary[i]->getName() != "nullblock")
			{
				counter++;
			}
		}
		if (counter==4)
		{
			_isFull = true;
		}
		return _isFull;
	}
	void updateInventary()
	{
		pushOnInventary(_player->getInventary());
		int count = 0;
		for (size_t i = 0; i < _inventary.size(); i++)
		{
			if (_inventary[i]->getName() != "nullblock")
			{
				count++;
			}
		}
		_player->setInventory(count);
	}

	void Draw(float X, float Y)
	{
		
		for (size_t i = 0; i < _inventary.size(); i++)
		{
			if (_inventary[i]->getName()=="nullblock")
			{
				continue;
			}
			if (_inventary[i]->getName() == "hauberkArmor")
			{
				_inventary[i]->setPositionSprite((X + _pos[i])-6, Y+3);
			}
			else
			{
				_inventary[i]->setPositionSprite(X+_pos[i], Y);
			}
			_inventary[i]->Draw(*_window);
		}
	}
	~inventary();
};


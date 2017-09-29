#pragma once
#include "entity.h"
#include"nullblock.h"
#include <vector>
using std::vector;
class inventary
{
private:
	vector<entity*> _inventary;
	sf::RenderWindow* _window;
	int _pos[4] = { 20,40,60,80 };
public:
	inventary();
	void setWindow(sf::RenderWindow& window)
	{
		_window = &window;
	}
	void Draw(float X, float Y)
	{
		
		for (size_t i = 0; i < _inventary.size(); i++)
		{
			if (_inventary[i]->getName()=="nullblock")
			{
				continue;
			}
			_inventary[i]->setPositionSprite(X+_pos[i], Y);
			_inventary[i]->Draw(*_window);
		}
	}
	~inventary();
};


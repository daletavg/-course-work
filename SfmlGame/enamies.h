#pragma once
#include"botFox.h"
#include "game_map.h"
#include<vector>
using std::vector;
class enamies
{
private:
	vector<character*>_bots;
	game_map* _gameMap;
public:
	enamies() = default;
	void setMap(game_map* map) {
		_gameMap = map;
	}
	void initBots(game_map* map) {
		setMap(map);
		vector<Object> tmp = _gameMap->getBlock("botFox");
		for (size_t i = 0; i < tmp.size(); i++)
		{
			botFox* bot = new botFox("fox.png", 2, 0, 23, 31, tmp[i].rect.left, tmp[i].rect.top);		
			bot->setSprite();
			_bots.push_back(bot);
		}
	}
	void Draw(sf::RenderWindow& window)
	{
		for (size_t i = 0; i < _bots.size(); i++)
		{
			_bots[i]->Draw(window);
		}
	}
};


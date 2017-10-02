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
	float* _time;
public:
	enamies() = default;
	void setMap(game_map* map) {
		_gameMap = map;
	}
	void setTime(float* time)
	{
		_time = time;
	}
	void loadNextLevel() {
		_bots.clear();
		initBots();
	}
	vector<character*>& getBots()
	{
		return _bots;
	}
	character* getBot(int index)
	{
		return _bots[index];
	}
	sf::FloatRect getDamageRect(int index)
	{
		return _bots[index]->getDamageRect();
	}
	void initBots() {
		
		vector<Object> tmp = _gameMap->getBlock("botFox");
		for (size_t i = 0; i < tmp.size(); i++)
		{
			botFox* bot = new botFox("fox.png", 2, 0, 23, 31, tmp[i].rect.left, tmp[i].rect.top);		
			bot->setSprite();
			bot->setMap(_gameMap);
			bot->setTime(_time);
			bot->searchBoxBot();
			bot->init();
			_bots.push_back(bot);
		}
	}
	void Draw(sf::RenderWindow& window)
	{
		for (size_t i = 0; i < _bots.size(); i++)
		{
			_bots[i]->Draw(window);
		}
		for (size_t i = 0; i < _bots.size(); i++)
		{
			_bots[i]->moveCharacter();
		}
	}
};


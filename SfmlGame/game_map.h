#pragma once

////////BLOCKS//////////////
#include "solid.h"
#include "plate.h"
#include"grass.h"
#include"boxbot.h"
#include "chess.h"
#include"door.h"
#include"nullblock.h"
#include "nextlvl.h"
#include"coper.h"
#include"endblock.h"
#include"lockdoor.h"
#include"key.h"

//////BOTS////////////////





class game_map
{
private:
	game_map* _gameMap;
	Level lvl;
	int _lvlCounter = 0;
	//vector<bot*> _bots;

	vector<frame*> _Blocks;
	frame fr;
public:
	game_map()=default;
	sf::FloatRect getSpawn();
	void addGameMap(game_map* gm)
	{
		_gameMap = gm;
	}
	void setBlocks(sf::String name, sf::String image, vector<Object> object, float ImageX, float ImageY, float width, float height);
	void reBlock(frame * fr,int index);
	void loadNextLevel();
	void setBlocks(frame * fr);
	void setBlocks(sf::String name, vector<Object> object);
	//void setBots(sf::String name, vector<Object> object);
	void reloadGame()
	{
		_lvlCounter = 0;
		_Blocks.clear();
		initLevel();
	}
	void initLevel();
	void Draw(sf::RenderWindow& window) {
		lvl.Draw(window);
		///fr.Draw(window);

		for (size_t i = 0; i < _Blocks.size()/*+_bots.size()*/; i++)
		{
			if (_Blocks[i]->getName()!="open") {
				_Blocks[i]->Draw(window);
			}
			//if (!_bots[i]->isDead()){
			//	_bots[i]->Draw(window);
			//}
		}
	}
	int getSize() {
		return _Blocks.size();
	}
	
	void drawAbovePlayer(sf::RenderWindow& window) {
		for (size_t i = 0; i < getSize(); i++)
		{
			if (getName(i) == "open")
			{
				_Blocks[i]->Draw(window);
			}
		}
	}
	void game_map::setSprite();
	void setName(sf::String name, int index);
	void checkCollision(sf::FloatRect & rect);
	frame * getBlock(int index);
	vector<Object>  getBlock(sf::String name);
	sf::FloatRect & getBlockRect(int i);
	sf::String  getName(int i);
	vector<frame*>& getBlock();
	Level & getLevel();
	~game_map() {}
};


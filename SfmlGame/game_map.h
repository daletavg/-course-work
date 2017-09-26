#pragma once
#include "solid.h"
#include "plate.h"
#include"grass.h"
#include "chess.h"
#include"door.h"
#include"nullblock.h"
#include "nextlvl.h"

class game_map
{
private:
	Level lvl;
	int _lvlCounter = 0;
	vector<frame*> _Blocks;
	frame fr;
public:
	game_map()=default;
	sf::FloatRect getSpawn();
	void setBlocks(sf::String name, sf::String image, vector<Object> object, float ImageX, float ImageY, float width, float height);
	void reBlock(frame * fr,int index);
	void loadNextLevel();
	void setBlocks(frame * fr);
	void setBlocks(sf::String name, vector<Object> object);
	void initLevel();
	void Draw(sf::RenderWindow& window) {
		lvl.Draw(window);
		///fr.Draw(window);

		for (size_t i = 0; i < _Blocks.size(); i++)
		{
			if (_Blocks[i]->getName()!="open") {
				_Blocks[i]->Draw(window);
			}
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
	sf::FloatRect & getBlockRect(int i);
	sf::String  getName(int i);
	vector<frame*>& getBlock();
	Level & getLevel();
	~game_map() {}
};


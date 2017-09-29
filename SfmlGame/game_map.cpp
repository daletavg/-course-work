#include "game_map.h"
#include"opensilver.h"
#include"opengold.h"


sf::FloatRect game_map::getSpawn() {
	return lvl.GetObject("spawn").rect;
}
void game_map::setBlocks(sf::String name, sf::String image, vector<Object> object, float ImageX, float ImageY, float width, float height) {
	if (name == "grass") {
		for (size_t i = 0; i < object.size(); i++)
		{
			grass* fr = new grass(name, image, object[i], ImageX, ImageY, width, height);
			_Blocks.push_back(fr);

		}
	}
	if (name == "lockdoor") {
		for (size_t i = 0; i < object.size(); i++)
		{
			lockdoor* fr = new lockdoor(name, image, object[i], ImageX, ImageY, width, height);
			_Blocks.push_back(fr);

		}
	}
	if (name == "silverkey"||name=="goldkey") {
		for (size_t i = 0; i < object.size(); i++)
		{
			key* fr = new key(name, image, object[i], ImageX, ImageY, width, height);
			_Blocks.push_back(fr);

		}
	}
	if (name == "chess") {
		for (size_t i = 0; i < object.size(); i++)
		{
			chess* fr = new chess(name, image, object[i], ImageX, ImageY, width, height);
			_Blocks.push_back(fr);

		}
	}
	if (name=="doorright")
	{
		for (size_t i = 0; i < object.size(); i++)
		{
			door* fr = new door(name, image, object[i], ImageX, ImageY, width, height);
			fr->setOpenDoor(name, image, object[i], 144, 432, width, height);
			_Blocks.push_back(fr);

		}
	}
	if (name == "door")
	{
		for (size_t i = 0; i < object.size(); i++)
		{
			door* fr = new door(name, image, object[i], ImageX, ImageY, width, height);
			fr->setOpenDoor(name, image, object[i], 1200, 48, width, height);
			_Blocks.push_back(fr);

		}
	}
	if (name=="bottleHealth")
	{
		for (size_t i = 0; i < object.size(); i++)
		{
			bottleHealth* fr = new bottleHealth(name, image, object[i], ImageX, ImageY, width, height);
			_Blocks.push_back(fr);

		}
	}
	
}
void game_map::reBlock(frame* fr, int index) {
	_Blocks[index] = fr;
}
void game_map::loadNextLevel()
{
	_lvlCounter++;
	
	_Blocks.clear();
	initLevel();

}
void game_map::setBlocks(frame* fr) {
	_Blocks.push_back(fr);
}
void game_map::setBlocks(sf::String name, vector<Object> object){
	if (name == "solid") {
		for (size_t i = 0; i < object.size(); i++)
		{
			solid* fr = new solid(name, object[i]);
			_Blocks.push_back(fr);

		}
	}
	if (name == "coper") {
		for (size_t i = 0; i < object.size(); i++)
		{
			coper* fr = new coper(name, object[i]);
			_Blocks.push_back(fr);

		}
	}
	if (name == "opensilver") {
		for (size_t i = 0; i < object.size(); i++)
		{
			opensilver* fr = new opensilver(name, object[i]);
			_Blocks.push_back(fr);

		}
	}
	if (name == "opensilverright") {
		for (size_t i = 0; i < object.size(); i++)
		{
			opensilver* fr = new opensilver(name, object[i]);
			_Blocks.push_back(fr);

		}
	}
	if (name == "opengold") {
		for (size_t i = 0; i < object.size(); i++)
		{
			opengold* fr = new opengold(name, object[i]);
			_Blocks.push_back(fr);

		}
	}
	if (name == "opengoldright") {
		for (size_t i = 0; i < object.size(); i++)
		{
			opengold* fr = new opengold(name, object[i]);
			_Blocks.push_back(fr);

		}
	}
	if (name == "endblock") {
		for (size_t i = 0; i < object.size(); i++)
		{
			endblock* fr = new endblock(name, object[i]);
			_Blocks.push_back(fr);

		}
	}
	if (name == "boxbot") {
		for (size_t i = 0; i < object.size(); i++)
		{
			boxbot* fr = new boxbot(name, object[i]);
			_Blocks.push_back(fr);

		}
	}
	if (name == "nextlvl") {
		for (size_t i = 0; i < object.size(); i++)
		{
			nextlvl* fr = new nextlvl(name, object[i]);
			_Blocks.push_back(fr);

		}
	}
	if (name == "plate") {
		for (size_t i = 0; i < object.size(); i++)
		{
			plate* fr = new plate(name, object[i]);
			fr->addPlate(i, "1.png");
			_Blocks.push_back(fr);
		}
	}
	

}

//void game_map::setBots(sf::String name, vector<Object> object)
//{
//	if (name=="foxBot")
//	{
//		for (size_t i = 0; i < object.size(); i++)
//		{
//			foxBot* fox = new foxBot("fox.png", 2, 0, 23, 31, object[i].rect.left, object[i].rect.top);
//			fox->setMap(_gameMap);
//			//fox->serchBotBox();
//			_bots.push_back(fox);
//		}
//	}
//}

void game_map::initLevel()
{
	char tmpString[20];
	Level newLv;
	lvl = newLv;
	sprintf_s(tmpString, "map%i.tmx", _lvlCounter);
	lvl.LoadFromFile(tmpString);
	
	//block tmpBl2("grass","Tileset.png",lvl.GetObjects("grass"), 241, 48, 48, 48);
	//_Blocks.push_back(tmpBl2);
	setBlocks("grass", "Tileset.png", lvl.GetObjects("grass"), 241, 48, 48, 48);
	setBlocks("solid", lvl.GetObjects("solid"));
	setBlocks("plate", lvl.GetObjects("plate"));
	setBlocks("chess", "items.png", lvl.GetObjects("chess"), 123, 43, 40, 39);
	setBlocks("doorright", "Tileset.png", lvl.GetObjects("doorright"), 1008, 48, 48, 48);
	setBlocks("door", "Tileset.png", lvl.GetObjects("door"), 1008, 48, 48, 48);
	setBlocks("nextlvl", lvl.GetObjects("nextlvl"));
	setBlocks("coper", lvl.GetObjects("coper"));
	setBlocks("endblock", lvl.GetObjects("endblock"));
	setBlocks("lockdoor", "Tileset.png", lvl.GetObjects("lockdoor"), 1104, 48, 48, 48);
	setBlocks("silverkey", "items.png", lvl.GetObjects("silverkey"), 51, 43, 21, 36);
	setBlocks("goldkey", "items.png", lvl.GetObjects("goldkey"), 92, 43, 21, 36);
	setBlocks("opensilver", lvl.GetObjects("opensilver"));
	setBlocks("opensilverright", lvl.GetObjects("opensilverright"));
	setBlocks("opengold", lvl.GetObjects("opengold"));
	setBlocks("opengoldright", lvl.GetObjects("opengoldright"));

	setBlocks("boxbot", lvl.GetObjects("boxbot"));
	//setBots("foxBot", lvl.GetObjects("foxBot"));

	//setBlocks("bottleHealth", "items.png", lvl.GetObjects("bottle"), 49, 289, 25, 36);
	//bottleHealth* fr = new bottleHealth("bottleHealth", "items.png", sf::FloatRect(0,0,0,0), 49, 289, 25, 36);
	//_Blocks.push_back(fr);


	setSprite();
}
void game_map::setSprite() {
	for (size_t i = 0; i < _Blocks.size(); i++)
	{
		_Blocks[i]->setSprite();
	}
}
void game_map::setName(sf::String name, int index) {
	_Blocks[index]->setName(name);
}
void game_map::checkCollision(sf::FloatRect& rect) {
	for (size_t i = 0; i < _Blocks.size(); i++)
	{
		//_Blocks[i].checkCollision(rect);
	}
}
frame* game_map::getBlock(int index) {
	
			return _Blocks[index];
	
}
vector<Object> game_map::getBlock(sf::String name)
{
	return lvl.GetObjects(name);
}
sf::FloatRect& game_map::getBlockRect(int i) {
	return _Blocks[i]->getRectPos();
}
sf::String game_map::getName(int i) {
	return _Blocks[i]->getName();
}
vector<frame*>& game_map::getBlock() {
	return _Blocks;

}
Level& game_map::getLevel() {
	return lvl;
}


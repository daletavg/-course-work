#include "block.h"

block::block(sf::String name, vector<Object> object, bool isdrow) {
	setBlock(name, object, isdrow);
}
block::block(sf::String name, sf::String image, vector<Object> object, float ImageX, float ImageY, float width, float height) {
	_Name = name;
	_count = object.size();
	setDraw(true);
	for (size_t i = 0; i < object.size(); i++)
	{
		frame fr;
		fr.setEntity(name, "Tileset.png", ImageX, ImageY, width, height, object[i].rect.left, object[i].rect.top);
		fr.setRectPos(object[i].rect);
		_Frame.push_back(fr);
	}
}

block::block(const block& bl) {
	_Name = bl._Name;
	_Frame = bl._Frame;
	_isDraw = bl._isDraw;
	_count = bl._count;
}

void block::setBlock(sf::String name, vector<Object> object, bool isdrow) {

	_Name = name;
	_count = object.size();
	for (size_t i = 0; i < object.size(); i++)
	{
		frame fr;
		fr.setName(name);
		fr.setPosition(object[i].rect.left, object[i].rect.top);
		fr.setRectPos(object[i].rect);
		_Frame.push_back(fr);
	}
}

void block::setSprite() {
	if (_isDraw == false)
		return;

	for (size_t i = 0; i < _Frame.size(); i++)
	{
		_Frame[i].setSprite();
	}
}
void block::setCollision(bool iscol) {
	for (size_t i = 0; i < _Frame.size(); i++)
	{
		_Frame[i].setCollision(iscol);
	}
}
void block::setCollision(sf::String name, sf::FloatRect rect, bool iscol) {
	for (size_t i = 0; i < _Frame.size(); i++)
	{
		if (rect.intersects(_Frame[i].getRect()))
		{
			_Frame[i].setCollision(iscol);
		}
	}
}

void block::setDraw(bool isdraw) {
	_isDraw = isdraw;
	for (size_t i = 0; i < _Frame.size(); i++)
	{
		_Frame[i].setDraw(isdraw);
	}
}
void block::setDraw(sf::String name, sf::FloatRect rect, bool isDraw) {
	for (size_t i = 0; i < _Frame.size(); i++)
	{
		if (rect.intersects(_Frame[i].getRect()))
		{
			_Frame[i].setDraw(isDraw);
		}
	}
}


bool block::checkCollision(sf::FloatRect& rect) {
	for (size_t i = 0; i < _Frame.size(); i++)
	{
		if (rect.intersects(_Frame[i].getRect())) {
			return _Frame[i].getCollision();
		}
	}
}
sf::FloatRect& block::getBlockRect(int index) {
	return _Frame[index].getRectPos();
}
int block::getCountBlock() {
	return _count;
}

void block::Draw(sf::RenderWindow& window) {

	if (_isDraw) {
		for (size_t i = 0; i < _Frame.size(); i++)
		{
			if (_Frame[i].getDraw()) {
				_Frame[i].Draw(window);
			}
		}
	}
}



block::~block()
{
	//delete[]_Frame;
}

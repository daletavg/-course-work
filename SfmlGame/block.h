#pragma once
#include <vector>
#include "frame.h"
using namespace std;
class block
{
private:
	int _count=0;
	sf::String _Name;
	vector<frame> _Frame;
	bool _isDraw=false;
	
public:
	block() = default;
	block(sf::String name, vector<Object> object, bool isdrow);
	block(sf::String name, sf::String image, vector<Object> object, float ImageX, float ImageY, float width, float height);

	block(const block& bl);
	
	void setBlock(sf::String name, vector<Object> object, bool isdrow);
	
	void setSprite();
	void setCollision(bool iscol);
	void setCollision(sf::String name, sf::FloatRect rect, bool iscol);

	void setDraw(bool isdraw);
	void setDraw(sf::String name, sf::FloatRect rect, bool isDraw);
	

	bool checkCollision(sf::FloatRect& rect);

	sf::FloatRect & getBlockRect(int index);

	int getCountBlock();

	void Draw(sf::RenderWindow& window);
	~block();
};


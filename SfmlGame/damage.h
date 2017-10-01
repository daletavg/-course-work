#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class damage
{
private:
	Clock _dClock;
	bool _Damage=false;
	int _dSec=0;
	int _dSecTmp = 0;
	bool _isSetClock = false;
	bool _isGet=true;
public:
	damage()=default;
	void setDamage();
	void setDamage(bool sd);
	bool getDamage();
	void setRedSprite(Sprite& sp);
};


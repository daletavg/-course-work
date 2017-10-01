#include "damage.h"

void damage::setDamage()
{
	if (!_Damage)
	{
		return;
	}
	
	if (_isSetClock)
	{
		
		_dSec = _dClock.getElapsedTime().asSeconds();
		_isSetClock = false;
	}
	_dSecTmp = _dClock.getElapsedTime().asSeconds();
}

void damage::setDamage(bool sd)
{
	_isGet = false;
	_Damage = sd;
	_isSetClock = sd;
}
bool damage::getDamage() {
	return _isGet;
}

void damage::setRedSprite(Sprite & sp)
{

	if (_Damage)
	{
		if (_dSec+1>=_dSecTmp)
		{
			sp.setColor(Color::Red);
		}
		else
		{
			_isGet = true;
			sp.setColor(Color::White);
			_Damage = false;
			_dClock.restart();
		}
	}
}

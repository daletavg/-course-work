#include "botFox.h"


using namespace sf;

void botFox::moveCharacter()
{
	if (_boxBot->getPlayerX()==getCoordX()&&_boxBot->getPlayerY()==getCoorgY())
	{
		return;
	}
	_distance = sqrt((_boxBot->getPlayerX()-getCoordX())*( _boxBot->getPlayerX() - getCoordX()) + (_boxBot->getPlayerY() - getCoorgY())*( _boxBot->getPlayerY()- getCoorgY()));//считаем дистанцию (длину от точки ј до точки Ѕ). формула длины вектора

	if (_distance > 2) {//этим условием убираем дергание во врем€ конечной позиции спрайта

		_posX += 0.1*(*_time)*( _boxBot->getPlayerX() - getCoordX()) / _distance;//идем по иксу с помощью вектора нормали
		_posY += 0.1*(*_time)*( _boxBot->getPlayerY() - getCoorgY()) / _distance;//идем по игреку так же
	}
	

	update();
}
void botFox::update()
{
	_posX += getDX()*(*_time);
	_posY += getDY()*(*_time);
	
	getSprite().setPosition(_posX, _posY);
	
}
void botFox::searchBoxBot()
{
	for (int i = 0; i < _map->getBlock().size(); i++)//проходимс€ по объектам
	{
		sf::FloatRect rect = getCharacterRect();
		sf::FloatRect rect2 = _map->getBlockRect(i);

		if (rect.intersects(rect2))//провер€ем пересечение игрока с объектом
		{


			if (_map->getName(i) == "boxbot")//если встретили преп€тствие
			{
				boxbot* b = dynamic_cast<boxbot*>(_map->getBlock(i));
				_boxBot = b;
				return;
			}
		}
	}
}

void botFox::addWindow(sf::RenderWindow & window)
{
	_window = &window;
}



void botFox::collision(float Dx, float Dy)//ф ци€ проверки столкновений с картой
{

	for (int i = 0; i < _map->getBlock().size(); i++)//проходимс€ по объектам
	{
		sf::FloatRect rect = getCharacterRect();
		sf::FloatRect rect2 = _map->getBlockRect(i);



		if (rect.intersects(rect2))//провер€ем пересечение игрока с объектом
		{


			if (_map->getName(i) == "solid")//если встретили преп€тствие
			{
				if (Dy > 0) { setPosY(_map->getBlockRect(i).top - (_height));  _dy = 0; }
				if (Dy < 0) { setPosY(_map->getBlockRect(i).top + _map->getBlockRect(i).height); }
				if (Dx > 0) { setPosX(_map->getBlockRect(i).left - (_width)); }
				if (Dx < 0) { setPosX(_map->getBlockRect(i).left + _map->getBlockRect(i).width); }
			}
		}
	}
}


game_map* botFox::getMap() {
	return _map;
}




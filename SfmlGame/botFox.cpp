#include "botFox.h"


using namespace sf;

void botFox::moveCharacter()
{
	update();
}

void botFox::addWindow(sf::RenderWindow & window)
{
	_window = &window;
}



void botFox::collision(float Dx, float Dy)//ф ция проверки столкновений с картой
{

	for (int i = 0; i < _map->getBlock().size(); i++)//проходимся по объектам
	{
		sf::FloatRect rect = getCharacterRect();
		sf::FloatRect rect2 = _map->getBlockRect(i);



		if (rect.intersects(rect2))//проверяем пересечение игрока с объектом
		{


			if (_map->getName(i) == "solid")//если встретили препятствие
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




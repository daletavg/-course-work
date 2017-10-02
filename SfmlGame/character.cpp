#include"character.h"
#include<iostream>

using namespace sf;
using namespace std;

 



void character::setDamageRect(float x, float y, float width, float height)
{
	_damageRect.left = x;
	_damageRect.top = y;
	_damageRect.width = width;
	_damageRect.height = height;
}

void character::updateDamageRect(float x, float y)
{
	_damageRect.left = x;
	_damageRect.top = y;
}

void character::setRotation(DIR dir)
{
	_dir = dir;
}






void character::update() //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
{

	switch (_dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
	{
	case RIGHT: setDX(_Speed); setDY(0); break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
	case LEFT: setDX(-_Speed); setDY(0); break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
	case UP: setDY(-_Speed); setDX(0); break;
	case DOWN: setDY(_Speed); setDX(0);  break;
	}


	addPosX(getDX()*(*_time));
	collision(getDX(), 0);//обрабатываем столкновение по Х
	addPosY(getDY()*(*_time));
	collision(0, getDY());//обрабатываем столкновение по Y
	
	
	_Speed = 0;
	positionSprite(getCoordX(),getCoorgY()); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
	
}
sf::FloatRect character::getCharacterRect() {
	return sf::FloatRect(getCoordX(), getCoorgY(), getWidth(), getHeight());
}

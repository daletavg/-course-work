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






void character::update() //������� "���������" ������� ������. update - ����������. ��������� � ���� ����� SFML , ���������� ���� �������� ����������, ����� ��������� ��������.
{

	switch (_dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
	{
	case RIGHT: setDX(_Speed); setDY(0); break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� �������� ���� ������ ������
	case LEFT: setDX(-_Speed); setDY(0); break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� �������� ���� ������ �����
	case UP: setDY(-_Speed); setDX(0); break;
	case DOWN: setDY(_Speed); setDX(0);  break;
	}


	addPosX(getDX()*(*_time));
	collision(getDX(), 0);//������������ ������������ �� �
	addPosY(getDY()*(*_time));
	collision(0, getDY());//������������ ������������ �� Y
	
	
	_Speed = 0;
	positionSprite(getCoordX(),getCoorgY()); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
	
}
sf::FloatRect character::getCharacterRect() {
	return sf::FloatRect(getCoordX(), getCoorgY(), getWidth(), getHeight());
}

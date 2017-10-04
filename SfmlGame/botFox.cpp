#include "botFox.h"


using namespace sf;

void botFox::moveCharacter()
{
	if (getHp() == 0)
	{
		update();
		return;
	}

	if (_boxBot->getPlayerX()==getCoordX()&&_boxBot->getPlayerY()==getCoorgY())
	{
		return;
	}
	float dd = _boxBot->getPlayerX();
	float ff = getCoordX();
	if ((_boxBot->getPlayerX()+2)>=getCoordX()&& (_boxBot->getPlayerX() - 2) <= getCoordX())
	{
		getSprite().setTextureRect(IntRect(getImageX()+ getWidth(), getImageY(), -getWidth(), getHeight()));
	}
	else if (_boxBot->getPlayerX()<getCoordX())
	{
		CurrentFrame += 0.009*(*_time); 
		setRotation(LEFT);
		if (CurrentFrame > 3) CurrentFrame -= 3; 
		getSprite().setTextureRect(IntRect(25 * int(CurrentFrame)+23, 53 , -23, 31));
		
	}
	else if (_boxBot->getPlayerX()>getCoordX())
	{
		CurrentFrame += 0.009*(*_time); 
		setRotation(RIGHT);
		if (CurrentFrame > 3) CurrentFrame -= 3; 
		getSprite().setTextureRect(IntRect(25 * int(CurrentFrame), 53, 23, 31)); 

	}
	
	_distance = sqrt((_boxBot->getPlayerX()-getCoordX())*( _boxBot->getPlayerX() - getCoordX()) + (_boxBot->getPlayerY() - getCoorgY())*( _boxBot->getPlayerY()- getCoorgY()));//считаем дистанцию (длину от точки А до точки Б). формула длины вектора

	if (_distance > 2) {

		_posX += 0.07*(*_time)*( _boxBot->getPlayerX() - getCoordX()) / _distance;
		_posY += 0.07*(*_time)*( _boxBot->getPlayerY() - getCoorgY()) / _distance;
	}
	

	update();
}
void botFox::update()
{
	/*_posX += getDX()*(*_time);
	_posY += getDY()*(*_time);
	
	getSprite().setPosition(_posX, _posY);*/

	if (isDead())
	{
		setDamage(0);
		
		if (_dethAnim)
		{
			getSprite().setColor(Color::White);
			CurrentFrame += 0.005*(*_time);
			if (CurrentFrame > 5) {
				_dethAnim = false;
				CurrentFrame -= 5;
			}
			getSprite().setTextureRect(IntRect(25 * int(CurrentFrame), 131, 25, 29));
			if (!_dethAnim)
			{
				getSprite().setTextureRect(IntRect(75, 131, 25, 29));
				coins* f = new coins("coins", "items.png", sf::FloatRect(getCoordX(), getCoorgY(), 38, 36), 248, 43, 38, 36);
				_map->setBlocks(f);
			}
			
		}
	}


	character::update();
	updateDamageRect(getCoordX() , getCoorgY());
	
}
void botFox::searchBoxBot()
{
	for (int i = 0; i < _map->getBlock().size(); i++)
	{
		sf::FloatRect rect = getCharacterRect();
		sf::FloatRect rect2 = _map->getBlockRect(i);

		if (rect.intersects(rect2))
		{


			if (_map->getName(i) == "boxbot")
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



void botFox::collision(float Dx, float Dy)
{

	for (int i = 0; i < _map->getBlock().size(); i++)
	{
		sf::FloatRect rect = getCharacterRect();
		sf::FloatRect rect2 = _map->getBlockRect(i);



		if (rect.intersects(rect2))
		{


			if (_map->getName(i) == "solid")
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




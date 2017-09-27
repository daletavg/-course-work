#include "player.h"
using namespace sf;

void player::moveCharacter()
{

		if (Keyboard::isKeyPressed(Keyboard::Left)|| Keyboard::isKeyPressed(Keyboard::A)) {
			setRotation(LEFT);
			setSpeed(0.1);
			CurrentFrame += 0.009*(*_time); //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			
			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к третьему кадру - откидываемся назад.
			getSprite().setTextureRect(IntRect(36 * int(CurrentFrame)+30, 440+ _armorType, -30, 43)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0
			//updateAnimation(5, sf::IntRect rect)
			
		}

		else if (Keyboard::isKeyPressed(Keyboard::Right)|| Keyboard::isKeyPressed(Keyboard::D)) {
			setRotation(RIGHT);
			CurrentFrame += 0.009*(*_time); //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			
			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к третьему кадру - откидываемся назад.
			getSprite().setTextureRect(IntRect(36 * int(CurrentFrame), 440 + _armorType, 30, 43)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0

			setSpeed(0.1);
		}

		else if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
			setRotation(UP);
			setSpeed(0.1);
			CurrentFrame += 0.005*(*_time); //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			
			if (CurrentFrame > 2) CurrentFrame -= 2; // если пришли к третьему кадру - откидываемся назад.
			getSprite().setTextureRect(IntRect(38 * int(CurrentFrame), 693+ _armorType, 32, 42)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0

		}

		else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
			setRotation(DOWN);
			setSpeed(0.1);

			CurrentFrame += 0.009*(*_time); //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации

			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к третьему кадру - откидываемся назад.
			getSprite().setTextureRect(IntRect(36 * int(CurrentFrame ) + 30, 440 + _armorType, -30, 43)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0

		
		}
		update();
}

void player::addWindow(sf::RenderWindow & window)
{
	_window = &window;
}



void player::collision(float Dx, float Dy)//ф ция проверки столкновений с картой
{

	for (int i = 0; i < _map->getBlock().size(); i++)//проходимся по объектам
	{
		sf::FloatRect rect = getCharacterRect();
		sf::FloatRect rect2 = _map->getBlockRect(i);



		if (rect.intersects(rect2))//проверяем пересечение игрока с объектом
		{


			if (_map->getName(i) == "solid")//если встретили препятствие
			{
				if (Dy > 0) { setPosY(_map->getBlockRect(i).top - (_height)) ;  _dy = 0; }
				if (Dy < 0) {setPosY(_map->getBlockRect(i).top + _map->getBlockRect(i).height); }
				if (Dx > 0) { setPosX(_map->getBlockRect(i).left - (_width)) ; }
				if (Dx < 0) { setPosX(_map->getBlockRect(i).left + _map->getBlockRect(i).width); }
			}
			if (_map->getName(i) == "grass")//если встретили препятствие
			{
				std::cout << "grass" << std::endl;
				grass* gr = dynamic_cast<grass*>(_map->getBlock(i));
				gr->setDraw(false);
				_map->reBlock(NullBlock, i);
				delete gr;
			}
			if (_map->getName(i) == "plate") {
				plate* pl = dynamic_cast<plate*>(_map->getBlock(i));
				pl->drawPlate(_window, getCharacterRect().left-400, getCharacterRect().top-300);
			}
			if (_map->getName(i) == "chess") {
				frame* f = _map->getBlock(i);
				chess* ch = dynamic_cast<chess*>(_map->getBlock(i));
				//_map->setBlocks(ch->getItems());
				_map->reBlock(ch->getItems(), i);
				//bottleHealth* fr = new bottleHealth("bottleHealth", "items.png", sf::FloatRect(0, 0, 25, 36), 49, 289, 25, 36);
				
				//_map->setBlocks(fr);
				//delete f;
			}
			if (_map->getName(i) == "bottleHealth") {
				frame* f = _map->getBlock(i);
				bottleHealth* ch = dynamic_cast<bottleHealth*>(_map->getBlock(i));
				if (Keyboard::isKeyPressed(Keyboard::E))
				{
					addHealth(ch->getBuff());
					_map->reBlock(NullBlock, i);
				}
				
			}
			if (_map->getName(i) == "coins") {
				frame* f = _map->getBlock(i);
				coins* ch = dynamic_cast<coins*>(_map->getBlock(i));
				if (Keyboard::isKeyPressed(Keyboard::E))
				{
					addScore(ch->getCoins());
					_map->reBlock(NullBlock, i);
				}
				
			}
			if (_map->getName(i) == "hauberkArmor") {
				frame* f = _map->getBlock(i);
				hauberkArmor * h = dynamic_cast<hauberkArmor *>(_map->getBlock(i));
				if (h->checkArmor(*_window, getArmor(), getCoordX(), getCoorgY())) {

					if (Keyboard::isKeyPressed(Keyboard::E))
					{
						addArmor(h->getArmor());
						setArmorType(h->getArmorType());
						_map->reBlock(NullBlock, i);

					}
				}
			}
			if (_map->getName(i)=="doorright"|| _map->getName(i) == "door"){
				door* dr= dynamic_cast<door*>(_map->getBlock(i));
				dr->setOpen(true);
			}
			if (_map->getName(i) == "boxbot") {

				boxbot * h = dynamic_cast<boxbot *>(_map->getBlock(i));
				if (h == NULL)
				{
					continue;
				}
				h->setPlayerCoord(getCoordX() + (getWidth() / 2), getCoorgY() + (getHeight() / 2));

			}
			if (_map->getName(i) == "nextlvl")
			{
				if (Keyboard::isKeyPressed(Keyboard::E))
				{
					_map->loadNextLevel();
					setRotation(RIGHT);
					drawInNewPosition(_map->getSpawn().left, _map->getSpawn().top);
					_bots->loadNextLevel();
					
					return;
				}
			}
			


		}
	}
}


game_map* player::getMap() {
	return _map;
}



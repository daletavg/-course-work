#include "player.h"
#include"opensilver.h"
#include"opengold.h"
using namespace sf;

void player::moveCharacter()
{
	if (getHp()==0)
	{
		update();
		return;
	}
	_Damage = false;
	if (getDamage()==25)
	{
		if (Keyboard::isKeyPressed(Keyboard::LControl))
		{
			for (size_t i = 0; i <2; i++)
			{
				CurrentFrame += 0.003*(*_time); 

				if (CurrentFrame > 2) CurrentFrame -= 2; 
				getSprite().setTextureRect(IntRect(40 * int(CurrentFrame), 879 + _armorType, 40, 47)); 
				_Damage = true;
				update();
				Draw(*_window);
			}
		
			return;
		}
		
	}
	

		if (Keyboard::isKeyPressed(Keyboard::Left)|| Keyboard::isKeyPressed(Keyboard::A)) {
			setRotation(LEFT);
			setSpeed(0.1);
			CurrentFrame += 0.009*(*_time); 
			_DamageBlock.setDamage();
			_DamageBlock.setRedSprite(getSprite());
			if (CurrentFrame > 5) CurrentFrame -= 5; 
			getSprite().setTextureRect(IntRect(36 * int(CurrentFrame)+30, 440+ _armorType, -30, 43));
			update();
			return;
		}

		else if (Keyboard::isKeyPressed(Keyboard::Right)|| Keyboard::isKeyPressed(Keyboard::D)) {
			setRotation(RIGHT);
			CurrentFrame += 0.009*(*_time); 
			
			if (CurrentFrame > 5) CurrentFrame -= 5; 
			getSprite().setTextureRect(IntRect(36 * int(CurrentFrame), 440 + _armorType, 30, 43)); 
			_DamageBlock.setDamage();
			_DamageBlock.setRedSprite(getSprite());
			setSpeed(0.1);
			update();
			return;
		}

		else if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
			setRotation(UP);
			setSpeed(0.1);
			CurrentFrame += 0.005*(*_time); 
			_DamageBlock.setDamage();
			_DamageBlock.setRedSprite(getSprite());
			if (CurrentFrame > 2) CurrentFrame -= 2; 
			getSprite().setTextureRect(IntRect(38 * int(CurrentFrame), 693+ _armorType, 32, 42)); 
			update();
			return;
		}

		else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
			setRotation(DOWN);
			setSpeed(0.1);

			CurrentFrame += 0.009*(*_time);
			_DamageBlock.setDamage();
			_DamageBlock.setRedSprite(getSprite());
			if (CurrentFrame > 5) CurrentFrame -= 5; 
			getSprite().setTextureRect(IntRect(36 * int(CurrentFrame ) + 30, 440 + _armorType, -30, 43)); 
			update();
			return;
		
		}
		_DamageBlock.setDamage();
		_DamageBlock.setRedSprite(getSprite());
		getSprite().setTextureRect(IntRect(getImageX(), getImageY() + _armorType, getWidth(), getHeight()));
		update();
}

void player::update()
{
	if (isDead())
	{
		if (_dethAnim)
		{
				getSprite().setColor(Color::White);
				CurrentFrame += 0.005*(*_time);
				if (CurrentFrame > 5) { 
					_dethAnim = false;
					CurrentFrame -= 5; 
				} 
				getSprite().setTextureRect(IntRect(36 * int(CurrentFrame), 823 , 25, 43)); 
				if (!_dethAnim)
				{
					getSprite().setTextureRect(IntRect(146, 822, 25, 43));
				}
		}
																									 
	}
	else
	{
		character::update();
		updateDamageRect(getCoordX() - 2, getCoorgY() - 2);
	}
}

void player::addWindow(sf::RenderWindow & window)
{
	_window = &window;
}
frame* player::getInventary()
{
	return _block;
}


void player::collision(float Dx, float Dy)
{
	for (size_t j = 0; j < _bots->getBots().size(); j++)
	{
		sf::FloatRect rect = getDamageRect();
		sf::FloatRect rect2 = _bots->getDamageRect(j);
		if (rect.intersects(rect2))
		{
			
			if (_Damage)
			{
				_Damage = false;
				_bots->getBot(j)->addHealth(-getDamage());
			}
		}
	}

	for (int i = 0; i < _map->getBlock().size(); i++)
	{
		sf::FloatRect rect = getCharacterRect();
		sf::FloatRect rect2 = _map->getBlockRect(i);



		if (rect.intersects(rect2))
		{


			if (_map->getName(i) == "solid"|| _map->getName(i) == "lockdoor")
			{
				if (Dy > 0) { setPosY(_map->getBlockRect(i).top - (_height)) ;  _dy = 0; }
				if (Dy < 0) {setPosY(_map->getBlockRect(i).top + _map->getBlockRect(i).height); }
				if (Dx > 0) { setPosX(_map->getBlockRect(i).left - (_width)) ; }
				if (Dx < 0) { setPosX(_map->getBlockRect(i).left + _map->getBlockRect(i).width); }
			}
			if (_map->getName(i) == "grass")
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
		
				_map->reBlock(ch->getItems(), i);
				
			}
			if (_map->getName(i) == "bottleHealth") {
				
				bottleHealth* ch = dynamic_cast<bottleHealth*>(_map->getBlock(i));
				ch->Draw(*_window, getCoordX(), getCoorgY());
				if (Keyboard::isKeyPressed(Keyboard::E))
				{
					addHealth(ch->getBuff());
					_map->reBlock(NullBlock, i);
				}
				if (_inventaryCount <4)
				{
					if (Keyboard::isKeyPressed(Keyboard::F))
					{
						_block = ch;
						_map->reBlock(NullBlock, i);

					}
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
				hauberkArmor * h = dynamic_cast<hauberkArmor *>(_map->getBlock(i));
				if (h->checkArmor(*_window, getArmor(), getCoordX(), getCoorgY())) {

					if (Keyboard::isKeyPressed(Keyboard::E))
					{
						addArmor(h->getArmor());
						setArmorType(h->getArmorType());
						_map->reBlock(NullBlock, i);

					}
				}
				if (_inventaryCount >= !4)
				{
					if (Keyboard::isKeyPressed(Keyboard::F))
					{
						_block = h;
						_map->reBlock(NullBlock, i);

					}
				}
			}
			if (_map->getName(i) == "goldkey") {
				_map->reBlock(NullBlock, i);
				_keys.gold = true;
			}
			if (_map->getName(i) == "silverkey") {
				_map->reBlock(NullBlock, i);
				_keys.silver = true;
			}
			if (_map->getName(i) == "opensilver"|| _map->getName(i) == "opensilverright") {
				opensilver * h = dynamic_cast<opensilver *>(_map->getBlock(i));
				if (Keyboard::isKeyPressed(Keyboard::E))
				{
					if (h->isOpen(*_window, _keys.silver,getCoordX(),getCoorgY(), _map))
					{
						_map->reBlock(NullBlock, i);
					}
				}

			}
			if (_map->getName(i) == "opengold" || _map->getName(i) == "opengoldright") {
				opengold * h = dynamic_cast<opengold *>(_map->getBlock(i));
				if (Keyboard::isKeyPressed(Keyboard::E))
				{
					if (h->isOpen(*_window, _keys.gold,getCoordX(),getCoorgY(), _map))
					{
						_map->reBlock(NullBlock, i);
					}
				}

			}
			if (_map->getName(i) == "sword") {
				sword * h = dynamic_cast<sword *>(_map->getBlock(i));
				if (h->checkSword(*_window, getDamage(), getCoordX(), getCoorgY())) {

					if (Keyboard::isKeyPressed(Keyboard::E))
					{
						setDamage(h->getDamage());
						_map->reBlock(NullBlock, i);

					}
				}
			}
			if (_map->getName(i) == "coper") {
				if (_DamageBlock.getDamage())
				{
					_DamageBlock.setDamage(true);
					coper* ch = dynamic_cast<coper*>(_map->getBlock(i));
					addHealth(ch->getDamage());
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
				h->setPlayerCoord(getCoordX() + getWidth(), getCoorgY() + 2);

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
			if (_map->getName(i) == "endblock")
			{
				if (Keyboard::isKeyPressed(Keyboard::E))
				{
					endblock* dr = dynamic_cast<endblock*>(_map->getBlock(i));
					setIsEnd(dr->getEnd());

					return;
				}
			}


		}
	}

	

}


game_map* player::getMap() {
	return _map;
}



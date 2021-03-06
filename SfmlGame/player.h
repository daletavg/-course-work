#pragma once
#include "character.h"
#include"enamies.h"
#include"damage.h"

class player :
	public character
{
	struct keys
	{
		bool silver = false;
		bool gold = false;
	};
	
private:
	sf::RenderWindow* _window;
	float CurrentFrame = 0;
	armors _armorType = leather;
	int _armor = 0;
	enamies* _bots;

	bool _dethAnim = true;
	bool _isEnd=false;
	bool _Damage = false;


	damage _DamageBlock;
	damage _DamageBot;

	frame* _block=NullBlock;
	int _inventaryCount = 0;

	keys _keys;

public:
	player() = default;
	player(sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy)
		:character("player",image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy){
		setDamageRect(getCoordX() - 2, getCoorgY() - 2, getWidth() + 2, getHeight() + 2);
	}
	void setPlayer(sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy) {
		setCharacter("player", image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy);
		setDamageRect(getCoordX() - 2, getCoorgY() - 2, getWidth() + 2, getHeight() + 2);
	}
	void setIsEnd(bool isend) {
		_isEnd = isend;
	}
	bool isEnd() {
		return _isEnd;
	}
	void reloadGame()
	{
		_Damage = false;
		setDamage(0);
		_map->reloadGame();
		setRotation(RIGHT);
		drawInNewPosition(_map->getSpawn().left, _map->getSpawn().top);
		setScore(0);
		_armor = 0;
		setDead(false);
		_dethAnim = true;
		_armorType = leather;
		setDefault();
		setHP(70);
		_bots->loadNextLevel();
	}
	void setEnamies(enamies* en) {
		_bots = en;
	}
	virtual void moveCharacter() override;
	void update();
	void setArmorType(armors arm)
	{
		_armorType = arm;
	}
	void setArmor(int arm)
	{
		_armor = arm;
	}
	void addArmor(int arm)
	{
		
		if (_armor+arm<=0)
		{
			_armorType = leather;
			_armor = 0;
			return;
		}
		_armor += arm;
	}
	int getArmor()
	{
		return _armor;
	}
	armors getArmorType()
	{
		return _armorType;
	}
	void addWindow(sf::RenderWindow& window);
	frame * getInventary();
	void setInventory(int count)
	{
		_inventaryCount = count;
		_block = NullBlock;
	}
	void collision(float Dx, float Dy);
	void drawInNewPosition(float X, float Y)
	{
		setPosition(X, Y);
		getSprite().setPosition(X, Y);
	}



	game_map * getMap();

};


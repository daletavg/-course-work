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

	damage _Damage;


	keys _keys;

public:
	player() = default;
	player(sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy)
		:character("player",image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy){
		
	}
	void setPlayer(sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy) {
		setCharacter("player", image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy);
		
	}
	void setIsEnd(bool isend) {
		_isEnd = isend;
	}
	bool isEnd() {
		return _isEnd;
	}
	void reloadGame()
	{
		_map->reloadGame();
		setRotation(RIGHT);
		drawInNewPosition(_map->getSpawn().left, _map->getSpawn().top);
		setScore(0);
		_armor = 0;
		setDead(false);
		_dethAnim = true;
		_armorType = leather;
		setDefault();
		addHealth(100);
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
	void addArmor(int arm)
	{
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
	void collision(float Dx, float Dy);
	void drawInNewPosition(float X, float Y)
	{
		setPosition(X, Y);
		getSprite().setPosition(X, Y);
	}



	game_map * getMap();

};


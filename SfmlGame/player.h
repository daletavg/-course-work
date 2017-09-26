#pragma once
#include "character.h"

class player :
	public character
{
private:
	sf::RenderWindow* _window;
	float CurrentFrame = 0;
	armors _armorType = leather;
	int _armor = 0;
public:
	player() = default;
	player(sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy)
		:character("player",image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy){}
	void setPlayer(sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy) {
		setCharacter("player", image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy);
	}
	virtual void moveCharacter() override;
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


	
	~player(); 
};


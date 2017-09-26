#pragma once


#include"game_map.h"
enum DIR {
	RIGHT, LEFT, UP, DOWN
};


class character:public entity
{
private:
	
	
	float _scaleW = 0, _scaleH=0;

	int _coins = 0;

	int _HP = 100;
	float _Speed;
	int _Damage;
	int _Score=0;
	
	

	DIR _dir;
protected:
	game_map* _map;
	void setCharacter(sf::String name, sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy) {
		setEntity(name, image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy);
		setSprite();
	}
public:
	character() = default;
	character(sf::String name,sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy)
		:entity(name,image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy) {}
	
	virtual void addScale(float W, float H)
	{
		_scaleW = _width*W;
		_scaleH = _height*H;
	}
	void addScore(int sc)
	{
		_Score += sc;
	}
	void setRotation(DIR dir);
	void setSpeed(float speed) {
		_Speed = speed;
	}
	void setMap(game_map* mp) {
		_map = mp;
	}

	virtual void collision(float Dx, float Dy)=0;
	void update();

	sf::FloatRect getCharacterRect();
	
	sf::FloatRect getRectWithScale()
	{
		return sf::FloatRect(_posX, _posY, _width + _scaleW, _height + _scaleH);

	}

	virtual void moveCharacter() = 0;
	void addHealth(int hp)
	{
		if (_HP + hp >= 200)
		{
			_HP = 200;
			return;

		}
		_HP += hp;
	}
	
	int getHp() {
		return _HP;
	}
	int getScore(){
		return _Score;
	}


	
	
};

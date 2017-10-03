#pragma once


#include"game_map.h"
enum DIR {
	RIGHT, LEFT, UP, DOWN
};


class character:public entity
{
private:
	sf::FloatRect _damageRect;
	
	float _scaleW = 0, _scaleH=0;

	int _coins = 0;

	int _HP = 100;
	float _Speed;
	int _Damage=0;
	int _Score=0;
	bool _isDead = false;
	

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
	
	void setDamageRect(float x, float y, float width, float height);
	void updateDamageRect(float x, float y);
	sf::FloatRect getDamageRect()
	{
		return _damageRect;
	}

	virtual void addScale(float W, float H)
	{
		_scaleW = _width*W;
		_scaleH = _height*H;
	}
	void setHP(int hp)
	{
		_HP = hp;
	}
	void setDamage(int damage)
	{
		_Damage = damage;
	}
	
	int getDamage()
	{
		return _Damage;
	}
	void setDead(bool de) 
	{
		_isDead = de;
	}
	void setScore(int sc)
	{
		_Score = sc;
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
	bool isDead() {
		return _isDead;
	}

	virtual void collision(float Dx, float Dy)=0;
	virtual void update();

	sf::FloatRect getCharacterRect();
	
	sf::FloatRect getRectWithScale()
	{
		return sf::FloatRect(_posX, _posY, _width + _scaleW, _height + _scaleH);

	}

	virtual void moveCharacter() = 0;
	bool addHealth(int hp)
	{
		if (_HP+hp<=0)
		{
			_HP = 0;
			_isDead = true;
			return false;
		}
		if (_HP + hp >= 130)
		{
			_HP = 130;
			return true;

		}
		_HP += hp;
		return true;
	}
	
	int getHp() {
		return _HP;
	}
	int getScore(){
		return _Score;
	}


	
	
};


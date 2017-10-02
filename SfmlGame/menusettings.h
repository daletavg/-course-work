#pragma once
#include <SFML/Graphics.hpp>
#include<SFML\Audio.hpp>
using namespace sf;
#include <iostream>
using namespace std;


class menusettings
{
private:
	
	RenderWindow* _window;

	Sprite* _imgSprite;

	Music* _music;

	Font _font;
	Font _font2;
	Text _videoSText;
	float _xVideo = 310, _yVideo = 100;
	Text _sizeSText;
	float _xSize = 330, _ySize = 150;

	Text _leftSText;
	Text _rightStext;
	float _xLeft = 310, _xRight = 485, _yLeftRight = 150;

	Text _musicSText;
	Text _onoffSText;
	float _xMusic = 335,  _yMusicOnOff = 200;
	Text _leftMSText;
	Text _righMtStext;
	float _xLeftM = 310, _xRightM = 485, _xOnoff = 380, _yLeftRightM = 250;
	Text _backSText;
	float _xBack = 350, _yBack = 300;



	int _sizeMod = 1;
public:
	menusettings();
	void setSpriteBorder(Sprite& _sprite);
	void loadMenu();
	void addPosition(float x, float y);
	void setMusic(Music& music);
	void setFont();
	void setText();
	void Draw(RenderWindow& window);
	void setRenderWindow(RenderWindow& window);
	

	int menuGame();
	bool isBiger();
	

};



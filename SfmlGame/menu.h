#pragma once
#include "menusettings.h"

class menu 
{
private:
	RenderWindow* _window;
	menusettings _settings;

	Image _back;
	Texture _backText;
	Sprite _backSprite;

	Image _img;
	Texture _imgText;
	Sprite _imgSprite;


	Font _font;
	
	Text _newGText;
	float _xNew = 305, _yNew = 100;
	Text _settingsGText;
	float _xSettings = 300, _ySettings = 150;
	Text _exitGText;
	float _xExit = 350, _yExit = 200;

	bool _isSettings=false;
	int menuNum;
public:
	menu();
	void loadMenu();

	void Draw(RenderWindow& window);
	void setRenderWindow(RenderWindow& window);
	
	bool isBigerWindow();
	
	void addPosition(float x, float y);
	

	int menuGame();
	
};


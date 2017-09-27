#pragma once
#include "character.h"
#include"boxbot.h"

class botFox :
	public character
{
private:
	sf::RenderWindow* _window;
	float CurrentFrame = 0;
	boxbot* _boxBot;

	int _tempX = 0;
	int _tempY = 0;
	float _distance = 0;

public:
	botFox() = default;
	botFox(sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy)
		:character("botFox", image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy) {}
	void setBot(sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy) {
		setCharacter("botFox", image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy);
	}
	virtual void moveCharacter() override;
	void update();
	void searchBoxBot();
	void addWindow(sf::RenderWindow& window);
	void collision(float Dx, float Dy);
	void init() {
		_boxBot->setPlayerCoord(getCoordX(),getCoorgY());
	}


	game_map * getMap();

};
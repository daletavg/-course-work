#pragma once
#include "character.h"
class botFox :
	public character
{
private:
	sf::RenderWindow* _window;
	float CurrentFrame = 0;

public:
	botFox() = default;
	botFox(sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy)
		:character("botFox", image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy) {}
	void setBot(sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy) {
		setCharacter("botFox", image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy);
	}
	virtual void moveCharacter() override;
	
	void addWindow(sf::RenderWindow& window);
	void collision(float Dx, float Dy);



	game_map * getMap();

};
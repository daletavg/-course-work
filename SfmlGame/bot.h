#pragma once
#include "character.h"
class bot :
	public character
{
public:
	bot(sf::String name, sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy)
		:character(name, image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy) {}
	void setPlayer(sf::String name, sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy) {
		setCharacter(name, image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy);
	}
	void virtual moveCharacter() override;
	~bot();
};


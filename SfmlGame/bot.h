#pragma once
#include<SFML\Graphics.hpp>
#include "character.h"
class bot :
	public character
{
public:
	bot(sf::String name, sf::String image, float posImageCharacterX, float posImageCharacterY, float widthImageCharacter, float heightImageCharacter, float posx, float posy) :
		character(name, image, posImageCharacterX, posImageCharacterY, widthImageCharacter, heightImageCharacter, posx, posy) {}
	
	virtual void moveCharacter() {

	}

};


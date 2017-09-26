#pragma once
#include <SFML/Graphics.hpp>


class view
{
private:
	sf::View _view;
public:
	view();
	void getCoord(float x, float y);
	void setView(sf::RenderWindow& window);
	sf::Vector2f getVeiw();
	float getViewX();
	float getViewY();
	

};


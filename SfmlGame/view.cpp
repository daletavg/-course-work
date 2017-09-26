#include "view.h"





view::view()
{
	_view.reset(sf::FloatRect(0, 0, 800, 600));
}
void view::getCoord(float x, float y)
{
	_view.setCenter(x, y);
}
void view::setView(sf::RenderWindow & window)
{
	window.setView(_view);

}
sf::Vector2f view::getVeiw() 
{
	return _view.getCenter();
}
float view::getViewX()
{
	return _view.getCenter().x;
}
float view::getViewY()
{
	return _view.getCenter().y;
}

#pragma once
#include<SFML\Graphics.hpp>


class animation 
{

private:

	int _currentFrame = 0;
	float _speedAnim = 0;
	sf::Sprite* _sprite;
	float* _time;
public:
	animation()=default;
	void setSprite(sf::Sprite& sprite);
	
	void setSpeedAnim(float speedAnim)
	{
		_speedAnim = speedAnim;
	}
	void setTime(float* time)
	{
		_time = time;
	}
	void updateAnimation(int countfr,float* time, sf::IntRect rect)
	{
		
			_currentFrame += _speedAnim*(*time); 
			if (_currentFrame >countfr) _currentFrame -= countfr;
			_sprite->setTextureRect(sf::IntRect(rect.left * int(_currentFrame), rect.top, rect.width, rect.height));
			
		
	}
};


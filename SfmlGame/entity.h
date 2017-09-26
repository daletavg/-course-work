#pragma once

#include"level.h"
#include<iostream>



class entity
{
protected:
	
	sf::Image  _Image;
	sf::Texture _Texture;
	sf::Sprite _Sprite;

	float _posX = 0, _posY = 0;
	float _width = 0, _height = 0;
	float _imageX = 0, _imageY = 0;
	sf::FloatRect _rectImage;
	float _dx = 0, _dy = 0;

	float* _time;

	
	sf::String  _pathImage;
	sf::String _Name;

	entity& forcopy(entity& en) {
		setEntity(en._Name, en._pathImage, en._imageX, en._imageY, en._width, en._height, en._posX, en._posY);
		return *this;
	}

public:
	entity() = default;
	entity(sf::String name, sf::String image, float ImageX, float ImageY, float width, float height, float posx, float posy)
	{
		//setName(name);
		//setImage(image);
		//setPosition(posx, posy);
		//setImagePos(ImageX, ImageY, width, height);
		
		setEntity(name, image, ImageX, ImageY, width, height, posx, posy);
		setSprite();
	}
	void setEntity(sf::String name,sf::String image, float ImageX, float ImageY, float width, float height, float posx, float posy) //constructor
	{
		setName(name);
		setImage(image);
		setPosition(posx, posy);
		setImagePos(ImageX, ImageY, width, height);
	}
	void setName(sf::String name) {
		_Name = name;
	}
	void setImage(sf::String images)
	{
		_pathImage = images;
		_Image.loadFromFile("image//" + images);
	}
	void setPosition(int posx, int posy)
	{
		_posX = posx;
		_posY = posy;

	}
	void setImagePos(float posImageX, float posImageY, int  widthImage, int heightImage)
	{
		_imageX = posImageX; _imageY = posImageY;
		_width = widthImage; _height = heightImage;
		setRect();
	}
	void setRect()
	{
		_rectImage = sf::FloatRect(_posX, _posY, _width, _height);
	}
	void setRect(sf::FloatRect rect) {
		_rectImage = rect;
		_width = rect.width;
		_height = rect.height;
		_posX = rect.left;
		_posY = rect.top;
	}
	void setPosX(float x) {
		_posX = x;
	}
	void setPosY(float y) {
		_posY = y;
	}
	void addPosX(float x) {
		_posX += x;
	}
	void addPosY(float y) {
		_posY += y;
	}

	void setDX(float dx) {
		_dx = dx;
	}
	void setDY(float dy) {
		_dy = dy;
	}
	float getDX() {
		return _dx;
	}
	float getDY() {
		return _dy;
	}
	void setSprite()
	{
		
		
		_Texture.loadFromImage(_Image);
		_Sprite.setTexture(_Texture);
		_Sprite.setPosition(_posX, _posY);
		_Sprite.setTextureRect(sf::IntRect(_imageX, _imageY, _width, _height));
	}
	virtual void setSprite(float pX, float pY) {
		_Sprite.setPosition(pX, pY);
		_rectImage.left = pX;
		_rectImage.top = pY;
		_posX = pX;
		_posY = pY;
	}
	void setTime(float* time)
	{
		_time = time;
	}
	void setScale(float a, float b)
	{
		_Sprite.setScale(a, b);
	}
	
	float getCoordX()const
	{

		//std::cout << "X: " << _posX << "\t";
		return _posX;
	}
	float getCoorgY()const
	{
		//std::cout << "Y: " << _posY << std::endl;
		return _posY;
	}
	void positionSprite(float x, float y) {
		_Sprite.setPosition(x, y);
	}
	sf::Sprite & getSprite()
	{
		return _Sprite;
	}
	virtual sf::FloatRect getRect()
	{//ф-ция получения прямоугольника. его коорд,размеры (шир,высот).
		return _rectImage;//эта ф-ция нужна для проверки столкновений 
	}
	float getWidth() {
		return _width;
	}
	float getHeight() {
		return _height;
	}
	virtual void Draw(sf::RenderWindow& window) {
		window.draw(_Sprite);
	}

	entity& operator =(entity& en) {
		return forcopy(en);
	}
	sf::String getName() {
		return _Name;
	}
};


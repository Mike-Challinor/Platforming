#pragma once

class Player
{
private:

	//PLAYER
	sf::Sprite sprite;
	sf::Texture textureSheet;

	//ANIMATION

	//MOVEMENT

	//CORE

	//PRIVATE FUNCTIONS
	void initTexture();
	void initSprite();

public:

	//CONSTRUCTORS AND DESTRUCTORS
	Player();
	virtual ~Player();

	//PUBLIC FUNCTIONS

	//UPDATES
	void update();

	//RENDERS
	void render(sf::RenderTarget& target);
};


#pragma once

class Player
{
private:

	//PLAYER
	sf::Sprite sprite;
	sf::Texture textureSheet;

	//ANIMATION
	sf::IntRect currentFrame;

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
	void updateMovement();
	void update();

	//RENDERS
	void render(sf::RenderTarget& target);
};


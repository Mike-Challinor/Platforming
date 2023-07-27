#pragma once

class Player
{
private:

	//TIMERS
	sf::Clock animationTimer;

	//PLAYER SPRITES AND TEXTURE
	sf::Sprite sprite;
	sf::Texture textureSheet;

	//ANIMATION
	sf::IntRect currentFrame;

	//MOVEMENT
	bool moving;

	//CORE

	//PRIVATE FUNCTIONS
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();

public:

	//CONSTRUCTORS AND DESTRUCTORS
	Player();
	virtual ~Player();

	//PUBLIC FUNCTIONS

	//UPDATES
	void updateMovement();
	void updateAnimations();
	void update();

	//RENDERS
	void render(sf::RenderTarget& target);
};


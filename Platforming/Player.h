#pragma once

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING};

class Player
{
private:

	//TIMERS
	sf::Clock animationTimer;

	//PLAYER SPRITES AND TEXTURE
	sf::Sprite sprite;
	sf::Texture textureSheet;

	//ANIMATION
	short animState;
	sf::IntRect currentFrame;

	//PHYSICS
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;

	//CORE

	//PRIVATE FUNCTIONS
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
	void initPhysics();

public:

	//CONSTRUCTORS AND DESTRUCTORS
	Player();
	virtual ~Player();

	//PUBLIC FUNCTIONS
	void move(const float dir_x, const float dir_y);

	//UPDATES
	void updatePhysics();
	void updateMovement();
	void updateAnimations();
	void update();

	//RENDERS
	void render(sf::RenderTarget& target);
};


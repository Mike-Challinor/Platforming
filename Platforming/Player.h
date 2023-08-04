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
	bool animationSwitch;

	//PHYSICS
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

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

	//ACCESSORS
	const bool& getAnimSwitch();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getBounds() const;

	//MODIFIERS
	void setPosition(const float x, const float y);
	void resetVelocityY();

	//PUBLIC FUNCTIONS
	void move(const float dir_x, const float dir_y);
	void resetAnimationTimer();

	//UPDATES
	void updatePhysics();
	void updateMovement();
	void updateAnimations();
	void update();

	//RENDERS
	void render(sf::RenderTarget& target);
};


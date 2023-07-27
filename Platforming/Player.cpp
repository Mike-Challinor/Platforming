#include "stdafx.h"
#include "Player.h"

//PRIVATE FUNCTIONS

void Player::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("Textures/player_sheet.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURES:: player_sheet failed to load" << std::endl;
	}

	else
	{
		std::cout << "TASK::PLAYER::INITTEXTURES:: player_sheet succesfully loaded" << std::endl;
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 40, 50);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(4.5f, 4.5f);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

//CONSTRUCTORS AND DESTRUCTORS

Player::Player()
{

	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Player::~Player()
{
	
}

//PUBLIC FUNCTIONS

//UPDATES

void Player::updateMovement()
{

	this->animState = PLAYER_ANIMATION_STATES::IDLE;

	//Move left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->sprite.move(-1.5f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}

	//Move right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->sprite.move(1.5f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}

}

void Player::updateAnimations()
{

	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			//IDLE ANIMATION
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 40.f;

			if (this->currentFrame.left >= 160.f)
			{
				this->currentFrame.left = 0;
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}

	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			//MOVING RIGHT ANIMATION
			this->currentFrame.top = 50.f;
			this->currentFrame.left += 40.f;

			if (this->currentFrame.left >= 360.f)
			{
				this->currentFrame.left = 0;
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}

	else
	{
		this->animationTimer.restart();
	}

	

}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
}

void Player::updatePhysics()
{

}

//RENDERS

void Player::render(sf::RenderTarget& target)
{
	
	target.draw(this->sprite);
}

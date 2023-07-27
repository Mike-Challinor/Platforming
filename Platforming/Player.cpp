#include "stdafx.h"
#include "Player.h"

//PRIVATE FUNCTIONS

void Player::initVariables()
{
	this->moving = false;
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
	this->sprite.setScale(2.5f, 2.5f);
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
	this->moving = false;

	//Move left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->sprite.move(-1.f, 0.f);
		this->moving = true;
	}

	//Move right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->sprite.move(1.f, 0.f);
		this->moving = true;
	}

	//Move down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->sprite.move(0.f, 1.f);
		this->moving = true;
	}

	//Move up
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->sprite.move(0.f, -1.f);
		this->moving = true;
	}
}

void Player::updateAnimations()
{

	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
	{
		//IDLE ANIMATION
		if (this->moving == false)
		{
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left >= 160.f)
			{
				this->currentFrame.left = 0;
			}

		}

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}

}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
}

//RENDERS

void Player::render(sf::RenderTarget& target)
{
	
	target.draw(this->sprite);
}

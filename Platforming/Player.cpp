#include "stdafx.h"
#include "Player.h"

//PRIVATE FUNCTIONS

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
	this->currentFrame = sf::IntRect(0, 0, 32, 48);
	this->sprite.setTextureRect(this->currentFrame);
}

//CONSTRUCTORS AND DESTRUCTORS

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
	
}

//PUBLIC FUNCTIONS

//UPDATES

void Player::updateMovement()
{
	bool movingLeft;
	//Move left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->sprite.move(-1.f, 0.f);
	}

	//Move right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->sprite.move(1.f, 0.f);
	}

	//Move down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->sprite.move(0.f, 1.f);
	}

	//Move up
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->sprite.move(0.f, -1.f);
	}
}

void Player::update()
{
	this->updateMovement();
}

//RENDERS

void Player::render(sf::RenderTarget& target)
{
	
	target.draw(this->sprite);
}

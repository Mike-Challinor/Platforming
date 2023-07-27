#include "stdafx.h"
#include "Player.h"

//PRIVATE FUNCTIONS

void Player::initTexture()
{
}

void Player::initSprite()
{

}

//CONSTRUCTORS AND DESTRUCTORS

Player::Player()
{
	void initTexture();
	void initSprite();
}

Player::~Player()
{
}

//PUBLIC FUNCTIONS

//UPDATES

void Player::update()
{
}

//RENDERS

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

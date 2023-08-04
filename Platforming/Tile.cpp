#include "stdafx.h"
#include "Tile.h"

//CONSTRUCTORS AND DESTRUCTORS

Tile::Tile(sf::Texture& texture_sheet, sf::IntRect texture_rect, bool damaging) : damaging(damaging)
{
	this->sprite.setTexture(texture_sheet);
	this->sprite.setTextureRect(texture_rect);

}

//PUBLIC FUNCTIONS

//ACCESSORS

const sf::FloatRect Tile::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

//UPDATES

void Tile::update()
{

}

//RENDERS

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}


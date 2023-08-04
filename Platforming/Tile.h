#pragma once

class Tile
{
private:
	sf::Sprite sprite;
	const bool damaging;

public:

	//CONSTRUCTORS AND DESTRUCTORS
	Tile(sf::Texture& texture_sheet, sf::IntRect texture_rect, bool damaging = false);

	//PUBLIC FUNCTIONS

	//ACCESSORS
	const sf::FloatRect getBounds() const;


	//UPDATES
	void update();

	//RENDERS
	void render(sf::RenderTarget& target);

};


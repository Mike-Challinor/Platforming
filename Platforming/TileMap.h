#pragma once

#include "Tile.h"

class TileMap
{
private:
	std::vector<std::vector<Tile>> tiles;

public:

	//CONSTRUCTORS AND DESTRUCTORS
	TileMap();
	~TileMap();

	//PUBLIC FUNCTIONS
	void addTile(unsigned x, unsigned y);
	void removeTile(unsigned x, unsigned y);

	//UPDATES
	void update();

	//RENDERS
	void render();

};


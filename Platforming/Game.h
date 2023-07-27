#pragma once

#include "Player.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::VideoMode videoMode;

	sf::Event ev;

	Player* player;

	//PRIVATE FUNCTIONS
	void initWindow();
	void initPlayer();


public:
	
	//CONSTRUCTORS AND DESTRUCTORS
	Game();
	virtual ~Game();

	//PUBLIC FUNCTIONS

	//ACCESSORS
	const sf::RenderWindow& getWindow() const;

	//UPDATES
	void updatePlayer();
	void update();

	//RENDERS

	void renderPlayer();
	void render();

};


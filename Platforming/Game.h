#pragma once

class Game
{
private:
	sf::RenderWindow window;
	sf::VideoMode videoMode;

	//PRIVATE FUNCTIONS
	void initWindow();


public:
	
	//CONSTRUCTORS AND DESTRUCTORS
	Game();
	virtual ~Game();

	//PUBLIC FUNCTIONS

	//ACCESSORS
	const sf::RenderWindow& getWindow() const;

	//UPDATES
	void update();

	//RENDERS
	void render();

};


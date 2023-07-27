#include "stdafx.h"
#include "Game.h"


//PRIVATE FUNCTIONS

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window.create(this->videoMode, "Platforming!", sf::Style::Close | sf::Style::Titlebar);
}

void Game::initPlayer()
{
	this->player = new Player();
}

//CONSTRUCTORS AND DESTRUCTORS

Game::Game()
{
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->player;
}

//ACCESSORS

const sf::RenderWindow& Game::getWindow() const
{
	return this->window;
}

//UPDATES

void Game::updatePlayer()
{
	this->player->update();
}

void Game::update()
{

	//Polling window events

	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
		{
			this->window.close();
		}

		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
		{
			this->window.close();
		}
	}

	this->updatePlayer();
}

//RENDERS

void Game::render()
{
	//Clear the window
	this->window.clear();

	//Draw Stuff


	//Display to window
	this->window.display();
}

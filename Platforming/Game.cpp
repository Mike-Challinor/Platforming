#include "stdafx.h"
#include "Game.h"


//PRIVATE FUNCTIONS

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window.create(this->videoMode, "Platforming!", sf::Style::Close | sf::Style::Titlebar);
}

//CONSTRUCTORS AND DESTRUCTORS

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{

}

//ACCESSORS

const sf::RenderWindow& Game::getWindow() const
{
	return this->window;
}

//UPDATES

void Game::update()
{

}

//RENDERS

void Game::render()
{
}

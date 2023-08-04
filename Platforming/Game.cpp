#include "stdafx.h"
#include "Game.h"


//PRIVATE FUNCTIONS

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window.create(this->videoMode, "Platforming!", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
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

void Game::updateCollision()
{
	//Check bottom boundary
	if (this->player->getPosition().y + this->player->getBounds().height > this->window.getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(this->player->getPosition().x, this->window.getSize().y - this->player->getBounds().height);
	}
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

		//If movement keys are released then reset the players animation timer.
		if (this->ev.type == sf::Event::KeyReleased && (this->ev.key.code == sf::Keyboard::A || this->ev.key.code == sf::Keyboard::D || this->ev.key.code == sf::Keyboard::S || this->ev.key.code == sf::Keyboard::W))
		{
			this->player->resetAnimationTimer();
		}
	}

	this->updatePlayer();
	this->updateCollision();
}

//RENDERS

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::render()
{
	//Clear the window
	this->window.clear();

	//Draw Stuff
	this->renderPlayer();

	//Display to window
	this->window.display();
}

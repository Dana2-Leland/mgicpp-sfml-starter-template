
#include "Game.h"
#include <iostream>
<<<<<<< Updated upstream

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
=======
#include <random>
#include "GameObject.h"

Game::Game(sf::RenderWindow& game_window)
>>>>>>> Stashed changes
{
  srand(time(NULL));
}

Game::~Game()
{

}

<<<<<<< Updated upstream
bool Game::init()
{

  return true;
=======
void Game::dragSprite(sf::Sprite* sprite)
{
	if (sprite != nullptr) {
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);
		//make click centered later
		sprite->setPosition(mouse_positionf.x, mouse_positionf.y);
		window.draw(*sprite);
	}
}

bool Game::init()
{
	background = new sf::Sprite;

	stamp = new sf::Sprite;

	newAnimal();
	//load background texture
	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png")) {
		std::cout << "background texture could not be loaded";
	}
	background->setTexture(background_texture);

	//load buttons
	
	rejectButton->setTexture(rejectButton_texture);
	rejectButton->setScale(.5, .5);
	rejectButton->setPosition(passport->getPosition().x * 1.41, passport->getPosition().y + 500);

	return true;
>>>>>>> Stashed changes
}


void Game::update(float dt)
{

}

void Game::render()
{

}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

<<<<<<< Updated upstream
=======
void Game::mouseButtonReleased(sf::Event event)
{
	dragged = nullptr;
}

void Game::renderButtons(){
	acceptButton = new sf::Sprite;
	rejectButton = new sf::Sprite;

	if (!acceptButton_texture.loadFromFile("../Data/Images/Critter Crossing Customs/accept button.png")) {
		std::cout << "accept button texture could not be loaded";
	}
	acceptButton->setTexture(acceptButton_texture);
	acceptButton->setScale(.5, .5);
	//acceptButton->setPosition(passport->getPosition().x, passport->getPosition().y + 500);

	if (!rejectButton_texture.loadFromFile("../Data/Images/Critter Crossing Customs/reject button.png")) {
		std::cout << "reject button texture could not be loaded";
	}
	rejectButton->setTexture(acceptButton_texture);
	rejectButton->setScale(.5, .5);
	//rejectButton->setPosition(passport->getPosition().x, passport->getPosition().y + 500);


}



>>>>>>> Stashed changes
void Game::keyPressed(sf::Event event)
{

}



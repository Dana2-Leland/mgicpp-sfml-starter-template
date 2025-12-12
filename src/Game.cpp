
#include "Game.h"
#include <iostream>
#include <random>
#include "GameObject.h"

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

/*
	Allows player to drag given sprite around scene
*/
void Game::dragSprite(sf::Sprite * sprite)
{
	if (sprite != nullptr) {
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);
		//make click centered later
		sprite->setPosition(mouse_positionf.x, mouse_positionf.y);
		window.draw(*sprite);
	}
}

/*
	gets the Passport struct from GameObject, then assigns its data to our passport/animal sprites (and adds textures)
*/
void Game::getAniPass() 
	{
	//GameObject fills animal & passport values
	GameObject thisAnimal;
	thisAnimal.init();

	//get animal & passport from GameObject class
	Passport& thisAnimalPassport = thisAnimal.getSprites();
	
	passport = std::make_unique<sf::Sprite>(std::move(thisAnimalPassport.passport)); 
	passport_texture = sf::Texture(thisAnimalPassport.passport_texture);
	passport->setTexture(passport_texture);
	passport->setPosition(500, 100); //set scalable position later

	animal = std::make_unique<sf::Sprite>(std::move(thisAnimalPassport.character));
	animal_texture = sf::Texture (thisAnimalPassport.character_texture);
	animal->setTexture(animal_texture);
	animal->setPosition(100, 100);

	}


bool Game::init()
{
	background = new sf::Sprite;

	//load background texture
	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png")) {
		std::cout << "background texture could not be loaded";
	}
	background->setTexture(background_texture);

	//retrieve animal and passport
	getAniPass();

	renderButtons();

	return true;
}


void Game::update(float dt)
{

}

void Game::render()
{
	window.draw(*background);
	window.draw(*passport);
	window.draw(*animal);
	window.draw(*acceptButton);
	window.draw(*rejectButton);


}

void Game::mouseClicked(sf::Event event)
{
	//get the click position
	sf::Vector2i click = sf::Mouse::getPosition(window);


}


void Game::mouseButtonPressed(sf::Event event)
{
	//get the click position
	sf::Vector2i click = sf::Mouse::getPosition(window);

	//write accept/reject collision checks
	if (event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2i click = sf::Mouse::getPosition(window);
		sf::Vector2f clickf = static_cast<sf::Vector2f>(click);

		if (passport->getGlobalBounds().contains(clickf)) {
			dragged = std::make_unique<sf::Sprite>(std::move(*passport));
		}
		else if (acceptButton->getGlobalBounds().contains(clickf)) {

		}
		else if (rejectButton->getGlobalBounds().contains(clickf)) {

		}
	}
}

void Game::mouseButtonReleased(sf::Event event)
{
	dragged = nullptr;
}

/*
	Renders accept/reject buttons in the scene
*/
void Game::renderButtons() {
	acceptButton = new sf::Sprite;
	rejectButton = new sf::Sprite;

	if (!acceptButton_texture.loadFromFile("../Data/Images/Critter Crossing Customs/accept button.png")) {
		std::cout << "accept button texture could not be loaded";
	}
	acceptButton->setTexture(acceptButton_texture);
	acceptButton->setScale(.5, .5);
	acceptButton->setPosition(passport->getPosition().x, passport->getPosition().y + 500);

	if (!rejectButton_texture.loadFromFile("../Data/Images/Critter Crossing Customs/reject button.png")) {
		std::cout << "reject button texture could not be loaded";
	}
	rejectButton->setTexture(acceptButton_texture);
	rejectButton->setScale(.5, .5);
	rejectButton->setPosition(passport->getPosition().x, passport->getPosition().y + 500);


}



void Game::keyPressed(sf::Event event)
{

}



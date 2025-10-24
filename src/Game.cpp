
#include "Game.h"
#include <iostream>
#include <random>

Game::Game(sf::RenderWindow& game_window)
	: window(game_window)
{
	srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	character = new sf::Sprite;
	passport = new sf::Sprite;
	bool isValid = false;
	
	std::random_device rd;  // a seed source for the random number engine
	std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
	//std::uniform_int_distribution<> distrib(0, 8);
	std::uniform_int_distribution<int> distribution_1_8(0,8);
	int randEntry = distribution_1_8(rd);


	std::uniform_int_distribution<int> distribution_0_1(0, 1);
	int torf = distribution_0_1(rd);
	//torf = 0; //debug line

	if (torf == 1) { 
		isValid = true; } //create 50/50 chance of passport being valid

	std::vector<std::string> animalNames = { "buffalo", "chicken", "elephant", "giraffe", "gorilla", "moose", "narwhal", "penguin", "walrus" }; //load all animal names into vector

	//load character texture
	if (!character_texture.loadFromFile("../Data/Images/Critter Crossing Customs/icons/" + animalNames[randEntry] + ".png")) {
		std::cout << "character texture could not be loaded";
	}
	character->setTexture(character_texture);
	character->setPosition(100, 100); //set scalable position later
	
	//load valid passport texture
	if (isValid && !passport_texture.loadFromFile("../Data/Images/Critter Crossing Customs/validPassports/" + animalNames[randEntry] + " passport.png")) {
		std::cout << "passport texture could not be loaded";
	}

	//generate invalid passport
	if (!isValid && !passport_texture.loadFromFile("../Data/Images/Critter Crossing Customs/invalidPassports/" + animalNames[randEntry] + "_invalid passport0.png")) {
		std::cout << "invalid passport texture could not be loaded";
	}
	passport->setTexture(passport_texture);
	passport->setPosition(500, 50); //set scalable position later
	passport->setScale(.7, .7);



	//load background texture
	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png")) {
		std::cout << "background texture could not be loaded";
	}
	background.setTexture(background_texture);

	return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
	window.draw(background);
	window.draw(*character);
	window.draw(*passport);
}

void Game::mouseClicked(sf::Event event)
{
	//get the click position
	sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{
	
}



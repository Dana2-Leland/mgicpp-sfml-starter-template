
#include "Game.h"
#include <iostream>

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
	using charVector = std::vector<std::unique_ptr<character>> character_ptrs;
	using psprtVector = std::vector<std::unique_ptr<passport>> passport_ptrs;
	//create array of strings for each animal. Go through each entry in there, and load in the image for it
	string animalNames[9] = { "buffalo", "chicken", "elephant", "giraffe", "gorilla", "moose", "narwhal", "penguin", "walrus" }
	for (int i = 0; i < animalNames.length(); i++) {
		string fileName = "../Data/Images/Critter Crossing Customs/" + ""
			//"\\nstu-nas01.uwe.ac.uk\users1$\d2-leland\Personal\GitHub\mgicpp-sfml-starter-template\Data\Images\Critter Crossing Customs\buffalo.png"
			if (!character_texture.loadFromFile("../"))
	}
	return true;
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

void Game::keyPressed(sf::Event event)
{

}



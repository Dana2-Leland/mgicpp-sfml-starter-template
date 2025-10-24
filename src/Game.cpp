
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
enum spriteType {charType, passType};


/*
Sets the texture. 
*/
static void getTexture(sf::Texture& targetTexture, std::string animalName, spriteType thisSprite, bool valid = true) {
	switch (thisSprite) {
	case(charType): //if character sprite
		if (!targetTexture.loadFromFile("../Data/Images/Critter Crossing Customs/icons/" + animalName + ".png")) {
			std::cout << animalName + "texture could not be loaded";
		}
		break;
	case(passType)://if passport sprite
		switch (valid) { //check validity
		case(true)://if valid
			if (!targetTexture.loadFromFile("../Data/Images/Critter Crossing Customs/validPassports/" + animalName + " passport.png")) {
				std::cout << animalName + "texture could not be loaded";
			}
			break;
		case(false)://if invalid
			if (!targetTexture.loadFromFile("../Data/Images/Critter Crossing Customs/invalidPassports/" + animalName + "_invalid passport0.png")) {
				std::cout << animalName + "texture could not be loaded";
			}
			break;
	}
		break;
	}
}


bool Game::init()
{
	//std::vector <std::unique_ptr< sf::Sprite* >> spriteType; //load sprites into vector
	character = new sf::Sprite;
	passport = new sf::Sprite;
	background = new sf::Sprite;
	acceptButton = new sf::Sprite;
	rejectButton = new sf::Sprite;

	bool isValid = false;
	std::vector<std::string> animalNames = { "buffalo", "chicken", "elephant", "giraffe", "gorilla", "moose", "narwhal", "penguin", "walrus" }; //load all animal names into vector


	//load background texture
	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png")) {
		std::cout << "background texture could not be loaded";
	}
	background->setTexture(background_texture);

	/*
		generate random number [0,8] to determine which animal appears
	*/
	std::random_device rd;  // a seed source for the random number engine
	std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<int> distributionAnimalName(0, animalNames.size());
	int randEntry = distributionAnimalName(rd);

	/*
		generate random number [0,1] to determine whether passport is or
		isn't valid (50/50 chance right now). Set isValid to true if we land
		on the right number. 
	*/
	int trueChance = 1;
	std::uniform_int_distribution<int> distributionChance(0, trueChance);
	int torf = distributionChance(rd);

	if (torf == trueChance) { isValid = true; } 


	//load character 
	getTexture(character_texture, animalNames[randEntry], charType);
	character->setTexture(character_texture);
	character->setPosition(100, 100); //set scalable position later
	
	//load passport 
	getTexture(passport_texture, animalNames[randEntry], passType, isValid);
	passport->setTexture(passport_texture);
	passport->setPosition(500, 50); //set scalable position later
	passport->setScale(.7, .7);

	//load buttons
	//"D:\Dana\mgicpp-sfml-starter-template\Data\Images\Critter Crossing Customs\accept button.png"
	if (!acceptButton_texture.loadFromFile("../Data/Images/Critter Crossing Customs/accept button.png")) {
		std::cout << "accept button texture could not be loaded";
	}
	acceptButton->setTexture(acceptButton_texture);
	acceptButton->setScale(.5, .5);
	acceptButton->setPosition(passport->getPosition().x, passport->getPosition().y + 500);

	if (!rejectButton_texture.loadFromFile("../Data/Images/Critter Crossing Customs/reject button.png")) {
		std::cout << "reject button texture could not be loaded";
	}
	rejectButton->setTexture(rejectButton_texture);
	rejectButton->setScale(.5, .5);
	rejectButton->setPosition(passport->getPosition().x*1.41, passport->getPosition().y + 500);

	return true;
}


void Game::update(float dt)
{

}

void Game::render()
{
	window.draw(*background);
	window.draw(*character);
	window.draw(*passport);
	window.draw(*acceptButton);
	window.draw(*rejectButton);

}

void Game::mouseClicked(sf::Event event)
{
	//get the click position
	sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{
	
}



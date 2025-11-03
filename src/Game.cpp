
#include "Game.h"
#include <iostream>
#include <random>

bool passport_accepted = false;
bool passport_denied = false;
enum spriteType { charType, passType };


Game::Game(sf::RenderWindow& game_window)
	: window(game_window)
{
	srand(time(NULL));
}

Game::~Game()
{

}


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




void Game::newAnimal() {
	character = new sf::Sprite;
	passport = new sf::Sprite;

	passport_accepted = false;
	passport_denied = false;

	std::vector<std::string> animalNames = { "buffalo", "chicken", "elephant", "giraffe", "gorilla", "moose", "narwhal", "penguin", "walrus" }; //load all animal names into vector
	bool isValid = false;
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
}

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
	acceptButton = new sf::Sprite;
	rejectButton = new sf::Sprite;

	newAnimal();
	//load background texture
	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png")) {
		std::cout << "background texture could not be loaded";
	}
	background->setTexture(background_texture);

	//load buttons
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
	rejectButton->setPosition(passport->getPosition().x * 1.41, passport->getPosition().y + 500);

	return true;
}

void Game::update(float dt)
{
	dragSprite(dragged);


}

void Game::renderStamp(bool accepted) {
	gameStamp = new sf::Sprite; 
	switch (accepted) {
	case(true):
		if (!gameStamp_texture.loadFromFile("../Data/Images/Critter Crossing Customs/accept.png")) {
			std::cout << "accept stamp texture could not be loaded";
		}
		break;
	case(false):
		if (!gameStamp_texture.loadFromFile("../Data/Images/Critter Crossing Customs/reject.png")) {
			std::cout << "reject stamp texture could not be loaded";
		}
		break;
	}
	gameStamp->setPosition(passport->getPosition().x + passport->getPosition().x / 2, passport->getPosition().y + passport->getPosition().y / 2);
	window.draw(*gameStamp);
}

void Game::render()
{
	window.draw(*background);
	window.draw(*character);
	window.draw(*passport);
	window.draw(*acceptButton);
	window.draw(*rejectButton);
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
			dragged = passport;
		}
		else if (acceptButton->getGlobalBounds().contains(clickf)) {
			renderStamp(true);
		}
		else if (rejectButton->getGlobalBounds().contains(clickf)) {
			renderStamp(false);
		}
	}


}

void Game::mouseButtonReleased(sf::Event event)
{
	dragged = nullptr;
}



void Game::keyPressed(sf::Event event)
{
	
}



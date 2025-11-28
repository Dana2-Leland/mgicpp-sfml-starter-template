#include "GameObject.h"
#include <iostream>
#include <random>

bool passport_accepted = false;
bool passport_denied = false;

/*
Sets the texture.
*/
void GameObject::getTexture(sf::Texture& targetTexture, std::string animalName, spriteType thisSprite, bool valid = true)
{
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
				std::cout << animalName + "valid passport texture could not be loaded";
			}
			break;
		case(false)://if invalid
			if (!targetTexture.loadFromFile("../Data/Images/Critter Crossing Customs/invalidPassports/" + animalName + "_invalid passport0.png")) {
				std::cout << animalName + "invalid passport texture could not be loaded";
			}
			break;
		}
	}
}

void GameObject::newAnimal() {
	std::unique_ptr<sf::Sprite> character(new sf::Sprite()); //change to smart vectors
	std::unique_ptr<sf::Sprite> passport(new sf::Sprite());


	passport_accepted = false;
	passport_denied = false;

	//**ISSUE: MAKE SMART VECTOR, NOT JUST VECTOR
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

std::vector<std::unique_ptr<sf::Sprite>> GameObject::getSprites()
{
	std::vector<std::unique_ptr<sf::Sprite>> aniPass;
	aniPass.push_back(std::move(character));
	aniPass.push_back(std::move(passport));

	return aniPass;
}




/*
	NEED:
		Accept & Reject buttons
			getters for those too
*/



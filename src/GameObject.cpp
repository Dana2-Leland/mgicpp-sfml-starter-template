#include "GameObject.h"
#include <iostream>
#include <random>

bool passport_accepted = false;
bool passport_denied = false;


GameObject::GameObject()
{
}


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

/*
fills character and passport sprites, calls getTexture() to assign the textures
*/
bool GameObject::init() 
{
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

	//load passport 
	getTexture(passport_texture, animalNames[randEntry], passType, isValid);

	//load data into passport struct
	setSprites(character, passport, character_texture, passport_texture);

	return true;
}

/*
* Fills in data for the Passport struct
*/
void GameObject::setSprites(sf::Sprite Tcharacter, sf::Sprite Tpassport, sf::Texture Tcharacter_texture, sf::Texture Tpassport_texture)
{
	AnimalPassport = std::make_unique<Passport>();
	AnimalPassport->character = std::make_unique<sf::Sprite>(Tcharacter);
	AnimalPassport->passport = std::make_unique<sf::Sprite>(Tpassport);
	AnimalPassport->character_texture = std::make_unique<sf::Texture>(Tcharacter_texture);
	AnimalPassport->passport_texture = std::make_unique<sf::Texture>(Tpassport_texture);
}

/*
	returns filled Passport struct
*/
Passport& GameObject::getSprites()
{	
	return *AnimalPassport;
}




/*
	NEED:
		Accept & Reject buttons
			getters for those too
*/



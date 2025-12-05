#include "stamp.h"
#include <iostream>

void stamp::placeStamp(sf::Sprite passport)
{
	switch (accepted) {
	case(true):
		if (!stamp_texture.loadFromFile("../Data/Images/Critter Crossing Customs/accept.png")) {
			std::cout << "accept stamp texture could not be loaded";
		}
		break;
	case(false):
		if (!stamp_texture.loadFromFile("../Data/Images/Critter Crossing Customs/reject.png")) {
			std::cout << "reject stamp texture could not be loaded";
		}
		break;
	}
	stamp.setPosition(passport.getPosition().x + passport.getPosition().x / 2, passport.getPosition().y + passport.getPosition().y / 2);
}

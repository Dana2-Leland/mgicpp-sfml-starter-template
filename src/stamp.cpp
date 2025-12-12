#include "stamp.h"
#include <iostream>

sf::Texture stamp::placeStamp(sf::Sprite passport, bool accepted)
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
	return stamp_texture;
}
	


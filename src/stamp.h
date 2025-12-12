#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class stamp
{
public:
	sf::Texture placeStamp(sf::Sprite passport, bool accepted);
	bool wasAccepted;

private:
	sf::Texture stamp_texture;
};
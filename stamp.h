#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class stamp
{
public:
	bool accepted;
	void placeStamp(sf::Sprite passport);

private:
	sf::Sprite stamp;
	sf::Texture stamp_texture;
};

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class GameObject {

public:
	enum spriteType { charType, passType, buttonType };

	bool init();
	void getTexture(sf::Texture& targetTexture, std::string animalName, spriteType thisSprite, bool valid);
	void newAnimal();
	std::vector<std::unique_ptr<sf::Sprite>> getSprites();

private:
	sf::Sprite* dragged = nullptr;

	sf::RenderWindow& window;
	std::unique_ptr<sf::Sprite> character;
	std::unique_ptr<sf::Sprite> passport;
	sf::Texture character_texture;
	sf::Texture passport_texture;


};
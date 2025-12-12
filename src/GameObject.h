#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct Passport
{
	sf::Sprite character;
	sf::Sprite passport;
	sf::Texture character_texture;
	sf::Texture passport_texture;
	bool isPassValid;

};
class GameObject {

public:
	enum spriteType { charType, passType, buttonType };
	GameObject();
	bool init();
	void getTexture(sf::Texture& targetTexture, std::string animalName, spriteType thisSprite, bool valid);
	Passport& getSprites();
	void setSprites(sf::Sprite Tcharacter, sf::Sprite Tpassport, sf::Texture Tcharacter_texture, sf::Texture Tpassport_texture, bool wasValid);

private:
	std::unique_ptr<Passport> AnimalPassport;

	sf::Sprite character;
	sf::Sprite passport;
	sf::Texture character_texture;
	sf::Texture passport_texture;


};

#include "Game.h"
#include <iostream>
#include <random>
#include "GameObject.h"
#include "stamp.h"

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

/*
	Allows player to drag given sprite around scene
*/
void Game::dragSprite(std::shared_ptr<sf::Sprite> sprite)
{
	if (sprite != nullptr) {
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);
		//make click centered later
		sprite->setPosition(mouse_positionf.x, mouse_positionf.y);
		window.draw(*sprite);
		if (stampSprite.getTexture() != NULL) {
			stampSprite.setPosition(passport->getPosition().x + 50, passport->getPosition().y + 50);
		}
	}
}

/*
	gets the Passport struct from GameObject, then assigns its data to our passport/animal sprites (and adds textures)
*/
void Game::getAniPass() 
	{
	//GameObject fills animal & passport values
	GameObject thisAnimal;
	thisAnimal.init();

	//get animal & passport from GameObject class
	Passport& thisAnimalPassport = thisAnimal.getSprites();
	
	passport = std::make_unique<sf::Sprite>(std::move(thisAnimalPassport.passport)); 
	passport_texture = sf::Texture(thisAnimalPassport.passport_texture);
	passport->setTexture(passport_texture);
	passport->setScale(.8, .8);
	passport->setPosition(500, 0); //set scalable position later

	animal = std::make_unique<sf::Sprite>(std::move(thisAnimalPassport.character));
	animal_texture = sf::Texture (thisAnimalPassport.character_texture);
	animal->setTexture(animal_texture);
	animal->setPosition(100, 100);

	passValid = thisAnimalPassport.isPassValid;
	}


bool Game::init()
{
	background = new sf::Sprite;

	//load background texture
	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png")) {
		std::cout << "background texture could not be loaded";
	}
	background->setTexture(background_texture);

	//retrieve animal and passport
	getAniPass();
	renderButtons();
	renderScore();

	return true;
}


void Game::update(float dt)
{
	dragSprite(dragged);
}

void Game::render()
{
	window.draw(*background);
	window.draw(*passport);
	window.draw(*acceptButton);
	window.draw(*rejectButton);
	window.draw(scoreText);
	if (stamped) {
		window.draw(stampSprite);
	}
	window.draw(*animal);
	
}


void Game::mouseClicked(sf::Event event)
{
	mouseButtonPressed(event);
}

void Game::mouseReleased(sf::Event event)
{
	if (stampSprite.getTexture() != NULL && (animal->getGlobalBounds().intersects(passport->getGlobalBounds()))) {
		if (passValid == passAccepted) {
			score += 5;
		}
		else {
			score -= 5;
		}
		renderScore();
		getAniPass();
	}
	mouseButtonReleased(event);
}

void Game::renderStamp(bool accepted)
{
	stamp thisStamp;
	stamp_texture = thisStamp.placeStamp(*passport, accepted);
	stampSprite.setTexture(stamp_texture);
	stampSprite.setPosition(passport->getPosition().x + 50, passport->getPosition().y +50);
	passAccepted = thisStamp.wasAccepted;
	stamped = true;
}

void Game:: renderScore() {
	scoreText.setString(std::to_string(score));
	if (!scoreFont.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf")) {
		std::cout << "font could not be loaded";
	}
	scoreText.setFont(scoreFont);
	scoreText.setCharacterSize(40);
	scoreText.setFillColor(sf::Color(255, 255, 128));
	scoreText.setPosition(30, 10);
	stamped = false;
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
			dragSprite(dragged);


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

/*
	Renders accept/reject buttons in the scene
*/
void Game::renderButtons() {
	acceptButton = new sf::Sprite;
	rejectButton = new sf::Sprite;

	if (!acceptButton_texture.loadFromFile("../Data/Images/Critter Crossing Customs/accept button.png")) {
		std::cout << "accept button texture could not be loaded";
	}
	acceptButton->setTexture(acceptButton_texture);
	acceptButton->setScale(.5, .5);
	acceptButton->setPosition(passport->getPosition().x + 20, passport->getPosition().y + 600);

	if (!rejectButton_texture.loadFromFile("../Data/Images/Critter Crossing Customs/reject button.png")) {
		std::cout << "reject button texture could not be loaded";
	}
	rejectButton->setTexture(rejectButton_texture);
	rejectButton->setScale(.5, .5);
	rejectButton->setPosition(passport->getPosition().x + 300, passport->getPosition().y + 600);


}



void Game::keyPressed(sf::Event event)
{

}



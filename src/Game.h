
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  void newAnimal();
  void dragSprite(sf::Sprite* sprite);
  bool init();
  void update(float dt);
  void render();
  void keyPressed(sf::Event event);
  void mouseButtonPressed(sf::Event event);
  void mouseButtonReleased(sf::Event event);
  void placeStamp(sf::Sprite stamp, sf::Sprite passport, bool valid);

 private:
	 sf::Sprite* dragged = nullptr;

	 sf::RenderWindow& window;
	 sf::Sprite* character;
	 sf::Sprite* passport;
	 sf::Texture character_texture;
	 sf::Texture passport_texture;

	 sf::Sprite* acceptButton;
	 sf::Texture acceptButton_texture;
	 sf::Sprite* rejectButton;
	 sf::Texture rejectButton_texture;

	 sf::Sprite* background;
	 sf::Texture background_texture;

};

#endif // PLATFORMER_GAME_H

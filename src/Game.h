
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
<<<<<<< Updated upstream

 private:
  sf::RenderWindow& window;
  sf::Sprite ball;
  sf::Texture ball_texture;

=======
  void mouseButtonPressed(sf::Event event);
  void mouseButtonReleased(sf::Event event);
  void placeStamp(sf::Sprite stamp, sf::Sprite passport, bool valid);
  void renderButtons();

 private:
	 sf::Sprite* background;
	 sf::Texture background_texture;

	 sf::Sprite* acceptButton;
	 sf::Texture acceptButton_texture;
	 sf::Sprite* rejectButton;
	 sf::Texture rejectButton_texture;
>>>>>>> Stashed changes
};

#endif // PLATFORMER_GAME_H

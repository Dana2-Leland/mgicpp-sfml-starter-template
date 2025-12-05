
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& game_window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void dragSprite(sf::Sprite* sprite);
  void getAniPass();

 private:
  sf::RenderWindow& window;
  sf::Sprite ball;
  sf::Texture ball_texture;
  void mouseButtonPressed(sf::Event event);
  void mouseButtonReleased(sf::Event event);
  //void placeStamp(sf::Sprite stamp, sf::Sprite passport, bool valid);
  void renderButtons();


  sf::Sprite* background;
  sf::Texture background_texture;

  std::unique_ptr<sf::Sprite> animal;
  sf::Texture animal_texture;
  std::unique_ptr<sf::Sprite> passport;
  sf::Texture passport_texture;


  sf::Sprite* acceptButton;
  sf::Texture acceptButton_texture;
  sf::Sprite* rejectButton;
  sf::Texture rejectButton_texture;

};

#endif // PLATFORMER_GAME_H

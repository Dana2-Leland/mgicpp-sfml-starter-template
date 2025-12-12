
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
  void mouseReleased(sf::Event event);
  void keyPressed(sf::Event event);
  void dragSprite(std::shared_ptr<sf::Sprite> sprite);
  void getAniPass();
  void renderStamp(bool accepted);

 private:
  std::shared_ptr<sf::Sprite> dragged;
  //sf::Sprite* dragged = nullptr;
  sf::RenderWindow& window;
  sf::Sprite ball;
  sf::Texture ball_texture;
  void renderScore();
  void mouseButtonPressed(sf::Event event);
  void mouseButtonReleased(sf::Event event);
  //void placeStamp(sf::Sprite stamp, sf::Sprite passport, bool valid);
  void renderButtons();


  sf::Sprite* background;
  sf::Texture background_texture;

  bool passValid;
  bool passAccepted;
  bool stamped;

  int score = 0;
  sf::Text scoreText;
  sf::Font scoreFont;

  std::unique_ptr<sf::Sprite> animal;
  sf::Texture animal_texture;
  std::shared_ptr<sf::Sprite> passport;
  sf::Texture passport_texture;


  sf::Sprite* acceptButton;
  sf::Texture acceptButton_texture;
  sf::Sprite* rejectButton;
  sf::Texture rejectButton_texture;

  sf::Sprite stampSprite;
  sf::Texture stamp_texture;

};

#endif // PLATFORMER_GAME_H


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

 private:
	 

  sf::RenderWindow& window;

  //background
  sf::Sprite background;
  sf::Texture background_texture;

  //bird
  sf::Sprite bird; 
  sf::Texture bird_texture;

  //Title Text
  sf:: Text title_text;
  sf::Font font;

  //Menu Text Variables
  sf::Text title_play_text;
  sf::Text title_quit_text;
  sf::Text title_prompt_text;


  //boolean variables
  bool in_menu = false;
  bool play_selected = false;
  bool reverse = false;

  //double variables
  double speed = 200.0;
 

};

#endif // PLATFORMER_GAME_H

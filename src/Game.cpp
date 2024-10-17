
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	// init sprite
	if (!background_texture.loadFromFile("../Data/Whackamole Worksheet/background.png") 
		|| !bird_texture.loadFromFile("../Data/Whackamole Worksheet/bird.png"))
												//  "../" to go back to main file (not src)
	{
		std::cout << "texture did not load \n"; //change eventually to have a variable that tells you *what* failed to load
	}
	// init text
	if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "font did not load \n";
	}

	background.setTexture(background_texture);
	//bird texture & positioning
	bird.setTexture(bird_texture);
	bird.setPosition(80, 485); //places in bottom left of screen. Works with resizing, but warps the image
	bird.setScale(.5, .5);
	//title menu text
	title_text.setString("Whack-a-mole");
	title_text.setFont(font);
	title_text.setCharacterSize(200);
	title_text.setFillColor(sf::Color(255, 255, 255, 128));
	title_text.setPosition(
		window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
		window.getSize().y / 2 - title_text.getGlobalBounds().height / 2);
		//title options text

	//title play text
	title_play_text.setString("Play");
	title_play_text.setFont(font);
	title_play_text.setCharacterSize(20);
	title_play_text.setFillColor(sf::Color(255, 255, 0));
	title_play_text.setPosition(
		window.getSize().x / 3  - title_play_text.getGlobalBounds().width / 2,
		window.getSize().y / 6 - title_play_text.getGlobalBounds().height / 2);
	//title quit text
	title_quit_text.setString("Quit");
	title_quit_text.setFont(font);
	title_quit_text.setCharacterSize(20);
	title_quit_text.setFillColor(sf::Color(255, 255, 0));
	title_quit_text.setPosition(
		window.getSize().x / 1.5 - title_quit_text.getGlobalBounds().width / 2,
		window.getSize().y / 6 - title_quit_text.getGlobalBounds().height / 2);
	//title prompt text
	title_prompt_text.setString("Welcome to whack-a-mole. Please select an option:");
	title_prompt_text.setFont(font);
	title_prompt_text.setCharacterSize(20);
	title_prompt_text.setFillColor(sf::Color(255, 255, 0));
	title_prompt_text.setPosition(
		window.getSize().x / 2 - title_prompt_text.getGlobalBounds().width / 2,
		window.getSize().y / 12 - title_prompt_text.getGlobalBounds().height / 2);

	//initializing in_menu to true
	in_menu = true;
	

  return true;
}

void Game::update(float dt)
{
	if (!in_menu) { //so that bird doesn't move while in option menu
		if ((bird.getPosition().x > (window.getSize().x - bird.getGlobalBounds().width)) ||
			(bird.getPosition().x < 0))
		{
			reverse = !reverse;
		}
		if (!reverse) {
			bird.move(1.0f * speed * dt, 0);
			bird.setTextureRect(sf::IntRect(
				0, 0, bird.getLocalBounds().width, bird.getLocalBounds().height));
		}
		else {
			bird.move(-1.0f * speed * dt, 0);
			bird.setTextureRect(sf::IntRect( bird.getLocalBounds().width, 0,
				-bird.getLocalBounds().width, bird.getLocalBounds().height));
		}
	}
}

void Game::render()
{
	if (in_menu) {
		window.draw(title_play_text);
		window.draw(title_quit_text);
		window.draw(title_prompt_text);
	}
	else {
		window.draw(background);
		window.draw(bird);
		window.draw(title_text);
	}
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  //check if in bounds of bird Sprite
  if (collisionCheck(click, bird))
  {
  }

}

void Game::keyPressed(sf::Event event)
{
	if (
		(event.key.code == sf::Keyboard::
			Left) ||
		(event.key.code == sf::Keyboard::
			Right))
	{
		play_selected = !play_selected;
		if (play_selected)
		{
			title_play_text.setString("> Play <");
			title_quit_text.setString("Quit");
		}
		else
		{
			title_play_text.setString("Play");
			title_quit_text.setString("> Quit <");
		}
	}
	else if (event.key.code == sf::Keyboard::
		Enter)
	{
		if (play_selected)
		{
			in_menu = false;
		}
		else
		{
			window.close();
		}
	}
}



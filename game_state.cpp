/*****************************************************************************/
/*                                                                           */
/*         █████  ██████  ███████ ██       █████  ██ ██████  ███████         */
/*        ██   ██ ██   ██ ██      ██      ██   ██ ██ ██   ██ ██              */
/*        ███████ ██   ██ █████   ██      ███████ ██ ██   ██ █████           */
/*        ██   ██ ██   ██ ██      ██      ██   ██ ██ ██   ██ ██              */
/*        ██   ██ ██████  ███████ ███████ ██   ██ ██ ██████  ███████         */
/*                                                                           */
/*        ██    ██ ███    ██ ██    |                            |            */
/*        ██    ██ ████   ██ ██    |   OOP Semester 1 2023      |            */
/*        ██    ██ ██ ██  ██ ██    |   Camille, Rose, Alex      |            */
/*        ██    ██ ██  ██ ██ ██    |   Pokemon Showdown remake  |            */
/*         ██████  ██   ████ ██    |                            |            */
/*                                                                           */
/*        This class represents the game state and its logic                 */
/*        It manages the players, their turns, and the game board            */
/*                                                                           */
/*****************************************************************************/

#include "game_state.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "bot.hpp"
#include "player.hpp"
#include "renderable.hpp"
#include "sprites.hpp"

// Constructor
Gamestate::Gamestate() : current_turn(0) {
  players[0] = new Player();
  players[1] = new Bot();
}

// Draw the game state on the window
void Gamestate::draw(sf::RenderWindow* window) {
  // Create a renderable object for the game state
  Renderable::Renderable gamestate;

  // Add the "start_game" sprite
  sf::Sprite* start_game = gamestate.add_sprite("start_game", "start_game.png");
  start_game->setPosition(80, 80);
  start_game->setFillColor(sf::Color::White);

  // Create the text to display within the sprite
  sf::Text start_game_text;
  // Load the font from file
  sf::Font font;
  font.loadFromFile("font.ttf");
  start_game_text.setFont(font);
  start_game_text.setCharacterSize(20);
  start_game_text.setFillColor(sf::Color::Black);
  start_game_text.setString(
      "Welcome to the world of Pokemon! Get ready to embark on an epic "
      "showdown, where trainers and their loyal Pokemon battle for glory and "
      "become champions. Are you ready to catch 'em all and prove your skills? "
      "Let the Pokemon Showdown begin!");
  start_game_text.setPosition(100, 100);

  // Draw the "start_game" sprite and the text
  window->draw(*start_game);
  window->draw(start_game_text);
}

void Gamestate::swap_move() {
  if (current_turn == 0) {
    if (players[0]->make_choice() == "Make move") {
      players[0]->make_move();
    } else if (players[0]->make_choice() == "Swap Pokemon") {
      players[0]->swap_pokemon();
    }
    current_turn++;
  } else {
    players[1]->make_choice();
    current_turn--;
  }
}

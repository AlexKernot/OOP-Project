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
/*        This is the base class for all objects that need rendering         */
/*      It is an abstract class that holds the sprites for each object       */
/*                                                                           */
/*****************************************************************************/

#include "game_state.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "bot.hpp"
#include "player.hpp"
#include "renderable.hpp"

Gamestate::Gamestate() : current_turn(0) {
  draw();
  game_state = Renderable::add_sprite(sf::RectangleShape());
  game_state.setSize(sf::Vector2f(200, 100));
  // game_state.setPosition(80, 80);
  game_state.setFillColor(sf::Color::White);

  sf::Text start_game;
  start_game.setFont(font);
  start_game.setCharacterSize(20);
  start_game.setFillColor(sf::Color::Black);
  start_game.setString(
      "Welcome to the world of Pokemon! Get ready to embark on an epic "
      "showdown, where trainers and their loyal Pokemon battle for glory and "
      "become champions. Are you ready to catch 'em all and prove your skills? "
      "Let the Pokemon Showdown begin!");
  // start_game.setPosition(100, 100);

  players[0] = new Player();
  players[1] = new Bot();
};

void Gamestate::swap_move() {
  if (current_turn = 0) {
    if (players[0].make_choice() == "Make move") {
      players[0].make_move();
    } else if (players[0].make_choice() == "Swap Pokemon") {
      players[0].swap_pokemon();
    }
    current_turn++;
  } else {
    players[1].make_choice();
    current_turn--;
  }
};

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
#include "button.hpp"
#include "player.hpp"
#include "pokemon.hpp"

// Constructor
Gamestate::Gamestate() : current_turn(0) {
  players[0] = new Player();
  players[1] = new Bot();
}

void Gamestate::swap_move() {
  // Player's turn
  if (current_turn == 0) {
    // swap pokemon
    for (int i = 0; i < pokemon_buttons.size(); ++i) {
      if (pokemon_buttons[i].ClickedOn()) {
        players[0]->swap_pokemon();
      }
    }
    // make move
    for (int i = 0; i < move_buttons.size(); ++i) {
      if (move_buttons[i].ClickedOn()) {
        players[0]->make_move(i);
      }
    }
    current_turn++;
  }

  // Bot's turn
  else {
    players[1]->make_choice();
    current_turn--;
  }
}

void Gamestate::buttons() {
  // Create swap pokemon buttons
  std::vector<sf::Vector2f> pokemon_coords = {};
  for (int i = 0; i < players[0]->pokemons.size(); ++i) {
    pokemon_buttons[i] = new Button;
    pokemon_buttons[i].SetPosition(pokemon_coords[i]);
    pokemon_buttons[i].SetText(pokemons[i]->get_name());
  }

  // Create move buttons
  std::vector<sf::Vector2f> moves_coords = {};
  for (int i = 0; i < players[0]->moves.size(); ++i) {
    move_buttons[i] = new Button;
    move_buttons[i].SetPosition(move_coords[i]);
    move_buttons[i].SetText(moves[i]->get_name());
  }
}

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
#include <vector>

#include "bot.hpp"
#include "button.hpp"
#include "player.hpp"
#include "pokemon.hpp"

// Constructor
Gamestate::Gamestate() : current_turn(0) {
  player1 = Player();
  player2 = Bot();
}

// Create buttons
void Gamestate::buttons() {
  // Create swap pokemon buttons
  std::vector<sf::Vector2f> pokemon_coords = {};
  for (int i = 0; i < 6; ++i) {
    pokemon_buttons[i] = new Button;
    pokemon_buttons[i]->SetPosition(static_cast<sf::Vector2i>(pokemon_coords[i]));
    pokemon_buttons[i]->SetText(player1.getPokemons()[i]->get_name());
  }

  // Create move buttons
  std::vector<sf::Vector2f> moves_coords;
  for (int i = 0; i < player1.get_current_pokemon()->get_moves().size();
       ++i) {
    move_buttons[i] = new Button;
    move_buttons[i]->SetText(player1.get_current_pokemon()->get_moves()[i]->get_name());
  }
}


void Gamestate::swap_move() {
  // Player's turn
  if (current_turn == 0) {
    // swap pokemon
    for (int i = 0; i < pokemon_buttons.size(); ++i) {
      if (pokemon_buttons[i]->ClickedOn(sf::Mouse::getPosition())) {
        player1.swap_pokemon(i);
      }
    }
    // make move
    for (int i = 0; i < move_buttons.size(); ++i) {
      if (move_buttons[i]->ClickedOn(sf::Mouse::getPosition())) {
        player1.make_move(i);
      }
    }
    current_turn++;
  }

  // Bot's turn
  else {
    player2.bot_make_choice();
    current_turn--;
  }
}


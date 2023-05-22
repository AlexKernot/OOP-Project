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
/*            This is the class that handles Players. Players will           */
/*                    direct their 6 Pokemon and 4 moves                     */
/*                                                                           */
/*****************************************************************************/

#include "player.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "button.hpp"
#include "move.hpp"
#include "pokemon.hpp"

Player::Player() {
  for (int i = 0; i < 6; ++i) {
    pokemons.push_back(new Pokemon());
  }
}

Player::Player(std::vector<Pokemon*> pokemons) {
  this->pokemons = pokemons;
  this->moves = current_pokemon->get_moves();
}

// This allows the Player to make a move
void Player::make_move(int i) { this->current_move = moves[i]; }

// This allows the Player to swap between Pokemons
void Player::swap_pokemon(int i) { this->current_pokemon = pokemons[i]; }

void Draw(sf::RenderWindow* window){};

Pokemon* Player::get_current_pokemon() { return this->current_pokemon; }

std::vector<Pokemon*> Player::getPokemons() { return this->pokemons; };

void Player::Draw(sf::RenderWindow* window) {
  return;
}

Player::~Player() {
  // Clean up resources
  for (int i = 0; i < 6; i++) {
    delete pokemons[i];
  }
}

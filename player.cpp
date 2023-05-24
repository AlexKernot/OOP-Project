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
    pokemons.push_back(Pokemon());
  }
  current_pokemon = &(pokemons[0]);
  int i = 0;
}

Player::Player(const Player& player) {
  int pokemonSize = static_cast<int>(player.pokemons.size());
  for (int i = 0; i < pokemonSize; ++i) {
    pokemons.push_back(player.pokemons[i]);
  }
  int moveSize = static_cast<int>(player.moves.size());
  for (int i = 0; i < moveSize; ++i) {
    moves.push_back(player.moves[i]);
  }
  current_pokemon = player.current_pokemon;
}

Player Player::operator=(const Player& player) {
  int pokemonSize = static_cast<int>(player.pokemons.size());
  for (int i = 0; i < pokemonSize; ++i) {
    pokemons.push_back(player.pokemons[i]);
  }
  int moveSize = static_cast<int>(player.moves.size());
  for (int i = 0; i < moveSize; ++i) {
    moves.push_back(player.moves[i]);
  }
  current_pokemon = player.current_pokemon;
  return *this;
}

Player::Player(std::vector<Pokemon> pokemons) {
  this->pokemons = pokemons;
  current_pokemon = &pokemons.at(0);
  this->moves = current_pokemon->get_moves();
}

// This allows the Player to make a move
void Player::make_move(int i) { current_move = moves[i]; }

// This allows the Player to swap between Pokemons
void Player::swap_pokemon(int i) { current_pokemon = &pokemons[i]; }

void Draw(sf::RenderWindow* window){};

Pokemon* Player::get_current_pokemon() { return current_pokemon; }

std::vector<Pokemon> *Player::getPokemons() { return &pokemons; };

void Player::Draw(sf::RenderWindow* window) {
  return;
}
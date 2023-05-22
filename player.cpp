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

Player::Player(std::string name, std::vector<Pokemon*> pokemons) {
  this->name = name;
  this->pokemons = pokemons;
  this->moves = = current_pokemon->get_moves();
}

// This allows the Player to make a move
Move Player::make_move(int i) { this->current_move = moves[i]; }

// This allows the Player to swap between Pokemons
void Player::swap_pokemon(int i) { this->current_pokemon = pokemons[i]; }

void Draw(sf::RenderWindow* window){};

Pokemon* Player::get_current_pokemon() { return this->current_pokemon; }

Player::~Player() {
  // Clean up resources
  delete[] pokemons;
}

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
/*         This class represents a Bot in the Pokemon Showdown game.         */
/*        It is a derived class of the Player class and overrides the        */
/*       make_choice, make_move, and swap_pokemon functions to provide       */
/*                         bot-specific behavior.                            */
/*                                                                           */
/*****************************************************************************/

#include "bot.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "move.hpp"
#include "pokemon.hpp"

Bot::Bot(std::string name, vector<Pokemon*> pokemons)
    : Player(name, pokemons){};

void Bot::make_choice() {
  // Generate a random probability between 0 and 10
  double prob = double(rand()) % 10;
  // 90% chance to make a move, 10% chance to swap Pokemon
  if (prob < 9) {
    make_move();
  } else {
    swap_pokemon();
  }
}

Move Bot::make_move() { return get_move()[rand() % get_move().size()]; };

void Bot::swap_pokemon() {
  current_pokemon = this->pokemons[rand() % this->pokemons.size()];
};
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

Bot::Bot(vector<Pokemon> pokemons) : Player(pokemons){};

void Bot::bot_make_choice() {
  // Generate a random probability between 0 and 10
  int prob = rand() % 10;
  // 90% chance to make a move, 10% chance to swap Pokemon
  if (prob < 9) {
    make_move(rand() % this->getPokemons()->size());
  } else {
    swap_pokemon(rand() % get_current_pokemon()->get_moves().size());
  }
}

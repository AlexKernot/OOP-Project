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

#include "bot.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "move.hpp"
#include "pokemon.hpp"

Bot::Bot(std::string name, vector<Pokemon*> pokemons)
    : Player(name, pokemons){};

void Bot::make_choice() {
  double prob = double(rand()) % 10;
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
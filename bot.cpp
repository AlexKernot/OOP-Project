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

Bot::Bot(vector<Pokemon> pokemons) : Player(pokemons) {
  for (size_t i = 0; i < pokemons.size(); ++i) {
    set_position(i, sf::Vector2i(500, 40));
  }
};

bool Bot::CheckLoss() {
  size_t size = getPokemons()->size();
  for (size_t i = 0; i < size; ++i) {
    if (getPokemons()->at(i).GetIsFainted() == false)
      return false;
  }
  return true;
}

int Bot::bot_make_choice() {
  if (getPokemons()->at(get_current_pokemon()).GetIsFainted() == true)
  {
    if (CheckLoss() == true)
      return -1;
    return 1;
  }
  // Generate a random probability between 0 and 10
  int prob = rand() % 10;
  // 90% chance to make a move, 10% chance to swap Pokemon
  if (prob < 9)
    return 0;
  return 1;
}

void Bot::swap_pokemon() {
  int number = 0;
  while (true) {
    number = rand() % getPokemons()->size();
    if (number == get_current_pokemon())
      continue;
    if (getPokemons()->at(number).GetIsFainted() == true)
      continue;
    set_current_pokemon(number);
    return ;
  }
}

Move Bot::make_move() {
  int number = 0;
  vector<Move *> tempMove = getPokemons()->at(get_current_pokemon()).get_moves();
  number = rand() % tempMove.size();
  return *tempMove.at(number);
}
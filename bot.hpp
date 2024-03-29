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

#ifndef BOT_H
#define BOT_H

#include "move.hpp"
#include "player.hpp"
#include "pokemon.hpp"

class Bot : public Player {
 public:
  Bot() : Player() {}
  Bot(vector<Pokemon> pokemons);
  int bot_make_choice();
  void swap_pokemon();
  Move make_move();
private:
  bool CheckLoss();
};

#endif
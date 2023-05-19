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

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "move.hpp"
#include "pokemon.hpp"
#include "renderable.hpp"

class Player : public Renderable {
 private:
  std::vector<Pokemon*> pokemons;
  Pokemon* current_pokemon;
  std::string name;
  std::string choice;

 public:
  Player(std::string name, vector<Pokemon*> pokemons);
  void draw();
  virtual Move make_move();
  virtual void swap_pokemon();  // make it virtual --> add to bot
  virtual void make_choice();   // 10% swap_pokemon - bot
  Pokemon get_current_pokemon();
  ~Player();
};

#endif
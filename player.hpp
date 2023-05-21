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
/*        This is the class that handles Players. Players will               */
/*                 direct their 6 Pokemon and 4 moves                        */
/*                                                                           */
/*****************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "move.hpp"
#include "pokemon.hpp"
#include "renderable.hpp"
#include "window.hpp"

class Player : public Renderable {
 private:
  std::vector<Pokemon*> pokemons;
  Pokemon* current_pokemon;
  std::string name;
  std::string choice;

 public:
  Player(std::string name, vector<Pokemon*> pokemons);
  void Draw(sf::RenderWindow* window){};
  virtual Move make_move(sf::RenderWindow* window);
  virtual void swap_pokemon(sf::RenderWindow* window);  // make it virtual --> add to bot
  virtual void make_choice(sf::RenderWindow* window);   // 10% swap_pokemon - bot
  Pokemon* get_current_pokemon();
  ~Player();
};

#endif
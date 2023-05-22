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
  std::vector<Move> moves;
  Move* current_move;
  std::string name;
  std::string choice;

 public:
  Player(std::string name, vector<Pokemon*> pokemons);
  void Draw(sf::RenderWindow* window);
  virtual void swap_pokemon(int i);  
  virtual void make_move(int i);   
  Pokemon* get_current_pokemon();
  ~Player();
};

#endif
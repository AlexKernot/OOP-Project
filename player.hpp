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
    std::vector<Pokemon> pokemons;
    int current_pokemon;
    std::vector<Move*> moves;
    Move* current_move;
    std::string name;
    std::string choice;

  public:
    Player();
    Player(vector<Pokemon> pokemons);
    Player(const Player& player);
    Player& operator=(const Player& player);
    void Draw(sf::RenderWindow* window);
    void swap_pokemon(int i);
    Move *make_move(int i);
    int get_current_pokemon();
    void set_current_pokemon(int index) {current_pokemon = index;}
    std::vector<Pokemon> *getPokemons();
    ~Player() {};
};

#endif
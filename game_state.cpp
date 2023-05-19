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

#include "game_state.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "bot.hpp"
#include "player.hpp"
#include "renderable.hpp"

Gamestate::Gamestate() : current_turn(0) {
  players[0] = new Player();
  players[1] = new Bot();
};

void Gamestate::swap_move() {
  if (current_turn = 0) {
    if (players[0].make_choice() == "Make move") {
      players[0].make_move();
    } else if (players[0].make_choice() == "Swap Pokemon") {
      players[0].swap_pokemon();
    }
    current_turn++;
  } else {
    players[1].make_choice();
    current_turn--;
  }
};

void Gamestate::start_game() {
  
}
/*
start game function: players, pokemon, game mode

*/
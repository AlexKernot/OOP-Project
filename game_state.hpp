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
/*        This class represents the game state and its logic                 */
/*        It manages the players, their turns, and the game board            */
/*                                                                           */
/*****************************************************************************/

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "game_container.hpp"
#include "player.hpp"
#include "bot.hpp"

class Gamestate : public Game_container {
 private:
  std::vector<Button*> pokemon_buttons;
  std::vector<Button*> move_buttons;
  int gamemode;
  int current_turn = 0;
  Player *player1;
  Bot *player2;

 public:
  Gamestate();
  ~Gamestate();
  void ButtonClick();
  void StartGame();
private:
  void CreatePokemon();
  void AddButtons();
  void DisablePokemonButtons();
  void EnablePokemonButtons();
  void EnableMoveButtons();
  void DisableMoveButtons();
  void UpdateButtons(Pokemon pokemon);
};

#endif
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

#include "game_state.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "bot.hpp"
#include "button.hpp"
#include "player.hpp"
#include "pokemon.hpp"

// Constructor
Gamestate::Gamestate() : current_turn(0) {
  player1 = Player();
  player2 = Bot();
}

// Create buttons
void Gamestate::buttons() {
  // Create swap pokemon buttons
  std::vector<sf::Vector2f> pokemon_coords = {};
  for (int i = 0; i < 6; ++i) {
    pokemon_buttons[i] = Button();
    pokemon_buttons[i].SetPosition(static_cast<sf::Vector2i>(pokemon_coords[i]));
    pokemon_buttons[i].SetText(player1.getPokemons()[i]->get_name());
    AddToWindow(&pokemon_buttons[i]);
  }

  // Create move buttons
  std::vector<sf::Vector2f> moves_coords;
  for (int i = 0; i < player1.get_current_pokemon()->get_moves().size();
       ++i) {
    move_buttons[i] = Button();
    move_buttons[i].SetText(player1.get_current_pokemon()->get_moves()[i]->get_name());
  }
}


void Gamestate::swap_move() {
  // Player's turn
  if (current_turn == 0) {
    // swap pokemon
    for (int i = 0; i < pokemon_buttons.size(); ++i) {
      if (pokemon_buttons[i].ClickedOn(sf::Mouse::getPosition())) {
        player1.swap_pokemon(i);
      }
    }
    // make move
    for (int i = 0; i < move_buttons.size(); ++i) {
      if (move_buttons[i].ClickedOn(sf::Mouse::getPosition())) {
        player1.make_move(i);
      }
    }
    current_turn++;
  }

  // Bot's turn
  else {
    player2.bot_make_choice();
    current_turn--;
  }
}

void Gamestate::StartGame() {
  int gameMode = MainMenu();
  if (gameMode == -1)
    return;
  ClearEntireWindow();
  add_sprite("Battleui", "./resources/bg_battle.png");
  set_size(0, sf::Vector2f(0.75f, 0.75f));
  set_position(0, sf::Vector2i(200, 0));
  add_sprite("player 2_HP", "./resources/health bar.jpg");
  set_size(1, sf::Vector2f(0.20f, 0.20f));
  set_position(1, sf::Vector2i(680, 0));
  add_sprite("player 1_HP", "./resources/health bar.jpg");
  set_size(2, sf::Vector2f(0.20f, 0.20f));
  set_position(2, sf::Vector2i(300, 380));
  AddToWindow(this);
  buttons();
  while (true) {
    sf::Event event;
    while (Window::PollEvent(&event)) {
      if (event.type == sf::Event::Closed)
      {
        std::cout << "Close\n";
        return ;
      }
    if (event.type == sf::Event::MouseButtonPressed) {
      ButtonPress(event);
    }
  }
  RenderWindow();
}
}
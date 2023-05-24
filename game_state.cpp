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

Gamestate::~Gamestate() {
  size_t pokemonSize = pokemon_buttons.size();
  size_t moveSize = move_buttons.size();
  for (size_t i = 0; i < pokemonSize; ++i)
    delete pokemon_buttons[i];
  for (size_t i = 0; i < moveSize; ++i)
    delete move_buttons[i];
}

void Gamestate::swap_move() {
  // Player's turn
  if (current_turn == 0) {
    // swap pokemon
    int sizePokemonButtons = static_cast<int>(pokemon_buttons.size());
    for (int i = 0; i < sizePokemonButtons; ++i) {
      if (pokemon_buttons[i]->ClickedOn(sf::Mouse::getPosition())) {
        player1.swap_pokemon(i);
      }
    }
    // make move
    int sizeMoveButtons = static_cast<int>(move_buttons.size());
    for (int i = 0; i < sizeMoveButtons; ++i) {
      if (move_buttons[i]->ClickedOn(sf::Mouse::getPosition())) {
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

// Create buttons
void Gamestate::AddButtons() {
  // Create swap pokemon buttons
  const std::vector<sf::Vector2i> pokemon_coords = {
    sf::Vector2i(10, 100),
    sf::Vector2i(10, 150),
    sf::Vector2i(10, 200),
    sf::Vector2i(10, 250),
    sf::Vector2i(10, 300),
    sf::Vector2i(10, 350)
    };
  for (int i = 0; i < 6; ++i) {
    pokemon_buttons.push_back(new Button());
    pokemon_buttons[i]->SetPosition(pokemon_coords[i]);
    pokemon_buttons[i]->SetSize(sf::Vector2f(0.5, 0.5));
    pokemon_buttons[i]->SetText(player1.getPokemons()->at(i).get_name());
    AddToWindow(pokemon_buttons[i]);
  }
  // Create move buttons
  const std::vector<sf::Vector2i> move_coords = {
    sf::Vector2i(200, 400),
    sf::Vector2i(500, 500),
    sf::Vector2i(200, 400),
    sf::Vector2i(500, 500)
  };
  int size_team = 
          static_cast<int>(player1.get_current_pokemon()->get_moves().size());
          std::cout << size_team;
  for (int i = 0; i < size_team;
       ++i) {
    move_buttons.push_back(new Button());
    move_buttons[i]->SetPosition(move_coords[i]);
    move_buttons[i]->SetSize(sf::Vector2f(0.5, 0.5));
    move_buttons[i]->SetText(player1.get_current_pokemon()->get_moves()[i]->get_name());
    AddToWindow(move_buttons[i]);
  }
}

void Gamestate::StartGame() {
  int gameMode = MainMenu();
  if (gameMode == -1)
    return;
  ClearEntireWindow();
  player1.get_current_pokemon()->PrettyPrint();
  AddGameSprites();
  AddButtons();
  while (true) {
    sf::Event event;
    while (Window::PollEvent(&event)) {
      if (event.type == sf::Event::Closed) {
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
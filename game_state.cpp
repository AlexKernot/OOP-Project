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

//  ructor
Gamestate::Gamestate() : current_turn(0) {
  std::vector<Pokemon> pokemon = {Pokemon("Ditto", Type("Normal"), Type("NULL"), Stats(1, 1, 1, 1, 1, 1), {Move(), Move(), Move(), Move()}, 1), Pokemon(), Pokemon(), Pokemon(), Pokemon(), Pokemon()};
  player1 = new Player(pokemon);
  player2 = new Bot(pokemon);
}

Gamestate::~Gamestate() {
  size_t pokemonSize = pokemon_buttons.size();
  size_t moveSize = move_buttons.size();
  for (size_t i = 0; i < pokemonSize; ++i)
    delete pokemon_buttons[i];
  for (size_t i = 0; i < moveSize; ++i)
    delete move_buttons[i];
}

void Gamestate::ButtonClick() {
  // Player's turn
  if (current_turn == 0) {
    // swap pokemon
    int sizePokemonButtons = static_cast<int>(pokemon_buttons.size());
    for (int i = 0; i < sizePokemonButtons; ++i) {
      if (pokemon_buttons[i]->ClickedOn(sf::Mouse::getPosition(*GetWindow()))) {
        pokemon_buttons.at(player1->get_current_pokemon())->EnableButton();
        pokemon_buttons.at(i)->DisableButton();
        player1->swap_pokemon(i);
        std::cout << "You swapped to Pokemon: " 
        << player1->getPokemons()->at(i).get_name() << std::endl;
        ++current_turn;
        return ;
      }
    }
    // make move
    int sizeMoveButtons = static_cast<int>(move_buttons.size());
    for (int i = 0; i < sizeMoveButtons; ++i) {
      if (move_buttons[i]->ClickedOn(sf::Mouse::getPosition(*GetWindow()))) {
        player1->make_move(i);
        std::cout << player1->getPokemons()
          ->at(player1->get_current_pokemon()).get_name() << " used "
        << player1->getPokemons()->at(player1->get_current_pokemon())
          .get_moves().at(i)->get_name() 
        << " on " << player2->getPokemons()->at(player1->get_current_pokemon())
          .get_name() << std::endl;
        ++current_turn;
        Pokemon *tempPokemon = &player1->getPokemons()
          ->at(player1->get_current_pokemon());
        player2->getPokemons()->at(player2->get_current_pokemon())
          .receive_move(
            *tempPokemon->get_moves().at(i), tempPokemon->get_level(), 
            tempPokemon->get_stats().GetAttack(), 
            tempPokemon->get_base_stats().GetAttack());
        return ;
      }
    }
  }
}

// Create buttons
void Gamestate::AddButtons() {
  // Create swap pokemon buttons
    std::vector<sf::Vector2i> pokemon_coords = {
    sf::Vector2i(20, -10),
    sf::Vector2i(20, 100),
    sf::Vector2i(20, 200),
    sf::Vector2i(20, 300),
    sf::Vector2i(20, 400),
    sf::Vector2i(20, 500)
    };
  for (int i = 0; i < 6; ++i) {
    pokemon_buttons.push_back(new Button());
    pokemon_buttons[i]->SetPosition(pokemon_coords[i]);
    pokemon_buttons[i]->SetSize(sf::Vector2f(0.5, 0.80));
    pokemon_buttons[i]->SetText(player1->getPokemons()->at(i).get_name());
    AddToWindow(pokemon_buttons[i]);
  }
  // Create move buttons
    std::vector<sf::Vector2i> move_coords = {
    sf::Vector2i(225, 435),
    sf::Vector2i(515, 515),
    sf::Vector2i(515, 435),
    sf::Vector2i(225, 515)
  };
  int size_team = 
          static_cast<int>(player1->getPokemons()
            ->at(player1->get_current_pokemon()).get_moves().size());
  for (int i = 0; i < size_team;
       ++i) {
    move_buttons.push_back(new Button());
    move_buttons[i]->SetPosition(move_coords[i]);
    move_buttons[i]->SetSize(sf::Vector2f(0.70, 0.70));
    move_buttons[i]->SetText(player1->getPokemons()
      ->at(player1->get_current_pokemon()).get_moves()[i]->get_name());
    AddToWindow(move_buttons[i]);
  }
  /*  The current pokemon will always start as the first one.  */
  /*   This disables that button.  */
  pokemon_buttons[0]->DisableButton();
}

void Gamestate::StartGame() {
  int gameMode = MainMenu();
  if (gameMode == -1)
    return;
  ClearEntireWindow();
  AddGameSprites();
  AddToWindow(player1);
  UpdateHealth(1, player1->getPokemons()
    ->at(player1->get_current_pokemon()).get_max_hp());
  AddToWindow(player2);
  UpdateHealth(1, player2->getPokemons()
    ->at(player2->get_current_pokemon()).get_max_hp());
  AddButtons();
  while (true) {
    sf::Event event;
    while (Window::PollEvent(&event)) {
      if (event.type == sf::Event::Closed) {
        std::cout << "Close\n";
        return ;
      }
      if (event.type == sf::Event::MouseButtonPressed) {
        ButtonClick();
      }
      if (current_turn == 1) {
        Pokemon *tempPokemon = &player2->getPokemons()
          ->at(player2->get_current_pokemon());
        Move move = player2->make_move();
        if (player2->bot_make_choice() == 0) {
          player1->getPokemons()->at(player1->get_current_pokemon())
            .receive_move(move, tempPokemon->get_level(), 
              tempPokemon->get_stats().GetAttack(), tempPokemon
                ->get_base_stats().GetAttack());
            std::cout << tempPokemon->get_name() << " used " 
              << move.get_name() << std::endl;
        } else {
          std::cout << "Bot switched out " 
          << player2->getPokemons()
            ->at(player2->get_current_pokemon()).get_name()
          << " into ";
          player2->swap_pokemon();
          std::cout << player2->getPokemons()
            ->at(player2->get_current_pokemon()).get_name()
          << std::endl;
        }
        current_turn--;
      }
    }
  UpdateHealth(1, player1->getPokemons()
    ->at(player1->get_current_pokemon()).get_hp());
  UpdateHealth(2, player2->getPokemons()
    ->at(player2->get_current_pokemon()).get_hp());
  RenderWindow();
  }
}
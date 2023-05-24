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
#include <cstdlib>
#include <time.h>

#include "bot.hpp"
#include "button.hpp"
#include "player.hpp"
#include "pokemon.hpp"
#include "readPokemonTeam.hpp"
#include "generateRandomPokemon.hpp"

//  ructor
Gamestate::Gamestate() : current_turn(0) {}

void Gamestate::CreatePokemon() {
  srand(time(0));
  if (gamemode == 2) {
    std::vector<Pokemon> playerPokemon;
    std::vector<Pokemon> botPokemon;
    for (int i = 0; i < 6; ++i) {
      playerPokemon.push_back(GenerateRandomPokemon());
      botPokemon.push_back(GenerateRandomPokemon());
    }
    player1 = new Player(playerPokemon);
    player2 = new Bot(botPokemon);
  }
  if (gamemode == 1) {
    std::string input;
    std::cout << "Please enter the name of your file relative "
    << "to the resources/playerTeams folder and without the .json prefix" << std::endl;
    std::cin >> input;
    std::vector<Pokemon> playerPokemon;
    std::vector<Pokemon> botPokemon;
    bool generateAll = true;
    for (int i = 0; i < 6; ++i) {
      if (generateAll == true) {
        playerPokemon.push_back(ReadPokemonTeam("playerTeams/" + input, i));
        generateAll = ReadPokemonTeam("playerTeams/" + input, i).GetGenerateAll();
      } else {
        playerPokemon.push_back(GenerateRandomPokemon());
      }
      botPokemon.push_back(GenerateRandomPokemon());
    }
    player1 = new Player(playerPokemon);
    player2 = new Bot(botPokemon);
  }
}

Gamestate::~Gamestate() {
  delete player1;
  delete player2;
  size_t pokemonSize = pokemon_buttons.size();
  size_t moveSize = move_buttons.size();
  for (size_t i = 0; i < pokemonSize; ++i)
    delete pokemon_buttons[i];
  for (size_t i = 0; i < moveSize; ++i)
    delete move_buttons[i];
}

void Gamestate::DisableMoveButtons() {
  for (size_t i = 0; i < move_buttons.size(); ++i) {
    move_buttons[i]->DisableButton();
  }
}

void Gamestate::DisablePokemonButtons() {
  for (size_t i = 0; i < pokemon_buttons.size(); ++i) {
    pokemon_buttons[i]->DisableButton();
  }
}

void Gamestate::EnablePokemonButtons() {
  for (size_t i = 0; i < pokemon_buttons.size(); ++i) {
    if (static_cast<int>(i) == player1->get_current_pokemon())
      continue;
    if (player1->getPokemons()->at(i).GetIsFainted() == true)
      continue;
    pokemon_buttons[i]->EnableButton();
  }
}

void Gamestate::EnableMoveButtons() {
  for (size_t i = 0; i < move_buttons.size(); ++i) {
    move_buttons[i]->EnableButton();
  }
}

void Gamestate::UpdateButtons(Pokemon pokemon) {
  move_buttons[0]->SetText(pokemon.get_moves()[0]->get_name());
  move_buttons[1]->SetText(pokemon.get_moves()[1]->get_name());
  move_buttons[2]->SetText(pokemon.get_moves()[2]->get_name());
  move_buttons[3]->SetText(pokemon.get_moves()[3]->get_name());
}

void Gamestate::ButtonClick() {
  // Player's turn
  if (current_turn == 0) {
    // swap pokemon
    int sizePokemonButtons = static_cast<int>(pokemon_buttons.size());
    for (int i = 0; i < sizePokemonButtons; ++i) {
      if (pokemon_buttons[i]->ClickedOn(sf::Mouse::getPosition(*GetWindow()))) {
        player1->swap_pokemon(i);
        UpdateButtons(player1->getPokemons()->at(i));
        DisablePokemonButtons();
        EnablePokemonButtons();
        std::cout << "You: swapped to Pokemon: " 
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
        std::cout << "You: " << player1->getPokemons()
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
  DisablePokemonButtons();
  EnablePokemonButtons();
}

void Gamestate::StartGame() {
  ClearEntireWindow();
  gamemode = MainMenu();
  if (gamemode == -1)
    return;
  CreatePokemon();
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
      if (player1->getPokemons()
        ->at(player1->get_current_pokemon()).GetIsFainted())
      {
        DisableMoveButtons();
        if (event.type == sf::Event::MouseButtonPressed) {
          ButtonClick();
          if (player1->getPokemons()
            ->at(player1->get_current_pokemon()).GetIsFainted() == false) {
              EnableMoveButtons();
              DisablePokemonButtons();
              EnablePokemonButtons();
              --current_turn;
            }
        }
      }
      if (event.type == sf::Event::Closed)
        return ;
      if (event.type == sf::Event::MouseButtonPressed)
        ButtonClick();
      if (current_turn == 1) {
        Pokemon *tempPokemon = &player2->getPokemons()
          ->at(player2->get_current_pokemon());
        Move move = player2->make_move();
        int botChoice = player2->bot_make_choice();
        if (botChoice == -1) {
          std::cout << "\nYou win!!" << std::endl;
          return ;
        }
        if (botChoice == 0) {
          player1->getPokemons()->at(player1->get_current_pokemon())
            .receive_move(move, tempPokemon->get_level(), 
              tempPokemon->get_stats().GetAttack(), tempPokemon
                ->get_base_stats().GetAttack());
            std::cout << "Bot: " << tempPokemon->get_name() << " used " 
              << move.get_name() << std::endl;
        if (player1->getPokemons()
          ->at(player1->get_current_pokemon()).GetIsFainted())
          std::cout << "You: " << player1->getPokemons()
            ->at(player1->get_current_pokemon()).get_name() 
          << " fainted. Please switch pokemon." << std::endl;
        } else {
          std::cout << "Bot: switched out " 
          << player2->getPokemons()
            ->at(player2->get_current_pokemon()).get_name()
          << " into ";
          player2->swap_pokemon();
          std::cout << player2->getPokemons()
            ->at(player2->get_current_pokemon()).get_name()
          << std::endl;
        }
        --current_turn;
      }
    }
  UpdateHealth(1, player1->getPokemons()
    ->at(player1->get_current_pokemon()).get_hp());
  UpdateHealth(2, player2->getPokemons()
    ->at(player2->get_current_pokemon()).get_hp());
  RenderWindow();
  }
}
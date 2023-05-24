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

#include "player.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "button.hpp"
#include "move.hpp"
#include "pokemon.hpp"

/* Constructor for the Player class */
Player::Player() {
  for (int i = 0; i < 6; ++i) {
    pokemons.push_back(Pokemon());
  }
  current_pokemon = 0;
  moves = pokemons.at(current_pokemon).get_moves();
}

/* Copy Constructor for Player */
Player::Player(const Player& player) {
  int pokemonSize = static_cast<int>(player.pokemons.size());
  pokemons.resize(pokemonSize);
  for (int i = 0; i < pokemonSize; ++i) {
    pokemons.push_back(player.pokemons[i]);
  }
  int moveSize = static_cast<int>(player.moves.size());
  pokemons.resize(moveSize);
  for (int i = 0; i < moveSize; ++i) {
    moves.push_back(player.moves[i]);
  }
  current_pokemon = player.current_pokemon;
}

/* Assignment operator for Player class */
Player& Player::operator=(const Player& player) {
  Renderable::operator=(player);
  return *this;


  int pokemonSize = static_cast<int>(player.pokemons.size());
  pokemons.resize(pokemonSize);
  for (int i = 0; i < pokemonSize; ++i) {
    pokemons[i] = player.pokemons[i];
  }
  int moveSize = static_cast<int>(player.moves.size());
  moves.resize(moveSize);
  for (int i = 0; i < moveSize; ++i) {
    moves[i] = player.moves[i];
  }
  current_pokemon = player.current_pokemon;
  return *this;
}

/* Sets up Sprites for every Pokemon */
Player::Player(std::vector<Pokemon> pokemons) {
  this->pokemons = pokemons;
  current_pokemon = 0;
  this->moves = pokemons.at(current_pokemon).get_moves();
  for (size_t i = 0; i < pokemons.size(); ++i) {
    std::string name = pokemons.at(i).get_name();
    if (name == "Missingno") {
      add_sprite("Pokemon" + std::to_string(i), "resources/sprites/" + name + ".png");
      set_size(i, sf::Vector2f(0.4, 0.4));
      set_position(i, sf::Vector2i(300, 300));
    } else {
      add_sprite("Pokemon" + std::to_string(i), "resources/sprites/" + name + ".bmp");
      set_size(i, sf::Vector2f(2, 2));
      set_position(i, sf::Vector2i(300, 300));
    }
  }
}

// This allows the Player to make a move
Move *Player::make_move(int i) { return moves[i]; }

// This allows the Player to swap between Pokemons
void Player::swap_pokemon(int i) { current_pokemon = i; }

int Player::get_current_pokemon() { return current_pokemon; }

std::vector<Pokemon> *Player::getPokemons() { return &pokemons; }

void Player::Draw(sf::RenderWindow* window) {
  //add_sprite("Test", "resources/placeholder.png");
  sf::Sprite sprite = *get_sprite(current_pokemon);
  window->draw(sprite);
  return ;
}
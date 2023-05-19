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

#include "player.hpp"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "pokemon.hpp"
#include "random_pokemon.hpp"

Player::Player(std::string name, vector<Pokemon*> pokemons) {
  this->name = name;
  this->pokemons = pokemons;
}

void Player::draw(){
    //
};

Move Player::make_move() {
  // Add sprite
  add_sprite("make_choice_sprite");

  // Create text messsage
  sf::Text make_move_message;
  make_move_message.setCharacterSize(20);
  make_move_message.setFillColor(sf::Color::White);
  // make_move_message.setPosition(100, 100);
  make_move_message.setString("Your turn! Choose a move:");
};

void Player::make_choice() {
  // Add make_choice sprite
  add_sprite("make_choice_sprite");

  //  Create text message
  sf::Text make_choice_message;
  make_choice_message.setCharacterSize(20);
  make_choice_message.setFillColor(sf::Color::White);
  // make_choice_message.setPosition(100, 100);
  make_choice_message.setString("What would you like to do?\n");
};

void Player::swap_pokemon() {
  // Add swap_pokemon sprite
  add_sprite("make_choice_sprite");

  //  Create text message
  sf::Text swap_pokemon_message;
  swap_pokemon_message.setCharacterSize(20);
  swap_pokemon_message.setFillColor(sf::Color::White);
  // make_move_message.setPosition(100, 100);
  swap_pokemon_message.setString("Choose a Pokémon to swap:");
};

Pokemon Player::get_current_pokemon() { return this->current_pokemon; };

Player::~Player() { delete[] pokemons; }
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
/*        This is the class that handles Players. Players will               */
/*                 direct their 6 Pokemon and 4 moves                        */
/*                                                                           */
/*****************************************************************************/

#include "player.hpp"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "pokemon.hpp"
#include "random_pokemon.hpp"

/*Player constructor that creates 1 player and a vector of the Pokemon in the Players team*/
Player::Player(std::string name, vector<Pokemon*> pokemons) {
  this->name = name;
  this->pokemons = pokemons;
}

/*This will draw the sprite of the Pokemon out on battle*/
void Player::draw(sf::RenderWindow *window) {
    //
}

/*This allows the player to allow the Pokemon to execute the move the user will select*/
Move Player::make_move() {
  // Add sprite
  add_sprite("make_choice_sprite");

  // Create text messsage
  sf::Text make_move_message;
  make_move_message.setCharacterSize(20);
  make_move_message.setFillColor(sf::Color::White);
  // make_move_message.setPosition(100, 100);
  make_move_message.setString("Your turn! Choose a move:");
}

/*This allows the Player to choose which move the Pokemon should execute*/
void Player::make_choice() {
  // Add make_choice sprite
  add_sprite("make_choice_sprite");

  //  Create text message
  sf::Text make_choice_message;
  make_choice_message.setCharacterSize(20);
  make_choice_message.setFillColor(sf::Color::White);
  // make_choice_message.setPosition(100, 100);
  make_choice_message.setString("What would you like to do?\n");
}

/*This allows for the Player to swap between Pokemon*/
void Player::swap_pokemon() {
  // Add swap_pokemon sprite
  add_sprite("make_choice_sprite");

  //  Create text message
  sf::Text swap_pokemon_message;
  swap_pokemon_message.setCharacterSize(20);
  swap_pokemon_message.setFillColor(sf::Color::White);
  // make_move_message.setPosition(100, 100);
  swap_pokemon_message.setString("Choose a Pokémon to swap:");
}

/*Returns the current Pokemon on the battlefield*/
Pokemon Player::get_current_pokemon() { 
  return this->current_pokemon; 
}

/*deletes the Player object*/
Player::~Player() {
  delete[] pokemons;
}
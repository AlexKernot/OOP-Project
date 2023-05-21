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
/*        direct their 6 Pokemon and 4 moves                                 */
/*                                                                           */
/*****************************************************************************/

#include "player.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "pokemon.hpp"
#include "renderable.hpp"
#include "sprites.hpp"
#include "window.hpp"

Player::Player(std::string name, std::vector<Pokemon*> pokemons) {
  this->name = name;
  this->pokemons = pokemons;
}

/******************************** MAKE CHOICE ********************************/
void Player::make_choice(sf::RenderWindow* window) {
  // Create the renderable object
  Renderable make_choice;

  // Create the swap_pokemon_sprite
  sf::Sprite* swap_pokemon_sprite =
      make_choice.add_sprite("swap_pokemon_sprite", "./resources/Box.PNG");

  // Create the make_move_sprite
  sf::Sprite* make_move_sprite =
      make_choice.add_sprite("make_move_sprite", "./resources/Box.PNG");

  // Set the texture rectangles for each sprite to display the appropriate image
  swap_pokemon_sprite->setTextureRect(sf::IntRect(0, 0, 100, 100));
  make_move_sprite->setTextureRect(sf::IntRect(100, 0, 100, 100));

  // Set the positions of the sprites
  swap_pokemon_sprite->setPosition(200, 200);
  make_move_sprite->setPosition(400, 200);

  // Create the text message
  sf::Text make_choice_message;
  make_choice_message.setCharacterSize(20);
  make_choice_message.setFillColor(sf::Color::White);
  make_choice_message.setString("What would you like to do?\n");

  // Handle player input
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          // Check if the player clicked on the swap sprite
          if (swap_pokemon_sprite->getGlobalBounds().contains(
                  event.mouseButton.x, event.mouseButton.y)) {
            window->clear();
            swap_pokemon(window);
            break;
          }
          // Check if the player clicked on the move sprite
          else if (make_move_sprite->getGlobalBounds().contains(
                       event.mouseButton.x, event.mouseButton.y)) {
            window->clear();
            make_move(window);
            break;
          }
        }
      }
    }
  }
}

/********************************* MAKE MOVE **********************************/
Move Player::make_move(sf::RenderWindow* window) {
  // Create the renderable object
  Renderable make_move;

  // Create the text message
  sf::Text make_move_message;
  make_move_message.setCharacterSize(20);
  make_move_message.setFillColor(sf::Color::White);
  make_move_message.setString("Your turn! Choose a move:");

  // Get the moves vector from the current Pokémon
  std::vector<Move> moves = current_pokemon->get_moves();

  // Create a sprite for each move
  for (int i = 0; i < moves.size(); ++i) {
    sf::Sprite* move_sprite = make_move.add_sprite(
        "move_sprite_" + std::to_string(i), moves[i].get_sprite_path());
    move_sprite->setPosition(200 + (i % 2) * 200, 200 + (i / 2) * 200);
  }

  // Handle player input
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          // Check if the player clicked on any of the move sprites
          for (int i = 0; i < moves.size(); ++i) {
            sf::Sprite* move_sprite = make_move.get_sprite(i);
            if (move_sprite->getGlobalBounds().contains(event.mouseButton.x,
                                                        event.mouseButton.y)) {
              // Player chose the move at index i, handle the choice
              return moves[i];
            }
          }
        }
      }
    }
  }
}

/******************************** SWAP POKEMON ********************************/
/* This allows the Player to swap between Pokemon */
void Player::swap_pokemon(sf::RenderWindow* window) {
  // Create the renderable object
  Renderable swap_pokemon;

  // Create the text message
  sf::Text swap_pokemon_message;
  swap_pokemon_message.setCharacterSize(20);
  swap_pokemon_message.setFillColor(sf::Color::White);
  swap_pokemon_message.setString("Choose a Pokémon to swap:");

  // Create a sprite for each Pokemon
  for (int i = 0; i < pokemons.size(); ++i) {
    sf::Sprite* pokemon_sprite = swap_pokemon.add_sprite(
        "pokemon_sprite_" + std::to_string(pokemons[i]->get_pokemon_name()),
        "./resources/Box.PNG");
    pokemon_sprite->setPosition(100 + (i * 150), 200);

    // Add text with the Pokemon name
    sf::Text pokemon_name_text;
    pokemon_name_text.setCharacterSize(16);
    pokemon_name_text.setFillColor(sf::Color::White);
    pokemon_name_text.setString(pokemons[i]->get_pokemon_name());
    pokemon_name_text.setPosition(pokemon_sprite->getPosition().x,
                                  pokemon_sprite->getPosition().y +
                                      pokemon_sprite->getGlobalBounds().height +
                                      10);

    // Draw the sprite and text
    window->draw(*pokemon_sprite);
    window->draw(pokemon_name_text);
  }

  // Display the window
  window->display();

  // Handle player input
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          // Check if the player clicked on any of the Pokemon sprites
          for (int i = 0; i < pokemons.size(); ++i) {
            sf::Sprite* pokemon_sprite =
                swap_pokemon.get_sprite("pokemon_sprite_" + std::to_string(i));
            if (pokemon_sprite->getGlobalBounds().contains(
                    event.mouseButton.x, event.mouseButton.y)) {
              this->current_pokemon = *pokemons[i];
              break;
            }
          }
        }
      }
    }
  }
}

Pokemon* Player::get_current_pokemon() { return this->current_pokemon; }

Player::~Player() {
  // Clean up resources
  delete[] pokemons;
}

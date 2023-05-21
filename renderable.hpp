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

#include <vector>

#include "sprites.hpp"

#ifndef POKEMON_RENDERABLE_H
#define POKEMON_RENDERABLE_H

typedef struct 
{
  int x;
  int y;
} Vector2;

class Renderable {
private:
  Sprites sprite_list;
  sf::Vector2i position;
  sf::Vector2i size;

public:
  virtual void Draw(sf::RenderWindow *window) = 0;
  sf::Sprite *get_sprite(int index) {return (sprite_list.get_sprite_index(index));}
  sf::Sprite *add_sprite(std::string spriteName, std::string texturePath);
  void set_position(int index, sf::Vector2i position) {
    sprite_list.get_sprite_index(index)->setPosition(static_cast<sf::Vector2f>(position));
  }
  void set_size(int index, sf::Vector2f size) {
    sprite_list.get_sprite_index(index)->setScale(size);
  }
  bool offset_position(int index, sf::Vector2i offset);

private:
  void render_single(int index);
};

#endif
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

#include "renderable.hpp"
#include <iostream>

/* Add a sprite to the sprite list and return a pointer to the added sprite */
sf::Sprite *Renderable::add_sprite(std::string spriteName,
                                   std::string texturePath) {
  sprite_list.add_sprite(spriteName, texturePath);
  return sprite_list.get_sprite_name(spriteName);
}

/* Operator function used for new Renderble objects to copy renderable values */
Renderable& Renderable::operator=(const Renderable& renderable) {
  std::cout << "Renderable" << std::endl;
  if (this == &renderable)
    return *this;
  sprite_list = Sprites(renderable.sprite_list);
  return *this;
}
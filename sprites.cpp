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
/*        This is a file containing all of the function definitions          */
/*       for the Renderable class that is defined in 'renderable.hpp'        */
/*                                                                           */
/*****************************************************************************/

#include "sprites.hpp"

/* returns the sprite that corrosponds to a named texture within the array.   */
/* will return a null pointer if no texture with that name is found.          */
sf::Sprite *Sprites::get_sprite_name(std::string sprite_name) {
  int sprite_index = sprite_name.find(sprite_name);
  return sprites[sprite_index];
}

/* returns the sprite that corrosponds to an index within the array.         */
/* This function will return a null pointer if that index doesn't exist.     */
sf::Sprite *Sprites::get_sprite_index(int index) {
  return sprites[index];
}

/* this will free all the sprites for a given renderable object.             */
Sprites::~Sprites() {
  for (int i = 0; i < sprites.size(); ++i)
    delete sprites[i];
}
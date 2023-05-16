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

/*  Loads the texture from the relative path 'texture path' and puts the      */
/*  pointer to the sprite on the heap.                                        */
void  Sprites::add_sprite(std::string spriteName, std::string texturePath){
  sf::Sprite *newSprite = new sf::Sprite();
  sf::Texture *newTexture = new sf::Texture();
  bool loadResult = newTexture->loadFromFile(texturePath);
  if (loadResult == false)
    newTexture->loadFromFile("resources/placeholder.png");
  newSprite->setTexture(*newTexture);
  sprites.push_back(newSprite);
  textures.push_back(newTexture);
  this->spriteName.push_back(spriteName);
}

/* returns the sprite that corrosponds to a named texture within the array.   */
/* will return a null pointer if no texture with that name is found.          */
sf::Sprite *Sprites::get_sprite_name(std::string spriteName) {
  int spriteIndex = spriteName.find(spriteName);
  return sprites[spriteIndex];
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
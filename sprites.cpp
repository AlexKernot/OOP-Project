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
#include <iostream>

Sprites::Sprites() {
  sprites = std::vector<sf::Sprite*>{};
  textures = std::vector<sf::Texture*>{};
  spriteName = std::vector<std::string>{};
}

Sprites::Sprites(const Sprites& copySprites) {
  std::cout << "Sprites copy being called" << std::endl;
  size_t size = copySprites.sprites.size();
  sprites.resize(size);
  for (size_t i = 0; i < size; ++i) {
    sprites[i] = copySprites.sprites[i];
  }
  std::cout << "Copied: " << size << std::endl;
  size = copySprites.textures.size();
  textures.resize(size);
  for (size_t i = 0; i < size; ++i) {
    textures[i] = copySprites.textures[i];
  }
  size = copySprites.spriteName.size();
  spriteName.resize(size);
  for (size_t i = 0; i < size; ++i) {
    spriteName[i] = copySprites.spriteName[i];
  }
}

Sprites& Sprites::operator=(const Sprites&) {
  return *this;
}

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
/*  int size = static_cast<int>(sprites.size());
  for (int i = 0; i < size; ++i)
  {
    if (sprites[i] == nullptr)
      return;
    delete sprites[i];
  }*/
}
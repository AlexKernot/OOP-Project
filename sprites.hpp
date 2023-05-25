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
/*          This is a class containing a list of all the sprites a           */
/*       specific object will use. Each sprite will be kept on the heap.     */
/*                                                                           */
/*****************************************************************************/


#ifndef SPRITES_H
#define SPRITES_H

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

class Sprites
{
private:
  std::vector<sf::Sprite*> sprites;
  std::vector<sf::Texture*> textures;
  std::vector<std::string> spriteName;

public:
/* Constructor for the Sprites to give them texture and add them to a list */
  Sprites();
  /* Constructor that frees all the sprites for the derived object.         */
  virtual ~Sprites();
  /*  Loads the texture from the relative path 'texture path' and puts the  */
  /*  pointer to the sprite on the heap.                                    */
  void  AddSprite(std::string spriteName, std::string texturePath);
  /* Copy Constructor for Sprites */
  Sprites(const Sprites& sprites);
  /* Operator Function so Sprite value can be copied to new Sprite values */
  Sprites& operator=(const Sprites&);
  /* returns the sprite that corrosponds to a named texture within the array.*/
  /* will return a null pointer if no texture with that name is found.       */
  sf::Sprite *GetSpriteName(std::string spriteName);
  /* returns the sprite that corrosponds to an index within the array.       */
  /* This function will return a null pointer if that index doesn't exist.   */
  sf::Sprite *GetSpriteIndex(int index);
};
#endif
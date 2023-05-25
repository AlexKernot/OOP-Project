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
  sf::Sprite *GetSprite(int index) 
            {return (sprite_list.GetSpriteIndex(index));}
/* Add a sprite to the sprite list and return a pointer to the added sprite */
  sf::Sprite *AddSprite(std::string spriteName, std::string texturePath);
/* Operator function used for new Renderble objects to copy renderable values */
  Renderable& operator=(const Renderable& renderable);
/* Sets the position of a sprite at index. Takes a 2D vector of coordinates.  */
  void SetPosition(int index, sf::Vector2i position);
/* Scales the sprite at index according to the 2D vector provided.            */
  void SetSize(int index, sf::Vector2f size);
  virtual ~Renderable() {}

private:
  void render_single(int index);
};

#endif
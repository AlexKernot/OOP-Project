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
sf::Sprite *Renderable::AddSprite(std::string spriteName,
                                   std::string texturePath) {
  sprite_list.AddSprite(spriteName, texturePath);
  return sprite_list.GetSpriteName(spriteName);
}

/* Scales the sprite at index according to the 2D vector provided.            */
void Renderable::SetSize(int index, sf::Vector2f size) {
  sprite_list.GetSpriteIndex(index)->setScale(size);
}

/* Sets the position of a sprite at index. Takes a 2D vector of coordinates.  */
void Renderable::SetPosition(int index, sf::Vector2i position) {
  sprite_list.GetSpriteIndex(index)->setPosition(static_cast<sf::Vector2f>(position));
}

/* Operator function used for new Renderble objects to copy renderable values */
Renderable& Renderable::operator=(const Renderable& renderable) {
  std::cout << "Renderable" << std::endl;
  if (this == &renderable)
    return *this;
  sprite_list = Sprites(renderable.sprite_list);
  return *this;
}
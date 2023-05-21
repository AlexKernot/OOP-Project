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
  Sprites();
  ~Sprites();
  void  add_sprite(std::string spriteName, std::string texturePath);
  sf::Sprite *get_sprite_name(std::string spriteName);
  sf::Sprite *get_sprite_index(int index);
};
#endif
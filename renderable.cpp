#include "renderable.hpp"

sf::Sprite *Renderable::add_sprite(std::string spriteName, 
                                  std::string texturePath) {
  sprite_list->add_sprite(spriteName, texturePath);
  return sprite_list->get_sprite_name(spriteName);
}
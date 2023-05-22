#ifndef POKEMON_BUTTON_H
#define POKEMON_BUTTON_H

#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "renderable.hpp"

class Button : public Renderable{
  sf::Vector2i position;
  sf::Vector2i size;
  sf::Vector2i boundsTopLeft;
  sf::Vector2i boundsTopRight;
  sf::Vector2i boundsBottomLeft;
  sf::Vector2i boundsBottomRight;

  sf::Font font;
  sf::Text text;
  bool fontLoaded = false;
  bool clickable = true;

public:
  Button() : Button("resources/button.png") {}
  Button(std::string buttonTexture);
  ~Button() {};
  void SetPosition(sf::Vector2i position);
  void SetSize(sf::Vector2f scale);
  void EnableButton();
  void DisableButton();
  void SetText(std::string text);
  bool HoverOn(sf::Vector2i mouse);
  bool ClickedOn(sf::Vector2i mouse);
  std::string GetText() {  return text.getString();  }
  void Draw(sf::RenderWindow *window);
};
#endif
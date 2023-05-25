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
/*    This is the class handling Buttons on the UI with their actions.       */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "button.hpp"

/* Button Constructor that assigns font and texture */
Button::Button(std::string buttonTexture) {
  if (!font.loadFromFile("./resources/Minecraft.ttf")) {
    std::cout << "Resources folder is potentially missing.\n";
    return ;
  }
  textureName = buttonTexture;
  AddSprite("button", textureName);
  size = sf::Vector2f(350, 112);
  boundsTopLeft = sf::Vector2i(0, 0);
  boundsBottomRight = sf::Vector2i(size.x, size.y);
  fontLoaded = true;
  text.setFont(font);
  text.setCharacterSize(24);
  text.setPosition(textOffset);
}

/* Copy Constructor for Button */
Button::Button(const Button& button) {
  if (!font.loadFromFile("./resources/Minecraft.ttf")) {
    std::cout << "Resources folder is potentially missing.\n";
    return ;
  }
  textureName = button.textureName;
  AddSprite("Button_Copy", textureName);
  position = button.position;
  size = button.size;
  text = button.text;
  boundsBottomRight = button.boundsBottomRight;
  boundsTopLeft = button.boundsTopLeft;
  fontLoaded = button.fontLoaded;
  clickable = button.clickable;
}

/* Assignment operator for Button to for copying button values to new buttons */
Button& Button::operator=(const Button& button) {
  if (this == &button)
    return *this;
  if (!font.loadFromFile("./resources/Minecraft.ttf")) {
    std::cout << "Resources folder is potentially missing.\n";
    return *this;
  }
  textureName = button.textureName;
  AddSprite("Button_Copy", textureName);
  position = button.position;
  size = button.size;
  text = button.text;
  boundsBottomRight = button.boundsBottomRight;
  boundsTopLeft = button.boundsTopLeft;
  fontLoaded = button.fontLoaded;
  clickable = button.clickable;
  return *this;
}

/* Puts text inside button */
void Button::SetText(std::string text) {
  this->text.setString(text);
}

/* Sets Position in renderable window for the button */
void Button::SetPosition(sf::Vector2i position) {
  this->position = position;
  sf::Vector2f positionFloat = static_cast<sf::Vector2f>(position);
  GetSprite(0)->setPosition(positionFloat);
  boundsTopLeft = sf::Vector2i(position.x, position.y);
  boundsBottomRight = sf::Vector2i(position.x + size.x, position.y + size.y);
  text.setPosition(positionFloat + textOffset);
}

/* Checks if mouse is hovering on button */
bool Button::HoverOn(sf::Vector2i mouse) {
  if (clickable == false)
    return false;
  if (mouse.x < boundsTopLeft.x || mouse.x > boundsBottomRight.x)
    return false;
  if (mouse.y < boundsTopLeft.y || mouse.y > boundsBottomRight.y)
    return false;
  return true;
}

/* Sets the size of the button */
void Button::SetSize(sf::Vector2f scale) {
  GetSprite(0)->setScale(scale);
  size = sf::Vector2f(size.x * scale.x, size.y * scale.y);
  boundsTopLeft = sf::Vector2i(position.x, position.y);
  boundsBottomRight = sf::Vector2i(position.x + size.x, position.y + size.y);
}

/* Allows clicking on button */
void Button::EnableButton() {
  clickable = true;
  GetSprite(0)->setColor(sf::Color::White);
  text.setFillColor(sf::Color::White);
}

/* Disables clicking on button */
void Button::DisableButton() {
  clickable = false;
  GetSprite(0)->setColor(sf::Color(100, 100, 100, 200));
  text.setFillColor(sf::Color(100, 100, 100, 200));
}

/* Checks if Button has been clicked on */
bool Button::ClickedOn(sf::Vector2i mouse) {
  if (clickable == false)
    return false;
  if (mouse.x < boundsTopLeft.x || mouse.x > boundsBottomRight.x)
    return false;
  if (mouse.y < boundsTopLeft.y || mouse.y > boundsBottomRight.y)
    return false;
  return true;
}

/* Renders the buttons on the screen */
void Button::Draw(sf::RenderWindow *window) {
  if (HoverOn(sf::Mouse::getPosition(*window))) {
    text.setOutlineThickness(4);
  } else {
    text.setOutlineThickness(0);
  }
  window->draw(*GetSprite(0));
  window->draw(text);
}
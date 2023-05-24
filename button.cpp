#include "button.hpp"

Button::Button(std::string buttonTexture) {
  if (!font.loadFromFile("./resources/Minecraft.ttf")) {
    std::cout << "Resources folder is potentially missing.\n";
    return ;
  }
  textureName = buttonTexture;
  add_sprite("button", textureName);
  size = sf::Vector2f(350, 112);
  boundsTopLeft = sf::Vector2i(0, 0);
  boundsBottomRight = sf::Vector2i(size.x, size.y);
  fontLoaded = true;
  text.setFont(font);
  text.setCharacterSize(24);
  text.setPosition(textOffset);
}

Button::Button(const Button& button) {
  if (!font.loadFromFile("./resources/Minecraft.ttf")) {
    std::cout << "Resources folder is potentially missing.\n";
    return ;
  }
  textureName = button.textureName;
  add_sprite("Button_Copy", textureName);
  position = button.position;
  size = button.size;
  text = button.text;
  boundsBottomRight = button.boundsBottomRight;
  boundsTopLeft = button.boundsTopLeft;
  fontLoaded = button.fontLoaded;
  clickable = button.clickable;
}

Button& Button::operator=(const Button& button) {
  if (this == &button)
    return *this;
  if (!font.loadFromFile("./resources/Minecraft.ttf")) {
    std::cout << "Resources folder is potentially missing.\n";
    return *this;
  }
  textureName = button.textureName;
  add_sprite("Button_Copy", textureName);
  position = button.position;
  size = button.size;
  text = button.text;
  boundsBottomRight = button.boundsBottomRight;
  boundsTopLeft = button.boundsTopLeft;
  fontLoaded = button.fontLoaded;
  clickable = button.clickable;
  return *this;
}

void Button::SetText(std::string text) {
  this->text.setString(text);
}

void Button::SetPosition(sf::Vector2i position) {
  this->position = position;
  sf::Vector2f positionFloat = static_cast<sf::Vector2f>(position);
  get_sprite(0)->setPosition(positionFloat);
  boundsTopLeft = sf::Vector2i(position.x, position.y);
  boundsBottomRight = sf::Vector2i(position.x + size.x, position.y + size.y);
  text.setPosition(positionFloat + textOffset);
}

bool Button::HoverOn(sf::Vector2i mouse) {
  if (clickable == false)
    return false;
  if (mouse.x < boundsTopLeft.x || mouse.x > boundsBottomRight.x)
    return false;
  if (mouse.y < boundsTopLeft.y || mouse.y > boundsBottomRight.y)
    return false;
  return true;
}
void Button::SetSize(sf::Vector2f scale) {
  get_sprite(0)->setScale(scale);
  size = sf::Vector2f(size.x * scale.x, size.y * scale.y);
  boundsTopLeft = sf::Vector2i(position.x, position.y);
  boundsBottomRight = sf::Vector2i(position.x + size.x, position.y + size.y);
}

void Button::EnableButton() {
  clickable = true;
  get_sprite(0)->setColor(sf::Color::White);
  text.setFillColor(sf::Color::White);
}

void Button::DisableButton() {
  clickable = false;
  get_sprite(0)->setColor(sf::Color(100, 100, 100, 200));
  text.setFillColor(sf::Color(100, 100, 100, 200));
}

bool Button::ClickedOn(sf::Vector2i mouse) {
  if (clickable == false)
    return false;
  if (mouse.x < boundsTopLeft.x || mouse.x > boundsBottomRight.x)
    return false;
  if (mouse.y < boundsTopLeft.y || mouse.y > boundsBottomRight.y)
    return false;
  return true;
}

void Button::Draw(sf::RenderWindow *window) {
  if (HoverOn(sf::Mouse::getPosition(*window))) {
    text.setOutlineThickness(4);
  } else {
    text.setOutlineThickness(0);
  }
  window->draw(*get_sprite(0));
  window->draw(text);
}
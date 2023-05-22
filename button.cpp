#include "button.hpp"

Button::Button(std::string buttonTexture) {
  if (!font.loadFromFile("./resources/Minecraft.ttf")) {
    std::cout << "Resources folder is potentially missing.";
    return ;
  }
  add_sprite("button", buttonTexture);
  size = sf::Vector2i(50, 20);
  boundsBottomLeft = sf::Vector2i(0, 0);
  boundsTopLeft = sf::Vector2i(0, size.y);
  boundsBottomRight = sf::Vector2i(size.x, 0);
  boundsTopRight = sf::Vector2i(size.x, size.y);
  fontLoaded = true;
  text.setFont(font);
  text.setCharacterSize(24);
  textPosition = static_cast<sf::Vector2f>(position + sf::Vector2i(4, 8));
  text.setPosition(textPosition);
}

void Button::SetText(std::string text) {
  this->text.setString(text);
}

void Button::SetPosition(sf::Vector2i position) {
  sf::Vector2f positionFloat = static_cast<sf::Vector2f>(position);
  get_sprite(0)->setPosition(positionFloat);
  boundsBottomLeft = sf::Vector2i(position.x, position.y);
  boundsTopLeft = sf::Vector2i(position.x, position.y + size.y);
  boundsBottomRight = sf::Vector2i(position.x + size.x, position.y);
  boundsTopRight = sf::Vector2i(position.x + size.x, position.y + size.y);
  textPosition = static_cast<sf::Vector2f>(position + sf::Vector2i(8, 4));
  text.setPosition(textPosition);
}

bool Button::HoverOn(sf::Vector2i mouse) {
  if (clickable == false)
    return false;
  if (mouse.x < position.x || mouse.x > (position.x + size.x))
    return false;
  if (mouse.y < position.y || mouse.y > (position.y + size.y))
    return false;
  return true;
}
void Button::SetSize(sf::Vector2f scale) {
  get_sprite(0)->setScale(scale);
}

void Button::EnableButton() {
  get_sprite(0)->setColor(sf::Color::White);
}

void Button::DisableButton() {
  clickable = false;
  get_sprite(0)->setColor(sf::Color(100, 100, 100, 100));
}

bool Button::ClickedOn(sf::Vector2i mouse) {
  if (clickable == false)
    return false;
  if (mouse.x < position.x || mouse.x > (position.x + size.x))
    return false;
  if (mouse.y < position.y || mouse.y > (position.y + size.y))
    return false;
  return true;
}

void Button::Draw(sf::RenderWindow *window) {
  if (HoverOn(sf::Mouse::getPosition(*window))) {
    text.setOutlineThickness(4);
  } else {
    text.setOutlineThickness(0);
  }
  window->draw(text);
  window->draw(*get_sprite(0));
}
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "../button.hpp"

int main(void) {
  Button button = Button();
  button.SetText("HELLO");
  sf::RenderWindow window(
    sf::VideoMode(800, 600), 
    "Button Test", 
    sf::Style::Close);
  while (true) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        return 0;
      }
      window.clear(sf::Color::Blue);
      button.Draw(&window);
      window.display();
    }
  }
}
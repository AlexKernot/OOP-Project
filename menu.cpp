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
/*        This is the main menu class that displays the menu with               */
/*         the corresponding choices to start and play the game                 */
/* source code for UI taken from: https://github.com/terroo/menu-sfml/tree/main */
/*                                                                              */
/*****************************************************************************/

#include "menu.hpp"

Menu::Menu(){
  font = new sf::Font();
  font->loadFromFile("./resources/Minecraft.ttf");
  add_sprite("background", "./resources/TitleScreen2.png");
  options = {"Normal Mode", "Mayhem Mode", "Broken Cup", "Quit"};

  texts.resize(4);
  coords = {{320,260},{320,340},{320,422},{350,500}};
  sizes = {24, 24, 24 ,24};

  int size = static_cast<int>(texts.size());
  for (int i = 0; i < size; ++i) {
   texts[i].setFont(*font); 
   texts[i].setString(options[i]); 
   texts[i].setCharacterSize(sizes[i]);
   texts[i].setOutlineColor(sf::Color::Black);
   texts[i].setPosition(coords[i]);
  }
  texts[0].setOutlineThickness(4);
}

Menu::~Menu() {
  delete font;
}
int Menu::HandleKeyboard() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
    if (pos < 3) {
      ++pos;
      pressed = true;
      texts[pos].setOutlineThickness(4);
      texts[pos - 1].setOutlineThickness(0);
      pressed = false;
    }
    return 0;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
    if (pos >= 0) {
      --pos;
      pressed = true;
      texts[pos].setOutlineThickness(4);
      texts[pos + 1].setOutlineThickness(0);
      pressed = false;
    }
    return 0;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    /*  Close        */
    if (pos == 3)
      return (-1);
    /*  Normal Mode  */
    if (pos == 0)
      return (1);
    /*  Mayhem Mode  */
    if (pos == 1)
      return (2);
    /*  Broken Cup   */
    if (pos == 2)
      return (3);
  }
  /*  Nothing has happened  */
  return 0;
}

void Menu::Draw(sf::RenderWindow* window) {
  window->draw(*get_sprite(0));
  int size = static_cast<int>(texts.size());
  for(int i = 0; i < size; ++i) {
   window->draw(texts[i]); 
  }
}
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

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "window.hpp"

class Menu {
  private:
    int pos;
    bool pressed, theselect;

    sf::RectangleShape * winclose;
    sf::Font * font;
    sf::Texture * image;
    sf::Sprite * bg;

    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;

    std::vector<const char *> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

  public:
    Menu(sf::RenderWindow* window);
    ~Menu();
    void run_menu(sf::RenderWindow* window);
    void Draw(sf::RenderWindow *window);
    void set_values(sf::RenderWindow* window);
    int loop_events(sf::RenderWindow* window);
    void Draw();

};

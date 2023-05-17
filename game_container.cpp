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
/*        This class is responsible for containing the game iself:           */
/*    main menu, sprites etc. will be called and displayed by this class     */
/*                                                                           */
/*****************************************************************************/

#include "game_container.hpp"
#include "renderable.hpp"
#include <iostream>

/*class TestClass : public Renderable {
public:
  TestClass() {
    Renderable::add_sprite("test", "noFile.png");
  }
  void Draw(sf::RenderWindow *window) {
    window->draw(*Renderable::get_sprite(0));
  }
};*/

void Game_container::ButtonPress(sf::Event event)
{
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        std::cout << "Left\n";
        // Button logic here
    }
    if (event.mouseButton.button == sf::Mouse::Right)
    {
        std::cout << "Right\n";
    }

}

//void Game_container::draw();
void Game_container::StartGame(){
/*  TestClass testClass = TestClass();
  Window::AddToWindow(&testClass);*/
  while (true) {
    sf::Event event;
    while (Window::PollEvent(&event)) {
      if (event.type == sf::Event::Closed)
      {
        std::cout << "Close\n";
        return ;
      }
    if (event.type == sf::Event::MouseButtonPressed) {
      ButtonPress(event);
    }
  }
  Window::RenderWindow();
}
}
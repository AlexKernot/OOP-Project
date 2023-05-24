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

void Game_container::AddGameSprites() {
  if (!font.loadFromFile("./resources/Minecraft.ttf")) {
    std::cout << "Font could not be loaded." << std::endl;
  }
  hpText1.setFont(font);
  hpText2.setFont(font);
  hpText1.setString("0");
  hpText2.setString("0");
  hpText1.setCharacterSize(14);
  hpText2.setCharacterSize(14);
  hpText1.setPosition(100, 100);
  hpText2.setPosition(200, 200);
  add_sprite("Battleui", "./resources/bg_battle.png");
  set_size(0, sf::Vector2f(0.75f, 0.75f));
  set_position(0, sf::Vector2i(200, 0));
  add_sprite("player 2_HP", "./resources/health bar.jpg");
  set_size(1, sf::Vector2f(0.20f, 0.20f));
  set_position(1, sf::Vector2i(680, 0));
  add_sprite("player 1_HP", "./resources/health bar.jpg");
  set_size(2, sf::Vector2f(0.20f, 0.20f));
  set_position(2, sf::Vector2i(300, 380));
  AddToWindow(this);
}

void Game_container::Draw(sf::RenderWindow *window) {
  window->draw(*get_sprite(0));
  window->draw(*get_sprite(1));
  window->draw(*get_sprite(2));
  window->draw(hpText1);
  window->draw(hpText2);
}

void Game_container::UpdateHealth(int player, int health) {
  if (player == 1) {
    hpText1.setString(std::to_string(health));
    return;
  }
  hpText2.setString(std::to_string(health));
}

int Game_container::MainMenu() {
  Menu menu = Menu();
  AddToWindow(&menu);
  sf::Event event;
  while (true) {
    while (PollEvent(&event)) {
      if (event.type == sf::Event::Closed)
        return -1;
      if(event.type == sf::Event::KeyPressed)
      {
        int result = menu.HandleKeyboard();
        if (result != 0)
          return result;
      }
    }
    RenderWindow();
  }
}

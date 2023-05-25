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

#include <iostream>

#include "game_container.hpp"
#include "renderable.hpp"

/* Adds the game sprites to the Window */
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
  hpText1.setPosition(295, 257);
  hpText2.setPosition(720, 32);
  hpText1.setOutlineColor(sf::Color::Black);
  hpText2.setOutlineColor(sf::Color::Black);
  hpText1.setOutlineThickness(0.8);
  hpText2.setOutlineThickness(0.8);
  AddSprite("Battleui", "./resources/bg_battle.png");
  SetSize(0, sf::Vector2f(0.75f, 0.75f));
  SetPosition(0, sf::Vector2i(200, 0));
  AddSprite("player 2_HP", "./resources/health bar.jpg");
  SetSize(1, sf::Vector2f(0.20f, 0.20f));
  SetPosition(1, sf::Vector2i(675, 25));
  AddSprite("player 1_HP", "./resources/health bar.jpg");
  SetSize(2, sf::Vector2f(0.20f, 0.20f));
  SetPosition(2, sf::Vector2i(250, 250));
  AddToWindow(this);
}

/* Renders the added sprites to the Window*/
void Game_container::Draw(sf::RenderWindow *window) {
  window->draw(*GetSprite(0));
  window->draw(*GetSprite(1));
  window->draw(*GetSprite(2));
  window->draw(hpText1);
  window->draw(hpText2);
}

/* Updates the health bar every turn */
void Game_container::UpdateHealth(int player, int health) {
  if (player == 1) {
    hpText1.setString(std::to_string(health));
    return;
  }
  hpText2.setString(std::to_string(health));
}

/* Displays the Main Menu */
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

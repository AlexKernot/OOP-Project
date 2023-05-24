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

#ifndef GAME_CONTAINER_HPP
#define GAME_CONTAINER_HPP

#include <SFML/Window.hpp>

#include <string>

#include "window.hpp"
#include "menu.hpp"
#include "renderable.hpp"
#include "button.hpp"

class Game_container : public Window, public Renderable {
private:
	int hp_index;
	int background_index;
	sf::Text hpText1;
  	sf::Text hpText2;
public:
	void UpdateHealth(int player, int health);
  void ButtonPress(sf::Event event);
	void Draw(sf::RenderWindow *window);
	int MainMenu();
	void AddGameSprites();
};

#endif
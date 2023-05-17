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
#include <iostream>

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
    while (true) {
        sf::Event event;
        while (Window::PollEvent(&event)) {
            if (event.type == sf::Event::Closed)
               return ;
		    if (event.type == sf::Event::MouseButtonPressed) {
                ButtonPress(event);
            }
    	}
	}
}
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
/*        This is the main menu class that displays the menu with            */
/*         the corresponding choices to start and play the game              */
/*                                                                           */
/*****************************************************************************/

#ifndef MAIN_MENU
#define MAIN_MENU

#include <SFML/GRaphics.hpp>
#include <iostream>

class Menu {
	private:
		int position;
		bool pressed;
		bool theselect;
		sf::Sprite * bg; // (?)
		sf::RectangleShape * windowclose;
		sf::Font * font;
		sf::Texture * image;
		sf::Vector2i position_mouse
		sf::Vector2f m_coord; //mouse coordinates
		std::vector<const char *> options;
		std::vector<sf::Vector2f> coords; //coordinates
		std::vector<sf::Text> texts; //text to be displayed
		std::vector<sf::Text> texts;
		std::vecotr<std::size_t> sizes;
	public:
		Menu();
		~Menu();
		void run_menu();
		void set_values(); //set values for each obj
		void loop_events(); //events of mouseclick
		void draw_all(); //draw everything (?) not necessary
		void draw();
};

#endif
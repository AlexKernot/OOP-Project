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
/*       This is the class containing info about the window that will        */
/*                          be opened through SFML.                          */
/*                                                                           */
/*****************************************************************************/

#ifndef POKEMON_WINDOW_H
#define POKEMON_WINDOW_H

#include "SFML/Window.hpp"

#include <vector>

#include "renderable.hpp"

class Window {
private:
	const int width = 800;
	const int height = 500;
	const int fpsLimit = 10;
	std::vector<Renderable *> objects;
	sf::RenderWindow *sfWindow;

public:
	Window();
	~Window();
	int GetWindowWidth() {return width;}
	int GetWindowHeight() {return height;}
	bool PollEvent(sf::Event *event);
	void AddToWindow(Renderable *object);
	void ClearFromWindow(Renderable *object);
	void ClearEntireWindow();
	void RenderWindow();
};

#endif
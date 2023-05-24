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
	  int width = 800;
	  int height = 600;
	  int fpsLimit = 10;
	std::vector<Renderable *> objects;
	sf::RenderWindow *sfWindow;

public:
	Window();
	virtual ~Window();
	int GetWindowWidth() {return width;}
	int GetWindowHeight() {return height;}
	sf::RenderWindow *GetWindow() {return sfWindow;}
	bool PollEvent(sf::Event *event);
	void AddToWindow(Renderable *object);
	void ClearFromWindow(Renderable *object);
	void ClearEntireWindow();
	void RenderWindow();
};

#endif
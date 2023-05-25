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
/* Creates a new renderable window to display the UI of the game    */
	Window();
/* Closes the renderable Window                                     */
	virtual ~Window();
/* Returns the width of the open window                             */
	int GetWindowWidth() {return width;}
/* Returns the height of the open window                            */
	int GetWindowHeight() {return height;}
	sf::RenderWindow *GetWindow() {return sfWindow;}
/* Polls event from the renderable window                           */
	bool PollEvent(sf::Event *event);
/* This adds all the renderable objects into the objects            */
/* vector to be able to display all sprites for the draw function   */
	void AddToWindow(Renderable *object);
/* Removes a specific renderable object passed as a pointer to      */
/* remove from the Window vector                                    */
	void ClearFromWindow(Renderable *object);
/* Clears all renderable objects from the Window vector             */
	void ClearEntireWindow();
/* Renders the window by drawing all the renderable objects in the  */
/* Window vector                                                    */
	void RenderWindow();
};

#endif
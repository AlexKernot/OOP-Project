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

#include "window.hpp"

#include <SFML/Window.hpp>

/* Creates a new renderable window to display the UI of the game */
Window::Window() {
  sfWindow = new sf::RenderWindow(
    sf::VideoMode(static_cast<unsigned int>(width), 
    static_cast<unsigned int>(height)), 
    "Pokemon Showdown", 
    sf::Style::Close);
}

/* Closes the renderable Window */
Window::~Window() {
  sfWindow->close();
  delete sfWindow;
}

/* This adds all the renderable objects into the objects           */
/* vector to be able to display all sprites for the draw function  */
void Window::AddToWindow(Renderable *object) {
  objects.push_back(object);
}

/* Polls event from the renderable window */
bool Window::PollEvent(sf::Event *event)
{
  bool eventsPending;
  eventsPending = sfWindow->pollEvent(*event);
  return eventsPending;
}

/* Removes a specific renderable object passed as a pointer to remove from the Window vector */
void Window::ClearFromWindow(Renderable *object) {
  int size = static_cast<int>(objects.size());
  for (int i = 0; i < size; ++i) {
    if (objects[i] == object) {
      objects.erase(objects.begin() + i);
      return;
    }
  }
  return;
}

/* Clears all renderable objects from the Window vector */
void Window::ClearEntireWindow() {
  objects.clear();
}

/* Renders the window by drawing all the renderable objects in the Window vector */
void Window::RenderWindow() {
  sfWindow->clear();
  int size = static_cast<int>(objects.size());
  for (int i = 0; i < size; ++i)
    if (objects[i] != nullptr)
      objects[i]->Draw(sfWindow);
  sfWindow->display();
}
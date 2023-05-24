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

/*Creates a new renderable window to display the UI of the game*/
Window::Window() {
  sfWindow = new sf::RenderWindow(
    sf::VideoMode(static_cast<unsigned int>(width), 
    static_cast<unsigned int>(height)), 
    "Pokemon Showdown", 
    sf::Style::Close);
}

/*Closes the renderable Window*/
Window::~Window() {
  sfWindow->close();
  delete sfWindow;
}

void Window::AddToWindow(Renderable *object) {
  objects.push_back(object);
}

bool Window::PollEvent(sf::Event *event)
{
  bool eventsPending;
  eventsPending = sfWindow->pollEvent(*event);
  return eventsPending;
}

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

void Window::ClearEntireWindow() {
  objects.clear();
}

void Window::RenderWindow() {
  sfWindow->clear();
  int size = static_cast<int>(objects.size());
  for (int i = 0; i < size; ++i)
    if (objects[i] != nullptr)
      objects[i]->Draw(sfWindow);
  sfWindow->display();
}
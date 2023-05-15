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

Window::Window() {
  sfWindow = new sf::RenderWindow(
    sf::VideoMode(static_cast<unsigned int>(width), 
    static_cast<unsigned int>(height)), 
    "Pokemon Simulator", 
    sf::Style::Titlebar);
  sfWindow->setFramerateLimit(fpsLimit);
}

Window::~Window() {
  sfWindow->close();
  delete sfWindow;
}

void Window::AddToWindow(Renderable *object) {
  objects.push_back(object);
}

void Window::ClearFromWindow(Renderable *object) {
  int size = static_cast<int>(objects.size());
  for (int i = 0; i < size; ++i) {
    if (objects[i] == object) {
      delete objects[i];
      objects.erase(objects.begin() + i);
      return;
    }
  }
  return;
}

void Window::ClearEntireWindow() {
  int size = static_cast<int>(objects.size());
  for (int i = 0; i < size; ++i)
    delete objects[i];
  objects.clear();
}

void Window::RenderWindow() {
  sfWindow->clear();
  int size = static_cast<int>(objects.size());
  for (int i = 0; i < size; ++i)
    objects[i]->Draw();
  sfWindow->display();
}
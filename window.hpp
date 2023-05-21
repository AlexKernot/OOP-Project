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

#include <vector>

#include "SFML/Window.hpp"
#include "renderable.hpp"

class Window {
 protected:
  const int width = 800;
  const int height = 600;
  const int fpsLimit = 10;
  std::vector<Renderable *> objects;

 public:
  sf::RenderWindow *sfWindow;
  Window();
  ~Window();
  int GetWindowWidth() { return width; }
  int GetWindowHeight() { return height; }
  bool PollEvent(sf::Event *event);
  void AddToWindow(Renderable *object);
  void ClearFromWindow(Renderable *object);
  void ClearEntireWindow();
  void RenderWindow();
};

#endif
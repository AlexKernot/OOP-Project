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
/*        This is the base class for all objects that need rendering         */
/*      It is an abstract class that holds the sprites for each object       */
/*                                                                           */
/*****************************************************************************/

#ifndef __MOVE_H__
#define __MOVE_H__

#include <iostream>
#include "type.hpp"

using std::string;

class Move {
private:
  string name;
  int power;
  string effect;
  Type type;
  bool isStab;

public:
  Move(string name, int power, string effect, string type, bool isStab);

  void set_name(string name);
  void set_effect(string effect);
  void set_type(string type);
  void set_power(int power);

  int get_power();
  string get_name();
  string get_effect();
  Type get_type();
  bool getIsStab() { return isStab;  }
};

#endif
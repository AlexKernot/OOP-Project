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
/*        This class represents a Move in the Pokemon Showdown game.         */
/*       It stores information about the move such as its name, power,       */
/*                        accuracy, effect, and type.                        */
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
  int accuracy;
  string effect;
  Type type;
  bool isStab = false;

public:
  Move();
  Move(string name, int power, int accuracy, string effect, string type);

  void set_name(string name);
  void set_effect(string effect);
  void set_type(string type);
  void set_power(int power);
  void SetStab(bool isStab) {this->isStab = isStab;}

  int get_power();
  string get_name();
  string get_effect();
  Type get_type();
  bool getIsStab() { return isStab;  }
};

#endif
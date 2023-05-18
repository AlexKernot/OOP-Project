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

#include "move.hpp"

Move::Move(string name, int power, string effect, string type, bool isStab)
    : name(name), effect(effect), type(type), power(power), isStab(isStab){}

void Move::set_name(string name) { this->name = name; }
void Move::set_effect(string effect) { this->effect = effect; }
void Move::set_type(string type) { this->type = Type(type); }
void Move::set_power(int power) {  this->power = power;  }

int Move::get_power() {  return power;  }
string Move::get_name() { return name; }
string Move::get_effect() { return effect; }
Type Move::get_type() { return type; }
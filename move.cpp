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

#include <iostream>

using namespace std;

Move::Move(string name, string effect, string type_one, string type_two)
    : name(name), effect(effect), type_one(type_one), type_two(type_two){};

void Move::set_name(string name) { this->name = name; };
void Move::set_effect(string effect) { this->effect = effect; };
void Move::set_type_one(string type_one) { this->type_one = type_one; };
void Move::set_type_two(string type_two) { this->type_two = type_two; };

string Move::get_name() { return name; };
string Move::get_effect() { return effect; };
string Move::get_type_one() { return type_one; };
string Move::get_type_two() { return type_two; }
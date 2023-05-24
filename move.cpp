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

#include "move.hpp"

//  ructor
Move::Move(string name, int power, int accuracy, string effect, string type)
    : name(name),
      power(power),
      accuracy(accuracy),
      effect(effect),
      type(type) {}

// Default  ructor to create a placeholder move
Move::Move() : Move("Struggle", 50, 100, "Recoil 50", "Normal") {}

// Set the name of the move
void Move::set_name(string name) { this->name = name; }

// Set the effect of the move
void Move::set_effect(string effect) { this->effect = effect; }

// Set the type of the move
void Move::set_type(string type) { this->type = Type(type); }

// Set the power of the move
void Move::set_power(int power) { this->power = power; }

// Get the power of the move
int Move::get_power() { return power; }

// Get the name of the move
string Move::get_name() { return name; }

// Get the effect of the move
string Move::get_effect() { return effect; }

// Get the type of the move
Type Move::get_type() { return type; }

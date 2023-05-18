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
/*        This is the Pokemon class responsible for the creation of          */
/*      Pokemon, their respective stats, and stat changes in battle          */
/*                                                                           */
/*****************************************************************************/

#ifndef POKEMON_H
#define POKEMON_H

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

#include <string>
#include <vector>

#include "move.hpp"
#include "type.hpp"

using std::string;
using std::time;
using std::rand;
using std::cout;
using std::vector;

class Pokemon
{
	public:
		typedef struct
    	{
			int attack;
			int defense;
			int special_attack;
			int special_defense;
			int speed;
    	} stats;
	private: 
		string name;
		Type type_one;
		Type type_two;
		int max_hp;
		int current_hp;
		int crit;
		int randomNumber;
		int division;
		int total_damage;
		int crit_stats;
		int stab;
		stats base_stats;
		stats mod_stats;
		vector<string>moveList;
	public:
		Pokemon(string name, Type type_one, Type type_two, int maximum_hp, stats stats, vector<Move> moves);
		void take_damage(int pwr);
		void modify_stats(stats);
		void receive_move(Move moves);
		void set_name(string name);
		void set_type_one(Type type);
		void set_type_two(Type type);
		string get_name();
		Type get_type_one();
		Type get_type_two();
		vector<string> get_moves();
};

#endif
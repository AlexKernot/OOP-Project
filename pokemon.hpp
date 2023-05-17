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

#include "move.h"

using std::string;
using std::time;
using std::rand;
using std::cout;

class Pokemon
{
	private: 
		string name;
		string type;
		int max_hp;
		int current_hp;
		int crit;
		int randomNumber;
		int division;
		int total_damage;
		int crit_stats;
		int stab;
		vector<string>moveList;
		struct Stats
    	{
			int attack;
			int defense;
			int special_attack;
			int special_defense;
			int speed;
    	} base_stats, mod_stats;
	public:
		virtual Pokemon();
		void take_damage(int pwr);
		void modify_stats(struct stats);
		void receive_move(Move moves);
		void set_name(string name);
		void set_type(string type);
		string get_name();
		string get_type();
		string get_moves();
};

#endif
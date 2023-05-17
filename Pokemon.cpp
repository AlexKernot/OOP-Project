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

#include "pokemon.hpp"

/* constructor for the Stats class to intialize values for stat variables */
Pokemon::Stats::Stats(int atk, int def, int specatk, int specdef, int spd)
{
	attack = atk;
	defense = def;
	special_attack = specatk;
	specdef = specdef;
	speed = spd;
}

/* virtual constructor for creating Pokemon that gives it stats and 4 moves each */
virtual Pokemon::Pokemon(Stats stats, Move moves, int maximum_hp)
{
	base_stats = stats;
	mod_stats = stats; //own note: for modify stats;
	max_hp = maximum_hp;
	current_hp = maximum_hp;
}

int typeChecker(Move moves, string pkm_type)
{
	if(moves.get_type == "Fire")
	{
		if(pkm_type() == "Grass" || pkm_type == "Bug")
		{ 
			//include all types fire is effective against
			return 1.5   
		}
		else if(pkm_type == "Water" || pkm_type == "Rock")
		{ 
		//include all types fire is weak against
		return 0.5   
		} 
		else 
			return 1;
  } //and so on for all types :>
}

/*reduces the hp of the Pokemon by the damage passed in the parameter */
void Pokemon::take_damage(int pwr)
{
	if(current_hp > 0) {
		current_hp -= pwr;
		if (current_hp < 0) {
			current_hp = 0;
		}
	}
}

/*modifies the stat when stat modifying moves are used or taken*/
void modify_stats(struct stats)
{

}

/* this function receives the moves and performs calculations to return the total hp for a Pokemon to lose and stats modifications*/
void Pokemon::receive_move(Move moves)
{
	srand(static_cast<unsigned>(time(nullptr)));
	randomNumber = rand() % 10;
	if (randomNumber == 9)
		randomNumber = 2;
	else 
		randomNumber = 1;
	if (moves.get_effect = " Physical Attack") {
		if ((mod_stats.attack || mod_stats.defense) > 255) {
			mod_stats.attack /= 4;
			floor(mod_stats.attack);
			mod_stats.defense /= 4;
			floor(mod_stats.defense);
			// < 0 checker (???)
		}
		if (moves.get_name == "Explosion" || moves.get_name == "Selfdestruct") {
			mod_stats.defense /= 2;
			floor(mod_stats.defense);
		}
		if (crit == 2) {
			division = base_stats.attack / base_stats.defense;
			floor(division);
		}
		else {
			division = mod_stats.attack / mod_stats.defense;
			floor(division);
		}
		total_damage = ((((((crit * 2) / 5) + 2) * move.get_power) * division) / 50)
		floor(total_damage);
		if (total_damage > 997)
		total_damage = 997;
		total_damage += 2;
		if (type == moves.get_type) {
			stab =  total_damage / 2;
			floor(stab);
			total_damage += stab;
		}
		//type 1 type 2 calculation (idk how to do that) ->type checker?
		if (total_damage == 0)
		{
			cout << "Move missed." << endl;
		}
		if (total_damage == 1)
			take_damage(total_damage);
		randomNumber = 217 + (rand() % (39));
		total_damage = ((total_damage * randomNumber) / 255)
		floor(total_damage);
		take_damage(total_damage);
	}
	else if (moves.get_effect = " Special Attack") {
		if ((mod_stats.special_attack || mod_stats.special_defense) > 255) {
			mod_stats.special_attack /= 4;
			floor(mod_stats.special_attack);
			mod_stats.special_defense /= 4;
			floor(mod_stats.special_defense);
			// < 0 checker (???)
		}
		if (crit == 2) {
			division = base_stats.special_attack / base_stats.special_defense;
			floor(division);
		}
		else {
			division = mod_stats.special_attack / mod_stats.special_defense;
			floor(division);
		}
		total_damage = ((((((crit * 2) / 5) + 2) * move.get_power) * division) / 50)
		floor(total_damage);
		if (total_damage > 997)
		total_damage = 997;
		total_damage += 2;
		if (type == moves.get_type) {
			stab =  total_damage / 2;
			floor(stab);
			total_damage += stab;
		}
		//type 1 type 2 calculation (idk how to do that) ->type checker?
		if (total_damage == 0)
		{
			cout << "Move missed." << endl;
		}
		if (total_damage == 1)
			take_damage(total_damage);
		randomNumber = 217 + (rand() % (39));
		total_damage = ((total_damage * randomNumber) / 255)
		floor(total_damage);
		take_damage(total_damage);
	}
}

/* sets the name of the Pokemon */
void set_name(string name)
{
	this->name = name;
}

/* sets the type of the Pokemon */
void set_type(string type)
{
	this->type = type;
}

/* returns the name of the Pokemon */
string get_name()
{
	return name;
}

/* returns the type of the Pokemon */
string get_type()
{
	return type;
}

/* returns all the moves of the Pokemon*/
string Pokemon::get_moves()
{
	for (int i = 0; i < 4; i++) {
            moveList += moves[i].get_name();
    }
        return moveList;
}
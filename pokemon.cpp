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

/* virtual constructor for creating Pokemon that gives it stats and 4 moves each */
Pokemon::Pokemon(string name, Type type_one, Type type_two, int maximum_hp, stats stats, vector<Move> moves)
				: name(name), type_one(type_one), type_two(type_two), max_hp(maximum_hp), base_stats(stats) {
	this->type_one = type_one;
	
	base_stats = stats;
	mod_stats = stats; //own note: for modify stats;
	max_hp = maximum_hp;
	current_hp = maximum_hp;
}

/*reduces the hp of the Pokemon by the damage passed in the parameter */
void Pokemon::take_damage(int pwr) {
	if(current_hp > 0) {
		current_hp -= pwr;
		if (current_hp < 0) {
			current_hp = 0;
		}
	}
}

/*modifies the stat when stat modifying moves are used or taken*/
void modify_stats(Pokemon::stats newStats) {

}

/* this function receives the moves and performs calculations to return the total hp for a Pokemon to lose and stats modifications*/
void Pokemon::receive_move(Move moves) {
	srand(static_cast<unsigned>(time(nullptr)));
	randomNumber = rand() % 10;
	if (randomNumber == 9)
		randomNumber = 2;
	else 
		randomNumber = 1;
	if (moves.get_effect() == " Physical Attack") {
		if ((mod_stats.attack || mod_stats.defense) > 255) {
			mod_stats.attack /= 4;
			division = floor(mod_stats.attack);
			mod_stats.defense /= 4;
			division = floor(mod_stats.defense);
			if(mod_stats.attack <= 0) {
				mod_stats.attack = 1;
			}
			if(mod_stats.defense <= 0) {
				mod_stats.defense = 1;
			}
		}
		if (moves.get_name() == "Explosion" || moves.get_name() == "Selfdestruct") {
			mod_stats.defense /= 2;
			division = floor(mod_stats.defense);
		}
		if (crit == 2) {
			division = base_stats.attack / base_stats.defense;
			division = floor(division);
		}
		else {
			division = mod_stats.attack / mod_stats.defense;
			division = floor(division);
		}
		if (division <= 0) {
			division = 1;
		}
		total_damage = ((((((crit * 2) / 5) + 2) * moves.get_power()) * division) / 50);
		total_damage = floor(total_damage);
		if (total_damage > 997)
		total_damage = 997;
		total_damage += 2;
		if (moves.getIsStab()) {
			stab =  total_damage / 2;
			stab = floor(stab);
			total_damage += stab;
		}
		//type 1 type 2 calculation (idk how to do that) ->type checker?
		//non effect type 
		if (total_damage <= 0) {
			cout << "Move missed." << std::endl; //note that this might have to be displayed on the battle log somehow
			return ;
		}
		if (total_damage == 1)
		{
			take_damage(total_damage);
			return ;
		}
		randomNumber = 217 + (rand() % (39));
		total_damage = ((total_damage * randomNumber) / 255);
		total_damage = floor(total_damage);
		take_damage(total_damage);
		return ;
	}
	else if (moves.get_effect() == " Special Attack") {
		if ((mod_stats.special_attack || mod_stats.special_defense) > 255) {
			mod_stats.special_attack /= 4;
			mod_stats.special_attack = floor(mod_stats.special_attack);
			mod_stats.special_defense /= 4;
			mod_stats.special_defense = floor(mod_stats.special_defense);
			if(mod_stats.special_attack <= 0) {
				mod_stats.special_attack = 1;
			}
			if(mod_stats.special_defense <= 0) {
				mod_stats.special_defense = 1;
			}
		}
		if (crit == 2) {
			division = base_stats.special_attack / base_stats.special_defense;
			division = floor(division);
		}
		else {
			division = mod_stats.special_attack / mod_stats.special_defense;
			division = floor(division);
		}
		if (division <= 0) {
			division = 1;
		}
		total_damage = ((((((crit * 2) / 5) + 2) * moves.get_power()) * division) / 50);
		total_damage = floor(total_damage);
		if (total_damage > 997)
		total_damage = 997;
		total_damage += 2;
		if (moves.getIsStab()) {
			stab =  total_damage / 2;
			stab = floor(stab);
			total_damage += stab;
		}
		//type 1 type 2 calculation (idk how to do that) ->type checker?
		if (total_damage == 0)
		{
			cout << "Move missed." << std::endl;
			return ;
		}
		if (total_damage == 1)
		{
			take_damage(total_damage);
			return ;
		}
		randomNumber = 217 + (rand() % (39));
		total_damage = ((total_damage * randomNumber) / 255);
		total_damage = floor(total_damage);
		take_damage(total_damage);
		return ;
	}
}

/* sets the name of the Pokemon */
void Pokemon::set_name(string name) {
	this->name = name;
}

/* sets the type of the Pokemon */
void Pokemon::set_type_one(Type type) {
	this->type_one = type;
}

void Pokemon::set_type_two(Type type) {
	this->type_two = type;
}
/* returns the name of the Pokemon */
string Pokemon::get_name() {
	return name;
}

/* returns the type of the Pokemon */
Type Pokemon::get_type_one() {
	return type_one;
}

Type Pokemon::get_type_two() {
	return type_two;
}

/* returns all the moves of the Pokemon*/
vector<string> Pokemon::get_moves() {
    return moveList;
}

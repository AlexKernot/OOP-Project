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
	mod_stats = stats;
	current_stats = stats;
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
void modify_stats(Pokemon::stats newStats, int n_stage, string stage_effect) {
	float multiplier = 1.00f;
	maxstage = 6;
	static const map<int, float> stage = { //static to avoid recreating everytime its called...idk if that is actually good here uh help?
    {-6, 0.25f}, {-5, 0.28f}, {-4, 0.33f}, {-3, 0.40f},
    {-2, 0.50f}, {-1, 0.66f}, {0, 1.00f}, {1, 1.50f},
    {2, 2.00f}, {3, 2.50f}, {4, 3.00f}, {5, 3.50f},
    {6, 4.00f}};
	multiplier = stage[n_stage];
	static const map<string, Pokemon::stats::current_stats*> effectMap = {
        {"Attack", &current_stats.attack},
        {"Defense", &current_stats.defense},
        {"Special attack", &current_stats.special_attack},
        {"Special Defense", &current_stats.special_defense},
        {"Speed", &current_stats.speed} //this doesnt work yet but u get the idea
    };
}

/* this function receives the moves and sends the power to the dmg calculator based on the moves effect*/
void Pokemon::receive_move(Move moves) {
	mod_stats = current_stats;
	if (moves.get_effect() == "Physical Attack")
		attack_damage(moves.get_power());
	else if (moves.get_effect() == " Special Attack")
		special_attack_damage(moves.get_power());
	//stat modifying moves go here
}

/* Dmg calculator for attack moves based on generation 1 calculation*/
void Pokemon::attack_damage(int pwr) {
	srand(static_cast<unsigned>(time(nullptr)));
	randomNumber = rand() % 10;
	if (randomNumber == 9)
		crit = 2;
	else 
		crit = 1;
	if ((mod_stats.attack || mod_stats.defense) > 255) {
			mod_stats.attack /= 4;
			mod_stats.defense /= 4;
			if(mod_stats.attack <= 0) {
				mod_stats.attack = 1;
			}
			if(mod_stats.defense <= 0) {
				mod_stats.defense = 1;
			}
		}
		if (moves.get_name() == "Explosion" || moves.get_name() == "Selfdestruct") {
			mod_stats.defense /= 2;
		}
		if (crit == 2) {
			division = base_stats.attack / base_stats.defense;
		}
		else {
			division = mod_stats.attack / mod_stats.defense;
		}
		if (division <= 0) {
			division = 1;
		}
		total_damage = ((((((crit * 2) / 5) + 2) * moves.get_power()) * division) / 50);
		if (total_damage > 997)
		total_damage = 997;
		total_damage += 2;
		if (moves.getIsStab()) {
			stab =  total_damage / 2;
			total_damage *= stab;
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
		take_damage(total_damage);
}

/* Dmg calculator for special attack moves based on generation 1 calculation*/
void Pokemon::special_attack_damage(int pwr) {
	srand(static_cast<unsigned>(time(nullptr)));
	randomNumber = rand() % 10;
	if (randomNumber == 9)
		crit = 2;
	else 
		crit = 1;
	if ((mod_stats.special_attack || mod_stats.special_defense) > 255) {
			mod_stats.special_attack /= 4;
			mod_stats.special_defense /= 4;
			if(mod_stats.special_attack <= 0) {
				mod_stats.special_attack = 1;
			}
			if(mod_stats.special_defense <= 0) {
				mod_stats.special_defense = 1;
			}
		}
		if (crit == 2) {
			division = base_stats.special_attack / base_stats.special_defense;
		}
		else {
			division = mod_stats.special_attack / mod_stats.special_defense;
		}
		if (division <= 0) {
			division = 1;
		}
		total_damage = ((((((crit * 2) / 5) + 2) * moves.get_power()) * division) / 50);
		if (total_damage > 997)
		total_damage = 997;
		total_damage += 2;
		if (moves.getIsStab()) {
			stab =  total_damage / 2;
			total_damage *= stab;
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
		take_damage(total_damage);
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

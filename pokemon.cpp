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

Pokemon::Pokemon(const Pokemon& pokemon) {
	name = pokemon.name;
  typeOne = pokemon.typeOne;
  typeTwo = pokemon.typeTwo;
  level = pokemon.level;
  maxHp = pokemon.maxHp;
  currentHp = pokemon.currentHp;
  baseStats = pokemon.baseStats;
  stats = pokemon.stats;
  moveList = pokemon.moveList;
}

void Pokemon::operator=(const Pokemon& pokemon) {
  name = pokemon.name;
  typeOne = pokemon.typeOne;
  typeTwo = pokemon.typeTwo;
  level = pokemon.level;
  maxHp = pokemon.maxHp;
  currentHp = pokemon.currentHp;
  baseStats = pokemon.baseStats;
  stats = pokemon.stats;
  moveList = pokemon.moveList;
}

/*  Constructor for creating Pokemon that gives it stats and 4 moves each  */
Pokemon::Pokemon(string name, Type type_one, Type type_two, 
					        Stats baseStats, vector<Move> moves, int level) {
  this->name = name;
  this->typeOne = type_one;
  this->typeTwo = type_two;
  this->baseStats = baseStats;
  this->level = level;
  moveList = moves;
  baseStats.GenerateStats(level /* IVs, EVs*/);
  maxHp = baseStats.GetHP();
	stats = baseStats;
	currentHp = maxHp;
}

/*reduces the hp of the Pokemon by the damage passed in the parameter */
void Pokemon::take_damage(int pwr) {
	if(currentHp > 0) {
		currentHp -= pwr;
		if (currentHp < 0) {
			currentHp = 0;
		}
	}
}

/* this function receives the moves and sends the power to the dmg calculator based on the moves effect*/
void Pokemon::receive_move(Move move, int level, int atk, int baseAtk) {
		attack_damage(move, level, atk, baseAtk);
	//stat modifying moves go here
}

/* Dmg calculator for attack moves based on generation 1 calculation*/
void Pokemon::attack_damage(Move move, int level, int atk, int baseAtk) {
	srand(static_cast<unsigned>(time(nullptr)));
	int randomNumber = rand() % 10;
  int crit = 1;
  int atkOrBaseAtk = atk;
  int defOrBaseDef = stats.GetDefense();
  if (move.get_effect() == "special")
    defOrBaseDef = stats.GetSpecialDefense();
	if (randomNumber == 9)
  {
    defOrBaseDef = baseStats.GetDefense();
    if (move.get_effect() == "special")
      defOrBaseDef = baseStats.GetSpecialDefense();
    atkOrBaseAtk = baseAtk;
		crit = 2;
  }
	if (defOrBaseDef > 255 || atkOrBaseAtk > 255) {
			defOrBaseDef /= 4;
			atkOrBaseAtk /= 4;
			if(atkOrBaseAtk <= 0)
				atkOrBaseAtk = 1;
			if(defOrBaseDef <= 0)
				defOrBaseDef = 1;
		}
		if (move.get_name() == "Explosion" || move.get_name() == "Selfdestruct")
			defOrBaseDef /= 2;
    int division = atkOrBaseAtk / defOrBaseDef;
		if (division <= 0) {
			division = 1;
		}
    int damage = ((level * crit * 2 / 5) + 2) * move.get_power();
    damage = damage * atkOrBaseAtk / defOrBaseDef / 50;
		if (damage > 997)
		  damage = 997;
		damage += 2;
		if (move.getIsStab()) {
			damage *= damage / 2;
		}
    damage *= move.get_type().GenerateTypeEffectiveness(typeOne, typeTwo);
		if (damage <= 0) {
			cout << "Move missed." << std::endl;
			return ;
		}
		if (damage == 1) {
			take_damage(damage);
			return ;
		}
		randomNumber = 217 + (rand() % (39));
		damage = ((damage * randomNumber) / 255);
		take_damage(damage);
}

/* sets the name of the Pokemon */
void Pokemon::set_name(string name) {
	this->name = name;
}

/* sets the type of the Pokemon */
void Pokemon::set_type_one(Type type) {
	this->typeOne = type;
}

void Pokemon::set_type_two(Type type) {
	this->typeTwo = type;
}
/* returns the name of the Pokemon */
string Pokemon::get_name() {
	return name;
}

/* returns the type of the Pokemon */
Type Pokemon::get_type_one() {
	return typeOne;
}

Type Pokemon::get_type_two() {
	return typeTwo;
}

/* returns all the moves of the Pokemon*/
vector<Move> Pokemon::get_moves() {
    return moveList;
}

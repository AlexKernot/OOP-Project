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

Pokemon::Pokemon() {
  name = "Missingno";
  typeOne = Type("Normal");
  typeTwo = Type("NULL");
  baseStats = Stats(1, 1, 1, 1, 1, 1);
  level = 1;
  baseStats.GenerateStats(level);
  maxHp = baseStats.GetHP();
  currentHp = maxHp;
  moveList = vector<Move> {Move(), Move(), Move(), Move()};
}

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

Pokemon& Pokemon::operator=(const Pokemon& pokemon) {
  if (this == &pokemon)
    return *this;
  name = pokemon.name;
  typeOne = pokemon.typeOne;
  typeTwo = pokemon.typeTwo;
  level = pokemon.level;
  maxHp = pokemon.maxHp;
  currentHp = pokemon.currentHp;
  baseStats = pokemon.baseStats;
  stats = pokemon.stats;
  moveList = pokemon.moveList;

  return *this;
}

/*   ructor for creating Pokemon that gives it stats and 4 moves each  */
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

/*  Pretty prints pokemon info to terminal for debugging.             */
void Pokemon::PrettyPrint() {
  std::cout << "Name: " << name << std::endl
  << "Type one: " << typeOne.GetType() << std::endl
  << "Type two: " << typeTwo.GetType() << std::endl
  << "Level:    " << level << std::endl
  << "Max HP:   " << maxHp << std::endl
  << "Current HP: " << currentHp << std::endl
  << "Stats: " << std::endl
  << "  HP: " << stats.GetHP() << std::endl
  << "  Attack: " << stats.GetAttack() << std::endl
  << "  Special Atk: " << stats.GetSpecialAttack() << std::endl
  << "  Defense: " << stats.GetDefense() << std::endl
  << "  Special Defense: " << stats.GetSpecialDefense() << std::endl
  << "  Speed: " << stats.GetSpeed() << std::endl
  << "Moves: " << std::endl ;
  int size = static_cast<int>(moveList.size());
  for (int i = 0; i < size; ++i)
  {
    std::cout << "  - " << moveList[i].get_name() << std::endl;
  }
}

/*reduces the hp of the Pokemon by the damage passed in the parameter */
void Pokemon::TakeDamage(int pwr) {
	if(currentHp > 0) {
		currentHp -= pwr;
		if (currentHp < 0 || currentHp == 0) {
			currentHp = 0;
      isFainted = true;
		}
	}
}

/* this function receives the moves and sends the power to the dmg calculator based on the moves effect*/
void Pokemon::ReceiveMove(Move move, int level, int atk, int baseAtk) {
		AttackDamage(move, level, atk, baseAtk);
	//stat modifying moves go here
}

/* Dmg calculator for attack moves based on generation 1 calculation*/
void Pokemon::AttackDamage(Move move, int level, int atk, int baseAtk) {
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
			TakeDamage(damage);
			return ;
		}
		randomNumber = 217 + (rand() % (39));
		damage = ((damage * randomNumber) / 255);
		TakeDamage(damage);
}

/* sets the name of the Pokemon */
void Pokemon::SetName(string name) {
	this->name = name;
}

/* sets the type of the Pokemon */
void Pokemon::SetTypeOne(Type type) {
	this->typeOne = type;
}

void Pokemon::SetTypeTwo(Type type) {
	this->typeTwo = type;
}
/* returns the name of the Pokemon */
string Pokemon::GetName() {
	return name;
}

/* returns the type of the Pokemon */
Type Pokemon::GetTypeOne() {
	return typeOne;
}

Type Pokemon::GetTypeTwo() {
	return typeTwo;
}
void Pokemon::SetMoves(vector<Move*> moves) {
  int size = static_cast<int>(moves.size());
  for (int i = 0; i < size; ++i) {
    moveList[i] = *moves[i];
  }
}

/* returns all the moves of the Pokemon*/
vector<Move*> Pokemon::GetMoves() {
  vector<Move*> moves;
  int size = static_cast<int>(moveList.size());
  for (int i = 0; i < size; ++i)
  {
    moves.push_back(&moveList[i]);
  }
    return moves;
}

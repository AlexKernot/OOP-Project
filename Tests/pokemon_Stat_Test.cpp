#include "../pokemon.hpp"
#include "../move.hpp"
#include "../type.hpp"
#include "../stats.hpp"

#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class PokemonStatMoveTest {
public:
	void runTests() {
		PokemontestDefault();
		PokemontestSetName();
		PokemontestSetEmptyName();
		PokemontestSetLongString();
		//testSetNull();
		PokemontestTypes();
		PokemontestReceiveMove();
		Pokemon_Stat_Copy();
		Stat_testGen();
		Stat_valid();
		Stat_modifyHP();
		invalidStages();
		GetMove();
	}

private:
	void PokemontestDefault() {
		Pokemon pokemon;
		cout << pokemon.get_name() << endl;
        vector<Move*> moves = pokemon.get_moves();
        for (const auto& move : moves) {
            cout << move->get_name() << endl;
        }
	}

	void PokemontestSetName() {
		Pokemon pokemon;
		pokemon.set_name("Alex");
		cout << pokemon.get_name()  << endl;
	}

	// void testSetNull() {
	// 	Pokemon pokemon;
	// 	pokemon.set_name();
	// 	cout << pokemon.get_name()  << endl; //terminates
	// }

	void PokemontestSetEmptyName() {
		Pokemon pokemon;
		pokemon.set_name("");
		pokemon.PrettyPrint();
	}

	void PokemontestSetLongString() {
		Pokemon pokemon;
		pokemon.set_name("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj");
		pokemon.PrettyPrint();
	}

	void PokemontestTypes() {
		Pokemon pokemon;
		Type t1("Fire");
    	Type t2("Flying");
		pokemon.set_type_one(t1);
		pokemon.set_type_two(t2);
		pokemon.PrettyPrint();
	}
	
	void PokemontestReceiveMove() {
		Stats baseStats(45, 70, 80, 20, 40, 58);
		Type t1("Fire");
   		Type t2("Rock");
		Move m1("Flamethrower", 90, 100, "special", "Fire");
        Move m2("Thunderbolt", 90, 100, "special", "Electric");
		
		vector<Move> moves = {m1, m2};
		Pokemon pokemon("Charmander", t1, t2, baseStats, moves, 50);
		pokemon.PrettyPrint();
		pokemon.receive_move(m1, 50, 100, baseStats.GetSpecialAttack());
		pokemon.PrettyPrint();
}
	void Pokemon_Stat_Copy() {
		Type t1("Fire");
   		Type t2("Rock");
		Stats b1(45, 66, 90, 90, 80, 48);
		Stats b2(50, 66, 90, 90, 80, 50);
		b2 = b1;
		Move m1("Flamethrower", 90, 100, "special", "Fire");
        Move m2("Thunderbolt", 90, 100, "special", "Electric");
		vector<Move> moves = {m1, m2};
		Pokemon p1("Alex", t1, t2, b1, moves, 50);
		Pokemon p2;
		p2 = p1;

		cout << "Alex original" << endl;
		p1.PrettyPrint();

		cout << "Alex the copycat" << endl;
		p2.PrettyPrint();
	}

	void Stat_testGen() {
		Type t1("Fire");
   		Type t2("Rock");
		Move m1("Flamethrower", 90, 100, "special", "Fire");
        Move m2("Thunderbolt", 90, 100, "special", "Electric");
		vector<Move> moves = {m1, m2};
		Stats s1;
		s1.GenerateStats(60);
		Pokemon p1("Alex", t1, t2, s1, moves, 50);
		p1.PrettyPrint();
	}

	void Stat_valid() {
		Stats b1(45, 66, 90, 90, 80, 48);
		vector<int> statsmod = {1, 2, 3};  
		int stage = 2;
		bool result = b1.ModifyStats(statsmod, stage);
		cout << "Mod Stat test 1: valid stats:  " << result << endl;
	}

	void Stat_modifyHP() {
		Stats b1(45, 66, 90, 90, 80, 48);
		vector<int> statsmod = {0};  
		int stage = 2;
		cout << "Mod Stat test 2: " << endl;
		bool result = b1.ModifyStats(statsmod, stage);
	}
	
	void invalidStages() {
		Stats b1(45, 66, 90, 90, 80, 48);
		vector<int> statsmod = {1, 2, 3};  
		int stage = -7;
		bool result = b1.ModifyStats(statsmod, stage);
		cout << "Mod Stat test 3: invalid stats:  " << result << endl;
	}
	void GetMove() {
		Stats baseStats(45, 70, 80, 20, 40, 58);
		Type t1("Fire");
		Type t2("Water");
		cout << t1.GetType() << endl;
		Move m1("Flamethrower", 90, 100, "special", "Fire");
        Move m2("Thunderbolt", 90, 100, "special", "Electric");
		
		vector<Move> moves = {m1, m2};
		Pokemon pokemon("Charmander", t1, t2, baseStats, moves, 50);
	}
	
};

int main(void) {
	PokemonStatMoveTest testing;
	testing.runTests();
	return 0;
}

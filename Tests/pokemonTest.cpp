#include "../pokemon.hpp"
#include "../move.hpp"
#include "../type.hpp"

#include <string>

using std::cout;
using std::endl;

class PokemonTest {
public:
	void runTests() {
		testSetName();
		testSetTypes();
		testSetEmptyName();
		testSetLongName();
		testSetInvalidTypes();
		testSetSameTypes();
		testSetDifferentCaseTypes();
		testGetTypesWithOneTypeSet();
		testGetTypesWithNoTypesSet();
	}

private:
	void testSetName() {
		Pokemon pokemon;
		pokemon.set_name("Raichu");

		if (pokemon.get_name() != "Raichu") {
			cout << "Setting the name failed!" << endl;
		}
	}

	void testSetTypes() {
		Pokemon pokemon;
		Type typeOne("Electric");
		Type typeTwo("Flying");
		pokemon.set_type_one(typeOne);
		pokemon.set_type_two(typeTwo);

		if (pokemon.get_type_one() != "Electric" ||
			pokemon.get_type_two() != "Flying") {
			cout << "Test SetTypes failed!" << endl;
		}
	}

	void testSetEmptyName() {
		Pokemon pokemon;
		pokemon.set_name("");

		if (pokemon.get_name() != "") {
			cout << "Test SetEmptyName failed!" << endl;
		}
	}

	void testSetLongName() {
		Pokemon pokemon;
		pokemon.set_name("Pneumonoultramicroscopicsilicovolcanoconiosis");

		if (pokemon.get_name() != "Pneumonoultramicroscopicsilicovolcanoconiosis") {
			cout << "Test SetLongName failed!" << endl;
			cout << "Expected: Pneumonoultramicroscopicsilicovolcanoconiosis" << endl;
			cout << "Actual: " << pokemon.get_name() << endl;
		}
	}

	void testSetInvalidTypes() {
		Pokemon pokemon;
		Type invalidType("InvalidType");
		pokemon.set_type_one(invalidType);
		pokemon.set_type_two(invalidType);

		if (pokemon.get_type_one() != "" ||
			pokemon.get_type_two() != "") {
			cout << "Test SetInvalidTypes failed!" << endl;
		}
	}

	void testSetSameTypes() {
		Pokemon pokemon;
		Type electricType("Electric");
		pokemon.set_type_one(electricType);
		pokemon.set_type_two(electricType);

		if (pokemon.get_type_one() != "Electric" ||
			pokemon.get_type_two() != "Electric") {
			cout << "Test SetSameTypes failed!" << endl;
		}
	}

	void testSetDifferentCaseTypes() {
		Pokemon pokemon;
		Type typeOne("Electric");
		Type typeTwo("electric");
		pokemon.set_type_one(typeOne);
		pokemon.set_type_two(typeTwo);

		if (pokemon.get_type_one() != "Electric" ||
			pokemon.get_type_two() != "electric") {
			cout << "Test SetDifferentCaseTypes failed!" << endl;
		}
	}

	void testGetTypesWithOneTypeSet() {
		Pokemon pokemon;
		Type typeOne("Electric");
		pokemon.set_type_one(typeOne);

		Type typeOneResult = pokemon.get_type_one();
		Type typeTwoResult = pokemon.get_type_two();

		if (typeOneResult != "Electric" ||
			typeTwoResult != "") {
			cout << "Test GetTypesWithOneTypeSet failed!" << endl;
		}
	}

	void testGetTypesWithNoTypesSet() {
		Pokemon pokemon;

		Type typeOneResult = pokemon.get_type_one();
		Type typeTwoResult = pokemon.get_type_two();

		if (typeOneResult != "" ||
			typeTwoResult != "") {
			cout << "Test GetTypesWithNoTypesSet failed!" << endl;
		}
	}
};

int main(void) {
	PokemonTest testing;
	testing.runTests();
	return 0;
}

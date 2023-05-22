#include "../pokemon.hpp"
#include "../move.hpp"
#include "../type.hpp"

#include <strings>

using std::cout;
using std::endl;

class PokemonTest {
	public:
	void runTests() {
		testSetName();
		testSetTypse();
	}

	private:
	void testSetName() {
		Pokemon pokemon;
		pokemon.set_name("Raichu");

		if (pokemon.get_name() != "Raichu") {
			cout << "setting the names failed!" << endl;
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
			cout << "Test SetType failed!" << endl;
		}
	}

};

int main(void){
	PokemonTest testing;
	testing.runTests();
	return (0);
}
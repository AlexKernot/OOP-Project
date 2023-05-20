#include "../json.hpp"
#include "../readPokemonTeam.hpp"

class jsonTest : private ReadPokemonTeam{
public:
  jsonTest() : ReadPokemonTeam("playerTeams/testTeam", 0) {}
  bool Start() {
    ReadPokemonTeam::PrettyPrint();
    return false;
  }
};

int main(void) {
    jsonTest tests;
    bool result = tests.Start();
    return !result;
}
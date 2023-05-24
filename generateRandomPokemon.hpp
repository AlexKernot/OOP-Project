#include "json.hpp"
#include "pokemon.hpp"

class GenerateRandomPokemon: protected JSON, public Pokemon {
public:
    GenerateRandomPokemon();
};
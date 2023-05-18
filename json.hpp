#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
#include "pokemon.hpp"

using json = nlohmann::json;

class JSON {

public:
  Pokemon LoadPokemonData(std::string name);
};
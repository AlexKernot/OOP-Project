#ifndef POKEMON_JSON_H
#define POKEMON_JSON_H

#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
#include "pokemon.hpp"

using json = nlohmann::json;

class JSON {

public:
  bool LoadPokemonData(std::string name);
};

#endif
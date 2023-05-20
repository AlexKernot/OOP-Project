#ifndef POKEMON_JSON_H
#define POKEMON_JSON_H

#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
#include "pokemon.hpp"
#include "type.hpp"
#include "move.hpp"

using json = nlohmann::json;

class JSON {
  vector<json> pokemonData;
  vector<json> moveData;
  bool parseSuccess = false;

public:
  JSON();
  Pokemon *CreatePokemon(std::string name);
  bool GetParseResult() {return parseSuccess;}

private:
  void GenerateTypeError(json data, std::string expectedType, 
                              std::string at);
  json ParseFile(std::string fileName);
  json LoadSinglePokemonData(std::string name);
  Stats GetStatsJson(json statsJson);
  json GetField(json data, std::string name);
};

#endif
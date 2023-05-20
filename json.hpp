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
  Move CreateMove(std::string name);
  bool GetParseResult() {return parseSuccess;}

private:
  void GenerateTypeError(json data, std::string expectedType, 
                              std::string at);
  vector<Move> CreateMoveList(json pokemonData);
  json ParseFile(std::string fileName);
  json LoadSingleJsonObject(std::string name, vector<json> data);
  Stats GetStatsJson(json statsJson);
  int GetIndividualStat(json statsJson, std::string name);
  json GetField(json data, std::string name);
};

#endif
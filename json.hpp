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
/*          This is the class that parses PokeApi information                */
/*             that allows us to use Generation 1 Pokemon                    */
/*                                                                           */
/*****************************************************************************/

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
  Pokemon CreatePokemon(std::string name, vector<Move> moves, int level);
  vector<Move> CreateMoveList(json pokemonData, string pokemon);
  bool GetParseResult() {return parseSuccess;}
  json ParseFile(std::string fileName);
  vector<json> *GetJsonData() {return &pokemonData;}

protected:
  void GenerateTypeError(json data, std::string expectedType, 
                              std::string at);
  Move CreateMove(std::string name);
  bool ValidateMove(string moveName, string pokemon);
  json LoadSingleJsonObject(std::string name, vector<json> data);
  Stats GetStatsJson(json statsJson);
  int GetIndividualStat(json statsJson, std::string name);
  json GetField(json data, std::string name);
};

#endif
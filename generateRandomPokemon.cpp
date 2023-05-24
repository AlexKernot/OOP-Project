#include "generateRandomPokemon.hpp"

GenerateRandomPokemon::GenerateRandomPokemon() : JSON() {
  vector<json> *jsonData = GetJsonData();
  size_t size = jsonData->size();
  int pokemonIndex = rand() % size;
  json pokemonData = jsonData->at(pokemonIndex);
  json nameJson = GetField(pokemonData, "name");
  if (nameJson.is_string() == false) {
    GenerateTypeError(pokemonData, "string", "name");
    std::cout << "Defaulting to Missingno." << std::endl;
    Pokemon::operator=(Pokemon());
    return;
  }
  std::string name = nameJson;
  json movesData = GetField(pokemonData, "moves");
  if (movesData.is_array() == false) {
    GenerateTypeError(movesData, "Array", "moves");
    std::cout << "Defaulting to missingno." << std::endl;
    Pokemon::operator=(Pokemon());
    return;
  }
  vector<json> moveArray = movesData;
  size_t moveListLength = moveArray.size();
  vector<Move> moveList;
  for (size_t i = 0; i < 4; ++i) {
    int moveIndex = rand() % moveListLength;
    std::string moveName = moveArray.at(moveIndex);
    moveList.push_back(CreateMove(moveName));
  }
  int level = 70 + (rand() % 20);
  Pokemon::operator=(CreatePokemon(name, moveList, level));
}
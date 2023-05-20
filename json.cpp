#include "json.hpp"

json JSON::ParseFile(std::string name) {
  std::string fileName = "resources/" + name + ".json";
  std::ifstream file(fileName);
  if (file.fail()) {
    std::cout << fileName << " could not be opened.\n";
    parseSuccess = false;
    return json(nullptr);
  }
  json tempData = json::parse(file, nullptr, false, true);
  file.close();
  if (tempData.is_discarded() == true)
  {
    std::cout << "A syntax error was found in pokemonList.json";
    parseSuccess = false;
    return json(nullptr);
  }
  try {
    tempData = tempData.at(name);
  } catch (const json::out_of_range&) {
    std::cout << "Missing " << name << " field in json.\n";
    parseSuccess = false;
    return json(nullptr);
  }
  parseSuccess = true;
  return tempData;
}

JSON::JSON() {
  json temp;
  temp = ParseFile("pokemonList");
  if (!temp.is_array())
  {
    parseSuccess = false;
    return ;
  }
  pokemonData = temp;
  temp = ParseFile("moveList");
  if (!temp.is_array())
  {
    parseSuccess = false;
    return ;
  }
  moveData = temp;
}

json JSON::LoadSinglePokemonData(std::string name) {
  json tempPokemonName;
  json pokemon;
  int size = static_cast<int>(pokemonData.size());
  for (int i = 0; i < size; ++i) {
    try {
      tempPokemonName = pokemonData[i].at("name");
    } catch (const json::out_of_range&) {
      std::cout << "Missing \"name\" field at index: " << i;
      return json(nullptr);
    }
    if (!tempPokemonName.is_string()) {
      GenerateTypeError(pokemonData[i], "String", "name");
      return json(nullptr);
    }
    if (pokemonData[i].at("name") == name) {
      pokemon = pokemonData[i];
      break;
    }
  }
  if (pokemon == nullptr)
    return false;
  std::string s_name = pokemon.at("name");
  return true;
}

json JSON::GetField(json data, std::string name) {
  json field;
  try {
    field = data.at(name);
  } catch (const json::out_of_range&) {
    std::cout << name << " field not found in " << data.at("name");
    return json(nullptr);
  }
  return field;
}

Stats JSON::GetStatsJson(json statsJson) {
  Stats pokemonStats = Stats(11, 4, 4, 4, 4, 4);
  json tempStat;
  tempStat = GetField(statsJson, "hp");
  if (!tempStat.is_number_integer()) {
    GenerateTypeError(statsJson, "number (integer)", "hp");
    return pokemonStats;
  }
  pokemonStats.SetHP(tempStat);
  tempStat = GetField(statsJson, "attack");
  if (!tempStat.is_number_integer()) {
    GenerateTypeError(statsJson, "number (integer)", "attack");
    return pokemonStats;
  }
  pokemonStats.SetAttack(tempStat);
  tempStat = GetField(statsJson, "defense");
  if (!tempStat.is_number_integer()) {
    GenerateTypeError(statsJson, "number (integer)", "defense");
    return pokemonStats;
  }
  pokemonStats.SetDefense(tempStat);
  tempStat = GetField(statsJson, "s_attack");
  if (!tempStat.is_number_integer()) {
    GenerateTypeError(statsJson, "number (integer)", "s_attack");
    return pokemonStats;
  }
  pokemonStats.SetSpecialAttack(tempStat);
  tempStat = GetField(statsJson, "s_defense");
  if (!tempStat.is_number_integer()) {
    GenerateTypeError(statsJson, "number (integer)", "s_defense");
    return pokemonStats;
  }
  pokemonStats.SetDefense(tempStat);
  tempStat = GetField(statsJson, "speed");
  if (!tempStat.is_number_integer()) {
    GenerateTypeError(statsJson, "number (integer)", "speed");
    return pokemonStats;
  }
  pokemonStats.SetSpeed(tempStat);
  return pokemonStats;
}

Pokemon *JSON::CreatePokemon(std::string name) {
  json tempJson;
  json pokemonJson = LoadSinglePokemonData(name);
  if (pokemonJson.is_null() == true)
    return nullptr;
  tempJson = GetField(pokemonJson, "type_one");
  if (!tempJson.is_string()) {
    GenerateTypeError(pokemonJson, "string", "type_one");
    return nullptr;
  }
  std::string type1 = tempJson;
  tempJson = GetField(pokemonJson, "type_two");
  if (!tempJson.is_string()) {
    GenerateTypeError(pokemonJson, "string", "type_two");
    return nullptr;
  }
  std::string type2 = tempJson;
  json statsJson = GetField(pokemonJson, "stats");
  if (!tempJson.is_array()) {
    GenerateTypeError(pokemonJson, "array", "stats");
    return nullptr;
  }
  Stats pokemonStats = GetStatsJson(statsJson);
  std::vector<Move> moves = {
    Move("Test1", 100, "None", "Normal", false),
    Move("Test2", 100, "None", "Normal", false),
    Move("Test3", 100, "None", "Normal", false),
    Move("Test4", 100, "None", "Normal", false)};
  Pokemon *pokemon = new Pokemon(name, Type(type1), Type(type2), pokemonStats, moves, 1);
  return pokemon;
}

void JSON::GenerateTypeError(json data, std::string expectedType, std::string at)
{
  std::cout << "Invalid syntax detected. Expected: " << expectedType
  << ", found: " << data.at(at).type_name()
  << " at: \n" << data.dump(2) << std::endl;
}
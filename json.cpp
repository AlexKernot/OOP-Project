#include "json.hpp"

JSON::JSON() {
  json temp;
  temp = ParseFile("pokemonList");
  if (!temp.is_array()) {
    parseSuccess = false;
    return ;
  }
  pokemonData = temp;
  temp = ParseFile("moveList");
  if (!temp.is_array()) {
    parseSuccess = false;
    return ;
  }
  moveData = temp;
}

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
  if (tempData.is_discarded() == true) {
    std::cout << "A syntax error was found in resources/" << name << ".json";
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

Move JSON::CreateMove(std::string name) {
  json moveJson = LoadSingleJsonObject(name, moveData);
  if (moveJson.is_null()) {
    std::cout << "!! - Alert - !! move " << name 
    << " defaulting to struggle.\n";
    return Move("Struggle", 50, 100, "Recoil 50", "Normal");
  }
  json tempJson = GetField(moveJson, "type");
  if (!tempJson.is_string()) {
    GenerateTypeError(moveJson, "string", "type");
    std::cout << "!! - Alert - !! move " << name 
    << " defaulting to struggle.\n";
    return Move("Struggle", 50, 100, "Recoil 50", "Normal");
  }
  std::string moveType = tempJson;
  tempJson = GetField(moveJson, "base_power");
  if (!tempJson.is_number_integer()) {
    GenerateTypeError(moveJson, "integer (number)", "base_power");
    std::cout << "!! - Alert - !! move " << name 
    << " defaulting to struggle.\n";
    return Move("Struggle", 50, 100, "Recoil 50", "Normal");
  }
  int movePower = tempJson;
  tempJson = GetField(moveJson, "accuracy");
  if (!tempJson.is_number_integer()) {
    GenerateTypeError(moveJson, "integer (number)", "accuracy");
    std::cout << "!! - Alert - !! move " << name 
    << " defaulting to struggle.\n";
    return Move("Struggle", 50, 100, "Recoil 50", "Normal");
  }
  int moveAccuracy = tempJson;
  tempJson = GetField(moveJson, "effect");
  if (!tempJson.is_string()) {
    GenerateTypeError(moveJson, "string", "effect");
    std::cout << "!! - Alert - !! move " << name 
    << " defaulting to struggle.\n";
    return Move("Struggle", 50, 100, "Recoil 50", "Normal");
  }
  std::string moveEffect = tempJson;
  return Move(name,  movePower, moveAccuracy, moveEffect, moveType);
}

json JSON::LoadSingleJsonObject(std::string name, vector<json> data) {
  json tempJsonObjectName;
  json jsonObject;
  int size = static_cast<int>(data.size());
  for (int i = 0; i < size; ++i) {
    try {
      tempJsonObjectName = data[i].at("name");
    } catch (const json::out_of_range&) {
      std::cout << "Missing \"name\" field at index: " << i;
      return json(nullptr);
    }
    if (!tempJsonObjectName.is_string()) {
      GenerateTypeError(data[i], "String", "name");
      return json(nullptr);
    }
    if (data[i].at("name") == name) {
      jsonObject = data[i];
      break;
    }
  }
  return jsonObject;
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

int JSON::GetIndividualStat(json statsJson, std::string name) {
  json tempStat;
  tempStat = GetField(statsJson, name);
  if (!tempStat.is_number_integer()) {
    GenerateTypeError(statsJson, "number (integer)", name);
    std::cout << "\n!! - Alert - !! stat " << name << " is defaulting to 1.\n";
    return 1;
  }
  return tempStat;
}

Stats JSON::GetStatsJson(json statsJson) {
  Stats pokemonStats = Stats(11, 4, 4, 4, 4, 4);
  pokemonStats.SetHP(GetIndividualStat(statsJson, "hp"));
  pokemonStats.SetAttack(GetIndividualStat(statsJson, "attack"));
  pokemonStats.SetSpecialAttack(GetIndividualStat(statsJson, "s_attack"));
  pokemonStats.SetDefense(GetIndividualStat(statsJson, "defense"));
  pokemonStats.SetSpecialDefense(GetIndividualStat(statsJson, "s_defense"));
  pokemonStats.SetSpeed(GetIndividualStat(statsJson, "speed"));
  return pokemonStats;
}

vector<Move> JSON::CreateMoveList(json pokemonData) {
  vector<Move> moves{};
  json tempJson = GetField(pokemonData, "moves");
  if (!tempJson.is_array())
  {
    GenerateTypeError(pokemonData, "array", "moves");
    return moves;
  }
  vector<string> moveJson = tempJson;
  int size = static_cast<int>(moveJson.size());
  if (size > 4)
  {
    size = 4;
    std::cout << "!! -- alert -- !! more than 4 moves detected."
    << " only the first 4 will be read. \n";
  }
  for (int i = 0; i < size; ++i) {
    tempJson = moveJson.at(i);
    if (!tempJson.is_string())
    {
      GenerateTypeError(moveJson, "string", "index " + std::to_string(i));
      moves[i] = Move("Struggle", 50, 100, "Recoil 50", "Normal");
      std::cout << "!! -- Alert -- !! Move defaulting to Struggle\n";
      continue;
    }
    std::string moveName = tempJson;
    moves[i] = CreateMove(moveName);
  }
  return moves;
}

Pokemon *JSON::CreatePokemon(std::string name) {
  json tempJson;
  json pokemonJson = LoadSingleJsonObject(name, pokemonData);
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
  std::vector<Move> moves = CreateMoveList(pokemonJson);
  Pokemon *pokemon = new Pokemon(name, Type(type1), Type(type2), 
                                  pokemonStats, moves, 1);
  return pokemon;
}

void JSON::GenerateTypeError(json data, std::string expectedType, std::string at)
{
  std::cout << "Invalid syntax detected. Expected: " << expectedType
  << ", found: " << data.at(at).type_name()
  << " at: \n" << data.dump(2) << std::endl;
}
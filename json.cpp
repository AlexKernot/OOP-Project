#include "json.hpp"

bool JSON::LoadPokemonData(std::string name) {
  std::ifstream file("resources/pokemonList.json");
  json data;
  try
  {
    data = json::parse(file);
  }
  catch(const json::parse_error e)
  {
    std::cerr << e.what() << '\n';
    return false;
  }
  std::vector<json> allPokemon = data.at("pokemon");
  json pokemon;
  for (int i = 0; i < allPokemon.size(); ++i)
  {
    if (!allPokemon[i].at("name").is_string())
    {
      std::cout << "invalid sytax detected. expected: String, found: " 
      << allPokemon[i].at("name").type_name() << " at index " << i << ": \n" 
      << allPokemon[i].dump(2) << std::endl;
    }
    if (allPokemon[i].at("name") == name)
    {
      pokemon = allPokemon[i];
      break;
    }
  }
  if (pokemon == nullptr)
    return false;
  std::string s_name = pokemon.at("name");
  std::cout << s_name << std::endl;
  return true;
}
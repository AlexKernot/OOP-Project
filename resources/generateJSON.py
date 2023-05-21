import json
import time
import requests

pokedexRequest = requests.get("https://pokeapi.co/api/v2/pokedex/2/")
pokedexData = pokedexRequest.text
pokedexJson = json.loads(pokedexData)
pokedexJson = pokedexJson["pokemon_entries"]
file = open("pokemonList.json", "w")
file.write('{\n"pokemonList": [')

for i in range(len(pokedexJson)):
  pokemonName = pokedexJson[i]["pokemon_species"]["name"]
  pokemonRequest = requests.get("https://pokeapi.co/api/v2/pokemon/" + pokemonName)
  pokemonJson = json.loads(pokemonRequest.text)
  typeJson = pokemonJson["types"]
  type_one = typeJson[0]["type"]["name"]
  type_two = "NULL"
  if (len(typeJson) == 2):
    type_two = typeJson[1]["type"]["name"]
  statsJson = pokemonJson["stats"]
  stats = []
  for j in range(len(statsJson)):
    stats.append(statsJson[j]["base_stat"])
  movesJson = pokemonJson["moves"]
  moves = []
  for j in range(len(movesJson)):
    if (movesJson[j]["version_group_details"][0]["version_group"]["name"] == "red-blue"):
        moves.append(movesJson[j]["move"]["name"])
  statsObject = {
    "hp": stats[0],
    "attack": stats[1],
    "s_attack": stats[2],
    "defense": stats[3],
    "s_defense": stats[4],
    "speed": stats[5]
  }
  pokemonObject = {
    "name" : pokemonName,
    "type_one" : type_one,
    "type_two" : type_two,
    "stats" : statsObject,
    "moves" : moves
    }
  file.write(json.dumps(pokemonObject, indent=2) + ",")
  print("got pokemon", pokemonName, "successfully")
  time.sleep(0.1)
file.write("]}\n")
file.close()

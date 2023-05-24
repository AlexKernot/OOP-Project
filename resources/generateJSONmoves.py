import json
import time
import requests

pokedexRequest = requests.get("https://pokeapi.co/api/v2/generation/1/")
pokedexData = pokedexRequest.text
pokedexJson = json.loads(pokedexData)
pokedexJson = pokedexJson["moves"]
file = open("moveList.json", "w")
file.write('{\n"moveList": [')

for i in range(len(pokedexJson)):
  pokemonName = pokedexJson[i]["name"]
  pokemonRequest = requests.get("https://pokeapi.co/api/v2/move/" + pokemonName)
  if not pokemonRequest.status_code == 200:
    print(pokemonRequest.status_code)
  pokemonJson = json.loads(pokemonRequest.text)
  name = pokemonJson["name"]
  power = pokemonJson["power"]
  type = pokemonJson["type"]
  typeName = type["name"]
  accuracy = pokemonJson["accuracy"]
  effectJson = pokemonJson["effect_entries"]
  effect = "Null"
  if (not len(effectJson) == 0):
    effect = effectJson[0]["effect"]
  moveObject = {
    "name" : name,
    "power": power,
    "type": typeName,
    "accuracy": accuracy,
    "effect": effect
  }
  file.write(json.dumps(moveObject, indent=2) + ",")
  print("got move", name, "successfully")
  time.sleep(0.1)
file.write("]}\n")
file.close()
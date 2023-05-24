import json
import time
import requests

pokedexRequest = requests.get("https://pokeapi.co/api/v2/generation/1/")
pokedexData = pokedexRequest.text
pokedexJson = json.loads(pokedexData)
pokedexJson = pokedexJson["pokemon_species"]

for i in range(len(pokedexJson)):
  pokemonName = pokedexJson[i]["name"]
  pokemonRequest = requests.get("https://pokeapi.co/api/v2/pokemon/" + pokemonName)
  if not pokemonRequest.status_code == 200:
    print(pokemonRequest.status_code)
  pokemonJson = json.loads(pokemonRequest.text)
  name = pokemonJson["name"]
  link = pokemonJson["sprites"]["versions"]["generation-i"]["red-blue"]["front_transparent"]
  img_data = requests.get(link).content
  with open(name + ".png", 'wb') as handler:
    handler.write(img_data)
  print("Got", name)
#ifndef POKEMON_READPOKEMONFILE_H
#define POKEMON_READPOKEMONFILE_H

#include "json.hpp"
#include "pokemon.hpp"

class ReadPokemonTeam: public Pokemon, protected JSON {
  static JSON data;
public:
  ReadPokemonTeam(string fileName, int index);
};
#endif
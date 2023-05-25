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
/*              Pokemon teams can be selected with this class.               */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#ifndef POKEMON_READPOKEMONFILE_H
#define POKEMON_READPOKEMONFILE_H

#include "json.hpp"
#include "pokemon.hpp"

class ReadPokemonTeam: public Pokemon, protected JSON {
  private:
   static JSON data;
   bool generateAll = true;
  public:
  /* Reads a user input file and parses the JSON data from it to construct a  */
  /* new pokemon class within itself that can be used in the game.            */
   ReadPokemonTeam(string fileName, int index);
  /*  This will return false if all the pokemon have been read from a file    */
  /*  before generating 6 pokemon. This allows for the rest to be random.     */
   bool GetGenerateAll() {return generateAll;}
};


#endif
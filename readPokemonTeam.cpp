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
/*          Pokemon teams can be selected with this class.                   */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "readPokemonTeam.hpp"

/* This allows the player to create a Team of Pokemon for Normal Team selected Mode*/
ReadPokemonTeam::ReadPokemonTeam(string fileName, int index) : JSON(){
  json playerData = ParseFile(fileName);
  if (GetParseResult() == false)
    return;
  if (playerData.size() <= index) {
    std::cout << "Only detected " << playerData.size() << " pokemon in file."
      << " Generating randoms.";
      generateAll = false;
      return ;
  }
  playerData = playerData[index];
  json tempJson = GetField(playerData, "name");
  if (tempJson.is_string() == false) {
    GenerateTypeError(playerData, "string", "name");
    return ;
  }
  std::string pokemonName = tempJson;
  tempJson = GetField(playerData, "level");
  if (tempJson.is_number_integer() == false) {
    GenerateTypeError(playerData, "number (integer)", "level");
    return ;
  }
  int level = tempJson;
  tempJson = GetField(playerData, "moves");
  if (tempJson.is_array() == false) {
    GenerateTypeError(playerData, "array", "moves");
    return ;
  }
  vector<Move> moves = CreateMoveList(playerData, pokemonName);
  Pokemon pokemon = CreatePokemon(pokemonName, moves, level);
  set_name(pokemon.get_name());
  set_type_one(pokemon.get_type_one());
  set_type_two(pokemon.get_type_two());
  set_level(pokemon.get_level());
  set_max_hp(pokemon.get_max_hp());
  set_current_hp(pokemon.get_hp());
  set_base_stats(pokemon.get_base_stats());
  set_stats(pokemon.get_stats());
  set_moves(pokemon.get_moves());
}
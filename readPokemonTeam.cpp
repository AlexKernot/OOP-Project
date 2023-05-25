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
  int size = static_cast<int>(playerData.size());
  if (size <= index) {
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
  SetName(pokemon.GetName());
  SetTypeOne(pokemon.GetTypeOne());
  SetTypeTwo(pokemon.GetTypeTwo());
  SetLevel(pokemon.GetLevel());
  SetMaxHp(pokemon.GetMaxHp());
  SetCurrentHp(pokemon.GetHp());
  SetBaseStats(pokemon.GetBaseStats());
  SetStats(pokemon.GetStats());
  SetMoves(pokemon.GetMoves());
}
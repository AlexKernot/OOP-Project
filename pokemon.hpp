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
/*        This is the Pokemon class responsible for the creation of          */
/*      Pokemon, their respective stats, and stat changes in battle          */
/*                                                                           */
/*****************************************************************************/

#ifndef POKEMON_H
#define POKEMON_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <map>

#include <string>
#include <vector>

#include "move.hpp"
#include "type.hpp"
#include "stats.hpp"

using std::string;
using std::time;
using std::rand;
using std::cout;
using std::vector;
using std::max;
using std::min;
using std::map;

class Pokemon
{
private: 
  string name;
  Type typeOne;
  Type typeTwo;
  int level;
  int maxHp;
  int currentHp;
  Stats baseStats;
  Stats stats;
  vector<Move> moveList;
public:
  Pokemon(string name, Type type_one, Type type_two, 
          Stats stats, vector<Move> moves, int level);
  Pokemon(const Pokemon& pokemon);
  Pokemon() : Pokemon("Missingno", Type("Normal"), Type("NULL"), Stats(), 
                       vector<Move>{}, 1) {}
  ~Pokemon() {}
  void operator=(const Pokemon& pokemon);
  void PrettyPrint();
  void receive_move(Move moves, int level, int atk, int baseAtk);
  void set_name(string name);
  void set_type_one(Type type);
  void set_type_two(Type type);
  void set_moves(vector<Move*> moves);
  void set_level(int level) {this->level = level;}
  void set_current_hp(int hp) {currentHp = hp;}
  void set_max_hp(int maxHp) {this->maxHp = maxHp;}
  void set_base_stats(Stats baseStats) {this->baseStats = baseStats;}
  void set_stats(Stats stats) {this->stats = stats;}
  string get_name();
  int get_hp() {return currentHp;}
  int get_max_hp() {return maxHp;}
  Type get_type_one();
  Type get_type_two();
  vector<Move*> get_moves();
  int get_level() {return level;}
  Stats get_base_stats() {return baseStats;}
  Stats get_stats() {return stats;}

private:
  void take_damage(int pwr);
  void attack_damage(Move move, int level, int atk, int baseAtk);
  void special_attack_damage(Move move);
};

#endif
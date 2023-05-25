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
  bool isFainted = false;
public:
  Pokemon(string name, Type type_one, Type type_two, 
          Stats stats, vector<Move> moves, int level);
  Pokemon(const Pokemon& pokemon);
  Pokemon();
  ~Pokemon() {}
  Pokemon& operator=(const Pokemon& pokemon);
  void PrettyPrint();
  void ReceiveMove(Move moves, int level, int atk, int baseAtk);
  void SetName(string name);
  void SetTypeOne(Type type);
  void SetTypeTwo(Type type);
  void SetMoves(vector<Move*> moves);
  void SetLevel(int level) {this->level = level;}
  void SetCurrentHp(int hp) {currentHp = hp;}
  void SetMaxHp(int maxHp) {this->maxHp = maxHp;}
  void SetBaseStats(Stats baseStats) {this->baseStats = baseStats;}
  void SetStats(Stats stats) {this->stats = stats;}
  string GetName();
  int GetHp() {return currentHp;}
  int GetMaxHp() {return maxHp;}
  Type GetTypeOne();
  Type GetTypeTwo();
  vector<Move*> GetMoves();
  int GetLevel() {return level;}
  Stats GetBaseStats() {return baseStats;}
  Stats GetStats() {return stats;}
  bool GetIsFainted() {return isFainted;}

private:
  void TakeDamage(int pwr);
  void AttackDamage(Move move, int level, int atk, int baseAtk);
};

#endif
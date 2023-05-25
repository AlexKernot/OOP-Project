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
/*     This is the class handling Pokemon stats throughout the game.         */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#ifndef POKEMON_STATS_H
#define POKEMON_STATS_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

class Stats {
  int stats[6];
  int statModifiers[6];
public:

  Stats() : Stats(11, 4, 4, 4, 4, 4) {}
  /* Initializes Stats with values */
  Stats(int hp, int attack, int specialAttack, 
        int defense, int specialDefense, int speed);
  /*  Deep copy of a class' stats and stat modifiers. */
  Stats(const Stats& statsClass);
  /*  Deep copy of a class' stats and stat modifiers. */
  Stats& operator=(const Stats& stats);
  ~Stats() {}
  /* Calculates stats based on given level */
  void GenerateStats(int level);
  /* Allows for stats modifications withiin certain constraints that are */
  /* in line with the actual games restrictions.                         */
  bool ModifyStats(std::vector<int> stats, int stages);
  int GetHP() {return stats[0];}
  int GetAttack() {return stats[1];}
  int GetDefense() {return stats[2];}
  int GetSpecialAttack() {return stats[3];}
  int GetSpecialDefense() {return stats[4];}
  int GetSpeed() {return stats[5];}
  void SetHP(int hp) {stats[0] = hp;}
  void SetAttack(int attack) {stats[1] = attack;}
  void SetSpecialAttack(int specialAttack) {stats[2] = specialAttack;}
  void SetDefense(int defense) {stats[3] = defense;}
  void SetSpecialDefense(int specialDefense) {stats[4] = specialDefense;}
  void SetSpeed(int speed) {stats[5] = speed;}
};

#endif
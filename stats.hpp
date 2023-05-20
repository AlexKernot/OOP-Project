#ifndef POKEMON_STATS_H
#define POKEMON_STATS_H

#include <vector>
#include <string>

class Stats {
  int stats[6];
  int statModifiers[6];
public:
    Stats(int hp, int attack, int specialAttack, 
          int specialDefense, int speed);
    Stats(const Stats& statsClass);
    void operator=(const Stats& stats);
    ~Stats() {}
    bool ModifyStats(std::vector<int> stats, int stages);
    int GetHP() {return stats[0];}
    int GetAttack() {return stats[1];}
    int GetDefense() {return stats[2];}
    int GetSpecialAttack() {return stats[3];}
    int GetSpecialDefense() {return stats[4];}
    int GetSpeed() {return stats[5];}
};

#endif
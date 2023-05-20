#include "stats.hpp"

Stats::Stats(int hp, int attack, int specialAttack, 
              int defense, int specialDefense, int speed) {
  stats[0] = hp;
  stats[1] = attack;
  stats[2] = specialAttack;
  stats[3] = defense;
  stats[4] = specialDefense;
  stats[5] = speed;
}

/*  Deep copy of a class' stats and stat modifiers.                           */
Stats::Stats(const Stats& statsClass) {
  for (int i = 0; i < 6; ++i)
  {
    stats[i] = statsClass.stats[i];
    statModifiers[i] = statsClass.statModifiers[i];
  }
}

/*  Deep copy of a class' stats and stat modifiers.                           */
void Stats::operator=(const Stats& statsClass) {
  for (int i = 0; i < 6; ++i)
  {
    stats[i] = statsClass.stats[i];
    statModifiers[i] = statsClass.statModifiers[i];
  }
}

void Stats::GenerateStats(int level) {
  stats[0] =(((2 * stats[0] /* + IV + EV/4*/)* level) / 100 );
  stats[0] = floor(stats[0]) + level + 10;
  for (int i = 1; i < 6; ++i)
  {
    stats[i] = floor(((2 * stats[i] /*+ IV + EV/4 */) * level) / 100);
    stats[i] = floor((stats[i] + 5) /* x nature*/);
  }
}

bool Stats::ModifyStats(std::vector<int> statsMod, int stages) {
  if (stages == 0 || stages < -6 || stages > 6)
    return false;
  int size = static_cast<int>(statsMod.size());
  for (int i = 0; i < size; ++i)
  {
    if (statsMod[i] == 0)
    {
      std::cout << "Forbidden: Attempting to modify hp stat." << std::endl;
      return false;
    }
    if (statsMod[i] < 0 || statsMod[i] > 5)
    {
      std::cout << "Error: Attempting to modify invalid stat." << std::endl;
      return false;
    }
    int tempStage = stages;
    if (stages + statModifiers[statsMod[i]] > 6)
      tempStage = 6 - statModifiers[statsMod[i]];
    if (tempStage == 0)
      continue;
    if (tempStage > 0) {
      stats[i] *= ((static_cast<float>(tempStage) * 2.0F + 2.0F) / 2.0F);
    } else if (tempStage < 0) {
      stats[i] *= (2 / (static_cast<float>(tempStage) * 2.0F + 2.0F));
    }
    statModifiers[stats[i]] += tempStage;
  }
  return true;
}
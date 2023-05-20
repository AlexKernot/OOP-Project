#include "stats.hpp"

Stats::Stats(int hp, int attack, int specialAttack, 
              int specialDefense, int speed) {
  stats[0] = hp;
  stats[1] = attack;
  stats[2] = specialAttack;
  stats[3] = specialDefense;
  stats[4] = speed;
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

bool Stats::ModifyStats(std::vector<int> statsMod, int stages) {
  if (stages == 0 || stages < -6 || stages > 6)
    return false;
  int size = static_cast<int>(statsMod.size());
  for (int i = 0; i < size; ++i)
  {
    if (statsMod[i] < 0 || statsMod[i] > 5)
      return false;
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
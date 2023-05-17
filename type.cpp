#include "type.hpp"
#include <iostream>

Type::Type(std::string type) {
  int validateType = typeToNumber.find(type)->second;
  if (validateType > 16 || validateType < 0)
  {
    std::cout << "Type " << type << " not recognised. Defaulting to normal.\n";
    this->type = "Normal";
    return ;
  }
  this->type = type;
}

float Type::GenerateTypeEffectiveness(std::string defendingType1, 
                                      std::string defendingType2) {
  int attackingIndex = typeToNumber.find(type)->second;
  int type1Index = typeToNumber.find(defendingType1)->second;
  int type2Index = typeToNumber.find(defendingType2)->second;
  float type1Effectiveness = typeMatchups[attackingIndex][type1Index];

  float type2Effectiveness;
  if (type2Index < 16 && type2Index > 0)
    type2Effectiveness = typeMatchups[attackingIndex][type2Index];
  else
    type2Effectiveness = 1;

  float resultEffectiveness = type1Effectiveness * type2Effectiveness;
  return resultEffectiveness;
}
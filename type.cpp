#include "type.hpp"
#include <iostream>

Type::Type(const std::string type) {
  int validateType = typeToNumber.find(type)->second;
  if (validateType > 17 || validateType < 0)
  {
    std::cout << "Type " << type << " not recognised. Defaulting to normal.\n";
    this->type = "Normal";
    return ;
  }
  this->type = type;
}

Type::Type(const Type &type) {
  this->type = type.type;
}

Type& Type::operator=(const Type newType) {
  if (this == &newType)
    return *this;
  type = newType.type;
  return *this;
}

float Type::GenerateTypeEffectiveness(Type defendingType1, 
                                      Type defendingType2) {
  int attackingIndex = typeToNumber.find(type)->second;
  int type1Index = typeToNumber.find(defendingType1.GetType())->second;
  int type2Index = typeToNumber.find(defendingType2.GetType())->second;
  if (type1Index < 0 || type1Index > 16)
  {
    std::cout << "Invalid type 1 found. Defaulting to 1x effectiveness.\n";
    return 1.0F;
  }
  float type1Effectiveness = typeMatchups[attackingIndex][type1Index];

  float type2Effectiveness;
  if (type2Index < 16 && type2Index > 0)
    type2Effectiveness = typeMatchups[attackingIndex][type2Index];
  else
    type2Effectiveness = 1;

  float resultEffectiveness = type1Effectiveness * type2Effectiveness;
  return resultEffectiveness;
}
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
/*     This is the class handling Pokemon typing throughout the game.        */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include <iostream>

#include "type.hpp"

/* The type constructor checks that valid Type is assigned */
Type::Type(const std::string type) {
  int validateType = typeToNumber.find(type)->second;
  if (validateType > 17 || validateType < 0)
  {
    std::cout << "Type " << type << " not recognised. Defaulting to normal.\n";
    this->type = "normal";
    return ;
  }
  this->type = type;
}

/* This is the copy constructor of the Type class */
Type::Type(const Type &type) {
  this->type = type.type;
}

/* Allows for the asignment of Type value to new Type objects */
Type& Type::operator=(const Type& newType) {
  if (this == &newType)
    return *this;
  type = newType.type;
  return *this;
}

/* This function takes care of calculating the correct Type effectiveness */
/* every Type shares                                                      */
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
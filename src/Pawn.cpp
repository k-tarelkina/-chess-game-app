#include "Pawn.h"

Pawn::~Pawn() {}

std::string Pawn::getName()
{
  return "Pawn";
}

std::vector<Coordinates> Pawn::getPossiblePaths()
{
  return std::vector<Coordinates>{{1, 1}, {5, 4}};
}
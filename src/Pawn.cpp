#include "Pawn.h"

Pawn::~Pawn() {}

std::string Pawn::getName()
{
  return "Pawn";
}

std::vector<std::pair<int, int>> Pawn::getPossiblePaths()
{
  return std::vector<std::pair<int, int>>{{1, 1}, {5, 4}};
}
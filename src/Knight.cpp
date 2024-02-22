#include "Knight.h"

Knight::~Knight() {}

std::string Knight::getName()
{
  return "Knight";
}

std::vector<Coordinates> Knight::getPossiblePaths()
{
  return std::vector<Coordinates>{{1, 1}, {5, 4}};
}
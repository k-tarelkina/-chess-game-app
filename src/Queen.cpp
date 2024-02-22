#include "Queen.h"

Queen::~Queen() {}

std::string Queen::getName()
{
  return "Queen";
}

std::vector<Coordinates> Queen::getPossiblePaths()
{
  return std::vector<Coordinates>{{1, 1}, {5, 4}};
}
#include "Knight.h"

Knight::~Knight() {}

std::string Knight::getName()
{
  return "Knight";
}

std::vector<std::pair<int, int>> Knight::getPossiblePaths()
{
  return std::vector<std::pair<int, int>>{{1, 1}, {5, 4}};
}
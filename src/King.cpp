#include "King.h"

std::string King::getName()
{
  return "King";
}

std::vector<std::pair<int, int>> King::getPossiblePaths()
{
  return std::vector<std::pair<int, int>>{{2, 2}, {1, 1}, {6, 7}};
}
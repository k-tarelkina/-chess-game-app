#include "Queen.h"

std::string Queen::getName()
{
  return "Queen";
}

std::vector<std::pair<int, int>> Queen::getPossiblePaths()
{
  return std::vector<std::pair<int, int>>{{1, 1}, {5, 4}};
}
#include "Bishop.h"

Bishop::~Bishop() {}

std::string Bishop::getName()
{
  return "Bishop";
}

std::vector<std::pair<int, int>> Bishop::getPossiblePaths()
{
  return std::vector<std::pair<int, int>>{{1, 1}, {5, 4}};
}
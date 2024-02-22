#include "Rook.h"

Rook::~Rook() {}

std::string Rook::getName()
{
  return "Rook";
}

std::vector<std::pair<int, int>> Rook::getPossiblePaths()
{
  return std::vector<std::pair<int, int>>{{1, 1}, {5, 4}};
}
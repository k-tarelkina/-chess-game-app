#include "King.h"

King::~King() {}

std::string King::getName()
{
  return "King";
}

std::vector<Coordinates> King::getPossiblePaths()
{
  return std::vector<Coordinates>{{2, 2}, {1, 1}, {6, 7}};
}
#include "Knight.h"

Knight::~Knight() {}

std::string Knight::getName()
{
  return "Knight";
}

std::vector<Coordinates> Knight::getAllPaths()
{
  std::vector<Coordinates> possiblePaths = {
      {x_ + 1, y_ + 2},
      {x_ + 2, y_ + 1},
      {x_ - 1, y_ + 2},
      {x_ - 2, y_ + 1},
      {x_ + 1, y_ - 2},
      {x_ + 2, y_ - 1},
      {x_ - 1, y_ - 2},
      {x_ - 2, y_ - 1}};

  std::vector<Coordinates> correctPaths;

  std::copy_if(possiblePaths.begin(), possiblePaths.end(), std::back_inserter(correctPaths),
               [this](Coordinates p)
               { return p.first < 8 && p.second < 8 && p.first >= 0 && p.second >= 0 &&
                        !this->isPieceOfSameColor(p.first, p.second); });

  return correctPaths;
}
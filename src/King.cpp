#include "King.h"

King::~King() {}

std::string King::getName()
{
  return "King";
}

std::vector<Coordinates> King::getAllPaths()
{
  std::vector<Coordinates> possiblePaths = {
      {x_ + 1, y_ + 1},
      {x_, y_ + 1},
      {x_ - 1, y_ + 1},
      {x_ + 1, y_},
      {x_ - 1, y_},
      {x_ + 1, y_ - 1},
      {x_, y_ - 1},
      {x_ - 1, y_ - 1},
  };

  std::vector<Coordinates> correctPaths;

  std::copy_if(possiblePaths.begin(), possiblePaths.end(), std::back_inserter(correctPaths),
               [this](Coordinates p)
               { return p.first < 8 && p.second < 8 && p.first >= 0 && p.second >= 0 &&
                        !this->isPieceOfSameColor(p.first, p.second); });

  return correctPaths;
}
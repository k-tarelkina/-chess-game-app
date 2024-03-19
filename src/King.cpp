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
               {
                 int x = p.first;
                 int y = p.second;
                 return x < 8 && y < 8 && x >= 0 && y >= 0 &&
                        !this->isPieceOfSameColor(x, y); // &&
                                                         //! this->isUnderThreat(x, y, this);
               });

  return correctPaths;
}

bool King::cannotMove()
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
               {
                 int x = p.first;
                 int y = p.second;
                 return x < 8 && y < 8 && x >= 0 && y >= 0 &&
                        !this->isPieceOfSameColor(x, y);
               });

  return correctPaths.size() > 0 &&
         std::all_of(
             correctPaths.begin(),
             correctPaths.end(),
             [this](const Coordinates &c)
             { return this->isUnderThreat(c.first, c.second, this); });
}
#include "Bishop.h"

Bishop::~Bishop() {}

std::string Bishop::getName()
{
  return "Bishop";
}

std::vector<std::pair<int, int>> Bishop::getPossiblePaths()
{
  std::vector<std::pair<int, int>> paths;

  for (int i = 0; i < 8; i++)
  {
    std::vector<std::pair<int, int>> pairs = {
        {x_ + i, y_ + i},
        {x_ - i, y_ + i},
        {x_ + i, y_ - i},
        {x_ - i, y_ - i}};

    for (auto p : pairs)
    {
      int newX = p.first;
      int newY = p.second;

      if (newX < 8 && newY < 8 && newX >= 0 && newY >= 0)
        paths.push_back(p);
    }
  }

  return prunePath(paths);
}

std::vector<std::pair<int, int>> Bishop::prunePath(std::vector<std::pair<int, int>> path)
{
  std::vector<std::pair<int, int>> prunedPath;
  for (auto p : path)
  {
    if (isPieceOfSameColor(p.first, p.second))
      break;

    prunedPath.push_back(p);

    if (isPieceOfOppositeColor(p.first, p.second))
      break;
  }
  return prunedPath;
}
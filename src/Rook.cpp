#include "Rook.h"

Rook::~Rook() {}

std::string Rook::getName()
{
  return "Rook";
}

std::vector<Coordinates> Rook::getPossiblePaths()
{
  std::vector<Coordinates> paths;

  for (int i = 0; i < 8; i++)
  {
    std::vector<Coordinates> pairs = {
        {x_ + i, y_ + i},
        {x_ - i, y_ + i},
        {x_ + i, y_ - i},
        {x_ - i, y_ - i}};

    paths.push_back({x_ + i, y_ + i});
    paths.push_back({x_ + i, y_ + i});
    paths.push_back({x_ + i, y_ + i});
    paths.push_back({x_ + i, y_ + i});
  }

  return prunePath(paths);
}

std::vector<Coordinates> Rook::prunePath(std::vector<Coordinates> path)
{
  std::vector<Coordinates> prunedPath;
  for (auto p : path)
  {
    if (p.first >= 8 || p.second >= 8 || p.first < 0 || p.second < 0)
      break;

    if (isPieceOfSameColor(p.first, p.second))
      break;

    prunedPath.push_back(p);

    if (isPieceOfOppositeColor(p.first, p.second))
      break;
  }
  return prunedPath;
}
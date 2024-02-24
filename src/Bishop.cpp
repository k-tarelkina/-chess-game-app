#include "Bishop.h"

Bishop::~Bishop() {}

std::string Bishop::getName()
{
  return "Bishop";
}

std::vector<Coordinates> Bishop::getPossiblePaths()
{
  std::vector<Coordinates> paths;
  auto directions = getDirections();

  for (auto direction : directions)
  {
    std::vector<Coordinates> currentPath;

    for (int i = 1; i < 8; i++)
      currentPath.push_back(direction(x_, y_, i));

    currentPath = prunePath(currentPath);
    paths.insert(paths.end(), currentPath.begin(), currentPath.end());
  }

  return paths;
}

std::vector<Coordinates> Bishop::prunePath(std::vector<Coordinates> path)
{
  std::vector<Coordinates> prunedPath;
  for (auto p : path)
  {
    if (p.first >= 8 || p.second >= 8 || p.first < 0 || p.second < 0)
    {
      break;
    }

    if (isPieceOfSameColor(p.first, p.second) || isKingOfOppositeColor(p.first, p.second))
    {
      break;
    }
    prunedPath.push_back(p);

    if (isPieceOfOppositeColor(p.first, p.second))
    {
      break;
    }
  }
  return prunedPath;
}

std::vector<std::function<Coordinates(int, int, int)>> Bishop::getDirections()
{
  std::vector<std::function<Coordinates(int, int, int)>> directions;

  directions.push_back([](int x, int y, int i)
                       { return std::make_pair(x + i, y + i); });
  directions.push_back([](int x, int y, int i)
                       { return std::make_pair(x + i, y - i); });
  directions.push_back([](int x, int y, int i)
                       { return std::make_pair(x - i, y + i); });
  directions.push_back([](int x, int y, int i)
                       { return std::make_pair(x - i, y - i); });
  return directions;
}
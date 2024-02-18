#pragma once

#include "ChessPiece.h"
#include <vector>
#include <string>

class Queen : public ChessPiece
{
public:
  std::string override getName()
  {
    return "Queen";
  }

  std::vector<std::pair<int, int>> override getPossiblePaths()
  {
    return std::vector<std::pair<int, int>>{{1, 1}, {5, 4}};
  }
};

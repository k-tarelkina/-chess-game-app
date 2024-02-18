#pragma once

#include "ChessPiece.h"
#include <vector>
#include <string>

class Queen : public ChessPiece
{
public:
  using ChessPiece::ChessPiece;
  std::string getName() override;
  std::vector<std::pair<int, int>> getPossiblePaths() override;
};

#pragma once

#include "ChessPiece.h"
#include <vector>
#include <string>

class Bishop : public ChessPiece
{
public:
  Bishop(int x, int y, Color color, Chessboard *chessboard) : ChessPiece(x, y, color, chessboard) {}
  ~Bishop() override;

  std::string getName() override;
  std::vector<std::pair<int, int>> getPossiblePaths() override;
};

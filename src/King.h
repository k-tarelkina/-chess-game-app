#pragma once

#include "ChessPiece.h"
#include <vector>
#include <string>

class King : public ChessPiece
{
public:
  King(int x, int y, Color color, Chessboard *chessboard) : ChessPiece(x, y, color, chessboard) {}
  ~King() override;

  using ChessPiece::ChessPiece;
  std::string getName() override;
  std::vector<std::pair<int, int>> getPossiblePaths() override;
};
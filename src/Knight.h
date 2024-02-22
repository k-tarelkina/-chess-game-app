#pragma once

#include "ChessPiece.h"
#include <vector>
#include <string>

class Knight : public ChessPiece
{
public:
  Knight(int x, int y, Color color, Chessboard *chessboard) : ChessPiece(x, y, color, chessboard) {}
  ~Knight() override;

  std::string getName() override;
  std::vector<std::pair<int, int>> getPossiblePaths() override;
};

#pragma once

#include "ChessPiece.h"
#include <vector>
#include <string>

class Queen : public ChessPiece
{
public:
  Queen(int x, int y, Color color, Chessboard *chessboard) : ChessPiece(x, y, color, chessboard) {}
  ~Queen() override;

  std::string getName() override;
  std::vector<Coordinates> getPossiblePaths() override;
};

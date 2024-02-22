#pragma once

#include "ChessPiece.h"
#include <vector>
#include <string>

class Rook : public ChessPiece
{
public:
  Rook(int x, int y, Color color, Chessboard *chessboard) : ChessPiece(x, y, color, chessboard) {}
  ~Rook() override;

  std::string getName() override;
  std::vector<Coordinates> getPossiblePaths() override;

private:
  std::vector<Coordinates> prunePath(std::vector<Coordinates> path);
};

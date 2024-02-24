#pragma once

#include "ChessPiece.h"
#include <vector>
#include <string>

class King : public ChessPiece
{
public:
  King(int x, int y, Color color, Chessboard *chessboard) : ChessPiece(x, y, color, chessboard) {}
  ~King() override;

  std::string getName() override;

protected:
  std::vector<Coordinates> getAllPaths() override;
};
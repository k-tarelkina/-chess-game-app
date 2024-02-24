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

protected:
  std::vector<Coordinates> getAllPaths() override;
};

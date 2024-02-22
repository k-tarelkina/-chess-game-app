#pragma once

#include "ChessPiece.h"
#include <vector>
#include <string>
#include <functional>

class Bishop : public ChessPiece
{
public:
  Bishop(int x, int y, Color color, Chessboard *chessboard) : ChessPiece(x, y, color, chessboard) {}
  ~Bishop() override;

  std::string getName() override;
  std::vector<Coordinates> getPossiblePaths() override;

private:
  std::vector<Coordinates> prunePath(std::vector<Coordinates> path);

  // Helper function to calculate direction from a given point (x, y) by
  // incrementing it by a value of i
  // (int, int, int) corresponds to (x, y, i)
  std::vector<std::function<Coordinates(int, int, int)>> getDirections();
};

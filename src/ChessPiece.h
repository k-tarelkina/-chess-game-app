#pragma once

#include "ChessPiece.fwd.h"
#include "Chessboard.fwd.h"
#include "ChessboardEnum.h"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class ChessPiece
{
public:
  ChessPiece(int x, int y, Color color, Chessboard *chessboard);
  virtual ~ChessPiece();

  void moveTo(int x, int y);
  void die();
  bool canMoveTo(int x, int y);
  Color getColor();

  virtual std::string getName() = 0;
  virtual std::vector<std::pair<int, int>> getPossiblePaths() = 0;

protected:
  int x_;
  int y_;
  Color color_;
  Chessboard *chessboard_;

  bool isPieceOfSameColor(int x, int y);
  bool isPieceOfOppositeColor(int x, int y);
};
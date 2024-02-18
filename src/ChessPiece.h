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
private:
  int x_;
  int y_;
  Color color_;
  Chessboard *chessboard_;

public:
  ChessPiece(int x, int y, Color color, Chessboard *chessboard);
  virtual ~ChessPiece();

  void moveTo(int x, int y);
  virtual void die();
  virtual bool canMoveTo(int x, int y);

  virtual std::string getName() = 0;
  virtual std::vector<std::pair<int, int>> getPossiblePaths() = 0;
};
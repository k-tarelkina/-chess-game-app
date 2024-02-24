#pragma once

#include "ChessPiece.fwd.h"
#include "Chessboard.fwd.h"
#include "ChessboardEnum.h"
#include "ChessCustomTypes.h"

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
  virtual std::vector<Coordinates> getPossiblePaths() = 0;

protected:
  int x_;
  int y_;
  bool hasMoved_;
  Color color_;
  Chessboard *chessboard_;

  bool isPieceOfSameColor(int x, int y);
  bool isPieceOfOppositeColor(int x, int y);
  bool hasPiece(int x, int y);
  bool isKingOfOppositeColor(int x, int y);
};
#pragma once

#include "ChessPiece.h"

class ChessboardCell
{
private:
  ChessPiece *piece_;
  int x_;
  int y_;

public:
  ChessboardCell();
  ChessboardCell(int x, int y);

  ChessPiece *putPiece(ChessPiece *piece);
  ChessPiece *getPiece();
  bool hasPiece();
  void clear();
};

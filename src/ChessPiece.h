#pragma once

#include "Chessboard.h"
#include <string>

class ChessPiece
{
private:
  int x;
  int y;
  std::string color;
  Chessboard *chessboard;
  std::string image;

public:
  ChessPiece(int x, int y, const std::string &color, Chessboard *chessboard)
      : x(x), y(y), color(color), chessboard(chessboard), image("image")
  {
    this->chessboard->putPiece(x, y, this);
  }

  virtual ~ChessPiece() {}

  void moveTo(int x, int y);
  virtual void die();
  virtual bool canMoveTo(int x, int y);

  virtual std::string getName() = 0;
  virtual std::vector<std::pair<int, int>> getPossiblePaths() = 0;
};
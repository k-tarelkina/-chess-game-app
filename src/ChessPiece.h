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
  bool threatensKing();
  Color getColor();
  std::vector<Coordinates> getCorrectPaths();
  virtual bool canFight(int x, int y);

  virtual std::string getName() = 0;

protected:
  int x_;
  int y_;
  bool hasMoved_;
  bool isDead_;
  Color color_;
  Chessboard *chessboard_; // TODO make private

  bool isPieceOfSameColor(int x, int y);
  bool isPieceOfOppositeColor(int x, int y);
  bool hasPiece(int x, int y);
  bool isKingOfOppositeColor(int x, int y);
  bool isUnderThreat(int x, int y, ChessPiece *checkFor);

  virtual std::vector<Coordinates> getAllPaths() = 0;
};
#include "ChessPiece.h"
#include "Chessboard.h" // Fixes error: invalid use of incomplete type ‘class Chessboard’

ChessPiece::ChessPiece(int x, int y, Color color, Chessboard *chessboard)
    : x_(x), y_(y), color_(color), chessboard_(chessboard)
{
}

ChessPiece::~ChessPiece() {}

Color ChessPiece::getColor()
{
  return color_;
}

void ChessPiece::moveTo(int x, int y)
{
  if (!canMoveTo(x, y))
  {
    std::cout << "Cannot move to these coordinates" << std::endl;
    return;
  }

  chessboard_->clearCell(x_, y_);
  x_ = x;
  y_ = y;

  ChessPiece *prevPiece = chessboard_->putPiece(x, y, this);
  if (prevPiece != nullptr)
  {
    prevPiece->die();
  }
}

void ChessPiece::die()
{
  chessboard_->addDeadPiece(this);
}

bool ChessPiece::canMoveTo(int x, int y)
{
  auto possiblePaths = getPossiblePaths();
  return std::any_of(
      possiblePaths.begin(),
      possiblePaths.end(),
      [x, y](const Coordinates &c)
      { return c.first == x && c.second == y; });
}

bool ChessPiece::isPieceOfSameColor(int x, int y)
{
  ChessPiece *piece = chessboard_->getPiece(x, y);
  if (piece == nullptr)
    return false;

  return piece->getColor() == color_;
}

bool ChessPiece::isPieceOfOppositeColor(int x, int y)
{
  ChessPiece *piece = chessboard_->getPiece(x, y);
  if (piece == nullptr)
    return false;

  return piece->getColor() != color_;
}

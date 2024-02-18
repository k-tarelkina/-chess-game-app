#include "ChessPiece.h"

ChessPiece::ChessPiece(int x, int y, const std::string &color, Chessboard *chessboard)
    : x_(x), y_(y), color_(color), chessboard_(chessboard)
{
  chessboard_->putPiece(x, y, this);
}

virtual ~ChessPiece::ChessPiece() {}

void ChessPiece::moveTo(int x, int y)
{
  if (!canMoveTo(x, y))
  {
    std::cout << "Cannot move to these coordinates" << std::endl;
    return;
  }

  chessboard_->clearCell(this->x, this->y);
  x_ = x;
  y_ = y;

  ChessPiece *prevPiece = chessboard_->putPiece(x, y, this);
  if (prevPiece != nullptr)
  {
    prevPiece->die();
  }
}

virtual void ChessPiece::die()
{
  chessboard_->addDeadPiece(this);
}

virtual bool ChessPiece::canMoveTo(int x, int y)
{
  auto possiblePaths = getPossiblePaths();
  return std::any_of(
      possiblePaths.begin(),
      possiblePaths.end(),
      [x, y](const std::pair<int, int> &c)
      { return c.first == x && c.second == y; });
}
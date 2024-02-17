#include "ChessPiece.h"

ChessPiece::ChessPiece(int x, int y, const std::string &color, Chessboard *chessboard)
    : x(x), y(y), color(color), chessboard(chessboard), image("image")
{
  this->chessboard->putPiece(x, y, this);
}

virtual ~ChessPiece::ChessPiece() {}

void ChessPiece::moveTo(int x, int y)
{
  if (!canMoveTo(x, y))
  {
    std::cout << "Cannot move to these coordinates" << std::endl;
    return;
  }
  chessboard->clearCell(this->x, this->y);
  this->x = x;
  this->y = y;

  ChessPiece *prevPiece = chessboard->putPiece(x, y, this);
  if (prevPiece != nullptr)
  {
    prevPiece->die();
  }
}

virtual void ChessPiece::die()
{
  chessboard->addDeadPiece(this);
}

virtual bool ChessPiece::canMoveTo(int x, int y)
{
  return false;
}

virtual std::string ChessPiece::getName()
{
  return "Chess piece";
}

virtual std::vector<std::pair<int, int>> ChessPiece::getPossiblePaths()
{
  return std::vector<std::pair<int, int>>();
};
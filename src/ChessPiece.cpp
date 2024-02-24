#include "ChessPiece.h"
#include "Chessboard.h" // Fixes error: invalid use of incomplete type ‘class Chessboard’

ChessPiece::ChessPiece(int x, int y, Color color, Chessboard *chessboard)
    : x_(x), y_(y), color_(color), chessboard_(chessboard), hasMoved_(false), isDead_(false)
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

  hasMoved_ = true;
}

void ChessPiece::die()
{
  isDead_ = true;
  chessboard_->addDeadPiece(this);
}

bool ChessPiece::canMoveTo(int x, int y)
{
  if (isDead_)
  {
    return false;
  }
  auto possiblePaths = getPossiblePaths();
  return std::any_of(
      possiblePaths.begin(),
      possiblePaths.end(),
      [x, y](const Coordinates &c)
      { return c.first == x && c.second == y; });
}

bool ChessPiece::threatensKing()
{
  if (isDead_)
  {
    return false;
  }
  auto possiblePaths = getAllPaths();
  return std::any_of(
      possiblePaths.begin(),
      possiblePaths.end(),
      [this](const Coordinates &c)
      { return this->isKingOfOppositeColor(c.first, c.second); });
}

std::vector<Coordinates> ChessPiece::getPossiblePaths()
{
  std::vector<Coordinates> possiblePaths = getAllPaths();
  std::vector<Coordinates> correctPaths;

  // Filter out king cell as cannot fight it!
  std::copy_if(possiblePaths.begin(), possiblePaths.end(), std::back_inserter(correctPaths),
               [this](Coordinates p)
               { return !this->isKingOfOppositeColor(p.first, p.second); });

  return correctPaths;
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

bool ChessPiece::isKingOfOppositeColor(int x, int y)
{
  ChessPiece *piece = chessboard_->getPiece(x, y);
  if (piece == nullptr)
    return false;

  return piece->getColor() != color_ && piece->getName() == "King";
}

bool ChessPiece::hasPiece(int x, int y)
{
  return chessboard_->hasPiece(x, y);
}
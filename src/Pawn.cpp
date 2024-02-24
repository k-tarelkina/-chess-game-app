#include "Pawn.h"

Pawn::~Pawn() {}

std::string Pawn::getName()
{
  return "Pawn";
}

bool Pawn::canFight(int x, int y)
{
  if (isDead_)
  {
    return false;
  }

  if (color_ == Color::White && x_ == 0 ||
      color_ == Color::Black && x_ == 7)
  {
    return false;
  }

  if (y_ > 0 && y_ < 7)
  {
    return true;
  }

  return false;
}

std::vector<Coordinates> Pawn::getAllPaths()
{
  if (color_ == Color::White && x_ == 0 ||
      color_ == Color::Black && x_ == 7)
  {
    return {};
  }

  std::vector<Coordinates> paths;

  if (color_ == Color::White)
  {
    if (!hasMoved_ && !hasPiece(x_ + 1, y_) && !hasPiece(x_ + 2, y_))
      paths.push_back(std::make_pair(x_ + 2, y_));

    if (!hasPiece(x_ + 1, y_))
      paths.push_back(std::make_pair(x_ + 1, y_));

    if (y_ > 0 && isPieceOfOppositeColor(x_ + 1, y_ - 1))
      paths.push_back(std::make_pair(x_ + 1, y_ - 1));

    if (y_ < 7 && isPieceOfOppositeColor(x_ + 1, y_ + 1))
      paths.push_back(std::make_pair(x_ + 1, y_ + 1));
  }
  else // Black color
  {
    if (!hasMoved_ && !hasPiece(x_ - 1, y_) && !hasPiece(x_ - 2, y_))
      paths.push_back(std::make_pair(x_ - 2, y_));

    if (!hasPiece(x_ - 1, y_))
      paths.push_back(std::make_pair(x_ - 1, y_));

    if (y_ > 0 && isPieceOfOppositeColor(x_ - 1, y_ - 1))
      paths.push_back(std::make_pair(x_ - 1, y_ - 1));

    if (y_ < 7 && isPieceOfOppositeColor(x_ - 1, y_ + 1))
      paths.push_back(std::make_pair(x_ - 1, y_ + 1));
  }

  return paths;
}
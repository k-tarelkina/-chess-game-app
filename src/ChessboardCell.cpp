#include "ChessboardCell.h"

ChessboardCell::ChessboardCell(int x, int y)
    : x_(x), y_(y), piece_(nullptr)
{
}

ChessPiece *ChessboardCell::putPiece(ChessPiece *piece)
{
  ChessPiece *prevPiece = piece_;
  piece_ = piece;
  return prevPiece;
}

ChessPiece *ChessboardCell::getPiece()
{
  return piece_;
}

bool ChessboardCell::hasPiece()
{
  return piece_ != nullptr;
}

void ChessboardCell::clear()
{
  piece_ = nullptr;
}
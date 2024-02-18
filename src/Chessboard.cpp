#include "Chessboard.h"

Chessboard::Chessboard(UI &ui) : cells_(8, std::vector<ChessboardCell>(8)), selectedCell_(0), ui_(ui)
{
}

void Chessboard::initializeBoard()
{
  for (int i = 7; i >= 0; --i)
  {
    for (int j = 0; j < 8; ++j)
    {
      ChessboardCell cell(i, j, this);
      cells[i][j] = cell;
    }
  }

  // call to UI
}

void Chessboard::initializePieces()
{
  // call to UI
  new Queen(0, 1, Color.White, this);

  // Assuming King and Queen constructors take (x, y, color, chessboard)
  // King *king = new King(0, 0, COLOR::White, this);
  // Queen *queen = new Queen(0, 1, COLOR::White, this);
  // Queen *queen2 = new Queen(0, 2, COLOR::Black, this);
  // Log the cells to the console (if needed)
  // This part of the code would be platform-specific and is not included here
}

void Chessboard::onCellClicked(int x, int y)
{
  if (selectedCell_ != 0 && selectedCell_->hasPiece())
  {
    Piece *piece = selectedCell->getPiece();
    piece->moveTo(x, y);
    clearHighlightedCells();
  }
  else
  {
    selectedCell_ = &cells[x][y];
    selectedCell_->select();
  }
}

void Chessboard::clearHighlightedCells()
{
  // call to UI
}

void Chessboard::selectCell(int x, int y)
{
  // call to UI
}

void Chessboard::highlightCells(const std::vector<std::pair<int, int>> &coordinates)
{
  // call to UI
}

void Chessboard::clearCell(int x, int y)
{
  cells[x][y].clear();
}

ChessPiece *Chessboard::putPiece(int x, int y, ChessPiece *piece)
{
  return cells_[x][y].putPiece(piece);
}

ChessPiece *Chessboard::getPiece(int x, int y)
{
  return cells_[x][y].getPiece();
}

void Chessboard::addDeadPiece(ChessPiece *piece)
{
  // call to UI
}
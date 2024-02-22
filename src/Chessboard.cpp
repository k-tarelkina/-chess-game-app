#include "Chessboard.h"

Chessboard::Chessboard(UI *ui) : cells_(8, std::vector<ChessboardCell>(0)),
                                 selectedCell_(0), ui_(ui)
{
  ui_->attachObserver(this);
}

void Chessboard::initializeBoard()
{
  for (int i = 7; i >= 0; --i)
  {
    for (int j = 0; j < 8; ++j)
    {
      ChessboardCell cell(i, j);
      cells_[i].push_back(cell);
    }
  }
}

void Chessboard::initializePieces()
{
  // White pieces

  putPiece(1, 0, new Pawn(1, 0, Color::White, this));
  putPiece(1, 1, new Pawn(1, 1, Color::White, this));
  putPiece(1, 2, new Pawn(1, 2, Color::White, this));
  putPiece(1, 3, new Pawn(1, 3, Color::White, this));

  putPiece(1, 4, new Pawn(1, 4, Color::White, this));
  putPiece(1, 5, new Pawn(1, 5, Color::White, this));
  putPiece(1, 6, new Pawn(1, 6, Color::White, this));
  putPiece(1, 7, new Pawn(1, 7, Color::White, this));

  putPiece(0, 1, new Knight(7, 2, Color::White, this));
  putPiece(0, 2, new Bishop(0, 2, Color::White, this));
  putPiece(0, 3, new Queen(0, 3, Color::White, this));
  putPiece(0, 4, new King(0, 4, Color::White, this));
  putPiece(0, 5, new Bishop(0, 5, Color::White, this));
  putPiece(0, 6, new Knight(7, 2, Color::White, this));

  // Black pieces

  putPiece(6, 0, new Pawn(6, 0, Color::Black, this));
  putPiece(6, 1, new Pawn(6, 1, Color::Black, this));
  putPiece(6, 2, new Pawn(6, 2, Color::Black, this));
  putPiece(6, 3, new Pawn(6, 3, Color::Black, this));

  putPiece(6, 4, new Pawn(6, 4, Color::Black, this));
  putPiece(6, 5, new Pawn(6, 5, Color::Black, this));
  putPiece(6, 6, new Pawn(6, 6, Color::Black, this));
  putPiece(6, 7, new Pawn(6, 7, Color::Black, this));

  putPiece(7, 1, new Knight(7, 2, Color::Black, this));
  putPiece(7, 2, new Bishop(7, 2, Color::Black, this));
  putPiece(7, 3, new Queen(7, 3, Color::Black, this));
  putPiece(7, 4, new King(7, 4, Color::Black, this));
  putPiece(7, 5, new Bishop(7, 5, Color::Black, this));
  putPiece(7, 6, new Knight(7, 2, Color::Black, this));
}

void Chessboard::onCellClicked(int x, int y)
{
  bool moveToThisCell = selectedCell_ != nullptr && selectedCell_->hasPiece();
  if (moveToThisCell)
  {
    ChessPiece *piece = selectedCell_->getPiece();
    piece->moveTo(x, y);
    clearCellsHighlight();
    return;
  }

  selectedCell_ = &cells_[x][y];
  ChessPiece *piece = selectedCell_->getPiece();

  if (piece == nullptr)
  {
    selectedCell_ = nullptr; // Cannot select empty cells
  }
  else
  {
    highlightSelectedCell(x, y);
    auto possiblePaths = piece->getPossiblePaths();
    highlightCells(possiblePaths);
  }
}

void Chessboard::onUiReady()
{
  initializeBoard();
  initializePieces();
}

void Chessboard::clearCellsHighlight()
{
  ui_->clearCellsHighlight();
}

void Chessboard::highlightSelectedCell(int x, int y)
{
  ui_->highlightSelectedCell(x, y);
}

void Chessboard::highlightCells(const std::vector<std::pair<int, int>> &coordinates)
{
  ui_->highlightCells(coordinates);
}

void Chessboard::clearCell(int x, int y)
{
  cells_[x][y].clear();
  ui_->removePiece(x, y);
}

ChessPiece *Chessboard::putPiece(int x, int y, ChessPiece *piece)
{
  ui_->putPiece(x, y, piece->getName(), piece->getColor());
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

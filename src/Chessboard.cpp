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
  std::cout << "initializePieces" << std::endl;
  putPiece(0, 1, new Queen(0, 1, Color::White, this));
  // new King(0, 2, Color::White, this);
  // Assuming King and Queen constructors take (x, y, color, chessboard)
  // King *king = new King(0, 0, COLOR::White, this);
  // Queen *queen = new Queen(0, 1, COLOR::White, this);
  // Queen *queen2 = new Queen(0, 2, COLOR::Black, this);
  // Log the cells to the console (if needed)
  // This part of the code would be platform-specific and is not included here
}

void Chessboard::onCellClicked(int x, int y)
{
  std::cout << "onCellClicked" << std::endl;
  if (selectedCell_ != nullptr && selectedCell_->hasPiece())
  {
    ChessPiece *piece = selectedCell_->getPiece();
    piece->moveTo(x, y);
    clearCellsHighlight();
  }
  else
  {
    selectedCell_ = &cells_[x][y];
    ChessPiece *piece = selectedCell_->getPiece();
    if (piece != nullptr)
    {
      selectCell(x, y);
      auto possiblePaths = piece->getPossiblePaths();
      highlightCells(possiblePaths);
    }
  }
}

void Chessboard::onUiReady()
{
  initializeBoard();
  initializePieces();
}

void Chessboard::clearCellsHighlight()
{
  // call to UI
}

void Chessboard::selectCell(int x, int y)
{
  // call to UI
}

void Chessboard::highlightCells(const std::vector<std::pair<int, int>> &coordinates)
{
  ui_->highlightCells(coordinates);
}

void Chessboard::clearCell(int x, int y)
{
  cells_[x][y].clear();
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
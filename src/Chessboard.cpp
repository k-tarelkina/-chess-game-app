#include "Chessboard.h"

void Chessboard::clearSelection()
{
  clearCellsStyles();
  selectedCell = nullptr;
  markedCells.clear();
}

void Chessboard::onCellClicked(int x, int y)
{
  if (selectedCell && selectedCell->hasPiece())
  {
    Piece *piece = selectedCell->getPiece();
    piece->moveTo(x, y);
    clearSelection();
  }
  else
  {
    selectedCell = &cells[x][y];
    cells[x][y].select();
  }
}

void clearCellsStyles()
{
  for (Cell *cell : markedCells)
  {
    cell->getElement().removeClass(STATE::HighlightedOccupied);
    cell->getElement().removeClass(STATE::HighlightedFree);
  }
  if (selectedCell)
  {
    selectedCell->getElement().removeClass(STATE::Selected);
  }
}

void highlightCells(const std::vector<std::pair<int, int>> &coordinates)
{
  for (const auto &c : coordinates)
  {
    cells[c.first][c.second].highlight();
    markedCells.push_back(&cells[c.first][c.second]);
  }
}

void clearCell(int x, int y)
{
  cells[x][y].clear();
}

bool putPiece(int x, int y, Piece *piece)
{
  return cells[x][y].putPiece(piece);
}

Piece *getPiece(int x, int y)
{
  return cells[x][y].getPiece();
}

void disableColor() {}
void enableColor() {}

void addDeadPiece(Piece *piece)
{
  // Assuming there is a function to update the UI with the dead piece
  // This part of the code would be platform-specific and is not included here
}

void initializeBoard()
{
  // Assuming there is a function to create and append cell elements to the UI
  // This part of the code would be platform-specific and is not included here
  for (int i = 7; i >= 0; --i)
  {
    for (int j = 0; j < 8; ++j)
    {
      Cell cell(i, j, this);
      cells[i][j] = cell;
      // Append cell.element to the UI
    }
  }
}

void initializePieces()
{
  // Assuming King and Queen constructors take (x, y, color, chessboard)
  King *king = new King(0, 0, COLOR::White, this);
  Queen *queen = new Queen(0, 1, COLOR::White, this);
  Queen *queen2 = new Queen(0, 2, COLOR::Black, this);
  // Log the cells to the console (if needed)
  // This part of the code would be platform-specific and is not included here
}
}
;

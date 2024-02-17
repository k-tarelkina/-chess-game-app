#pragma once

#include "ChessboardCell.h"
#include <vector>
#include <string>
#include <iostream>

class Chessboard
{
private:
  std::vector<std::vector<ChessboardCell>> cells;
  std::vector<ChessboardCell *> markedCells;
  Cell *selectedCell;

public:
  Chessboard() : cells(8, std::vector<ChessboardCell>(8)), selectedCell(nullptr) {}

  void initializeBoard();
  void initializePieces();

  void clearSelection();
  void onCellClicked(int x, int y);
  void clearCellsStyles();

  void highlightCells(const std::vector<std::pair<int, int>> &coordinates);

  void clearCell(int x, int y);

  bool putPiece(int x, int y, Piece *piece);

  Piece *getPiece(int x, int y);

  void disableColor() {}
  void enableColor() {}

  void addDeadPiece(Piece *piece);
};

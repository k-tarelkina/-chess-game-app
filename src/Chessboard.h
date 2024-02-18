#pragma once

#include "ChessboardCell.h"
#include "ChessPiece.fwd.h"
#include "Chessboard.fwd.h"
#include "UI.h"
#include <vector>
#include <string>
#include <iostream>
#include "Queen.h"

class Chessboard
{
private:
  std::vector<std::vector<ChessboardCell>> cells_;
  ChessboardCell *selectedCell_;
  UI *ui_;

public:
  explicit Chessboard(UI *ui);

  void initializeBoard();
  void initializePieces();

  void onCellClicked(int x, int y);

  void highlightCells(const std::vector<std::pair<int, int>> &coordinates);
  void selectCell(int x, int y);
  void clearCellsHighlight();

  void clearCell(int x, int y);

  ChessPiece *putPiece(int x, int y, ChessPiece *piece);
  ChessPiece *getPiece(int x, int y);

  void addDeadPiece(ChessPiece *piece);
};

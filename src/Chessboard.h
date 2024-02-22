#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "ChessboardCell.h"
#include "ChessPiece.fwd.h"
#include "Chessboard.fwd.h"
#include "UI.h"
#include "UIObserver.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"

class Chessboard : public UIObserver
{
public:
  explicit Chessboard(UI *ui);

  void initializeBoard();
  void initializePieces();

  void onCellClicked(int x, int y) override;
  void onUiReady() override;
  // TODO move to private methods
  void highlightCells(const std::vector<std::pair<int, int>> &coordinates);
  void highlightSelectedCell(int x, int y);
  void clearCellsHighlight();

  void clearCell(int x, int y);

  ChessPiece *putPiece(int x, int y, ChessPiece *piece);
  ChessPiece *getPiece(int x, int y);

  void addDeadPiece(ChessPiece *piece);

private:
  std::vector<std::vector<ChessboardCell>> cells_;
  ChessboardCell *selectedCell_;
  UI *ui_;

  bool shouldMoveCell();
};

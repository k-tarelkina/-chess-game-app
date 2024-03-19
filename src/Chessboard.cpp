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
  for (int i = 0; i < 8; i++)
  {
    addNewPiece(1, i, new Pawn(1, i, Color::White, this));
  }

  addNewPiece(0, 0, new Rook(0, 0, Color::White, this));
  addNewPiece(0, 1, new Knight(0, 1, Color::White, this));
  addNewPiece(0, 2, new Bishop(0, 2, Color::White, this));
  addNewPiece(0, 3, new Queen(0, 3, Color::White, this));
  whiteKing_ = new King(0, 4, Color::White, this);
  addNewPiece(0, 4, whiteKing_);
  addNewPiece(0, 5, new Bishop(0, 5, Color::White, this));
  addNewPiece(0, 6, new Knight(0, 6, Color::White, this));
  addNewPiece(0, 7, new Rook(0, 7, Color::White, this));

  // Black pieces

  for (int i = 0; i < 8; i++)
  {
    addNewPiece(6, i, new Pawn(6, i, Color::Black, this));
  }

  addNewPiece(7, 0, new Rook(7, 0, Color::Black, this));
  addNewPiece(7, 1, new Knight(7, 1, Color::Black, this));
  addNewPiece(7, 2, new Bishop(7, 2, Color::Black, this));
  addNewPiece(7, 3, new Queen(7, 3, Color::Black, this));
  blackKing_ = new King(7, 4, Color::Black, this);
  addNewPiece(7, 4, blackKing_);
  addNewPiece(7, 5, new Bishop(7, 5, Color::Black, this));
  addNewPiece(7, 6, new Knight(7, 6, Color::Black, this));
  addNewPiece(7, 7, new Rook(7, 7, Color::Black, this));
}

void Chessboard::onCellClicked(int x, int y)
{
  bool moveToThisCell = selectedCell_ != nullptr && selectedCell_->hasPiece();
  if (moveToThisCell && usersEntered())
  {
    ChessPiece *piece = selectedCell_->getPiece();

    if (piece->canMoveTo(x, y))
    {
      piece->moveTo(x, y);
      ui_->resetTimer();
    }

    clearCellsHighlight();
    selectedCell_ = nullptr;
    return;
  }

  // Trying to move a piece, but usernames are not entered.
  if (moveToThisCell)
  {
    // Call to UI
    ui_->showMessage("Enter usernames before starting the game");
    std::cout
        << "Cannot move, usernames not entered" << std::endl;
    return;
  }

  ChessboardCell *cell = &cells_[x][y];
  ChessPiece *piece = cell->getPiece();

  if (piece == nullptr)
  {
    return; // Cannot select empty cells
  }

  if (piece->getColor() == currentColorTurn_)
  {
    selectedCell_ = cell;
    highlightSelectedCell(x, y);
    auto possiblePaths = piece->getCorrectPaths();
    highlightCells(possiblePaths);
  }
}

void Chessboard::onUiReady()
{
  initializeBoard();
}

void Chessboard::clearCellsHighlight()
{
  ui_->clearCellsHighlight();
}

void Chessboard::highlightSelectedCell(int x, int y)
{
  ui_->highlightSelectedCell(x, y);
}

void Chessboard::highlightCells(const std::vector<Coordinates> &coordinates)
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
  ChessPiece *deadPiece = cells_[x][y].putPiece(piece);

  if (std::any_of(pieces_.begin(), pieces_.end(), [](ChessPiece *p)
                  { return p->threatensKing(); }))
  {
    ui_->showMessage("Check !");
  }
  else
  {
    ui_->clearMessage();
  }

  switchColorTurn();

  return deadPiece;
}

ChessPiece *Chessboard::getPiece(int x, int y)
{
  return cells_[x][y].getPiece();
}

bool Chessboard::hasPiece(int x, int y)
{
  return cells_[x][y].hasPiece();
}

bool Chessboard::isUnderThreat(int x, int y)
{
  return std::any_of(pieces_.begin(), pieces_.end(), [x, y](ChessPiece *p)
                     { return p->canFight(x, y); });
}

void Chessboard::addDeadPiece(ChessPiece *piece)
{
  ui_->addDeadPiece(piece->getName(), piece->getColor());
}

void Chessboard::addNewPiece(int x, int y, ChessPiece *piece)
{
  ui_->putPiece(x, y, piece->getName(), piece->getColor());
  cells_[x][y].putPiece(piece);
  pieces_.push_back(piece);
}

void Chessboard::switchColorTurn()
{
  currentColorTurn_ = currentColorTurn_ == Color::White ? Color::Black : Color::White;
}

void Chessboard::onStartGame()
{
  gameInProgress = true;
  initializeBoard();
  initializePieces();
  ui_->startTimer();
}

void Chessboard::onStartGameOver()
{
  gameInProgress = false;
  ui_->clearBoard();
  ui_->clearUserNames();
  whitePiecesUser_ = "";
  blackPiecesUser_ = "";

  cells_.clear();
  std::vector<std::vector<ChessboardCell>> newCells(8, std::vector<ChessboardCell>(0));
  cells_ = newCells;

  selectedCell_ = nullptr;
  currentColorTurn_ = Color::White;
  ui_->stopTimer();
}

void Chessboard::onAddWhitePiecesUser(const std::string &username)
{
  whitePiecesUser_ = username;
}

void Chessboard::onAddBlackPiecesUser(const std::string &username)
{
  blackPiecesUser_ = username;
}

bool Chessboard::usersEntered()
{
  return whitePiecesUser_.length() > 0 && blackPiecesUser_.length() > 0;
}
#include <iostream>
#include <string>
#include <functional>
#include <vector>

// Assuming STATE is an enum or a set of constants defined elsewhere
// Assuming ChessPiece is a class defined elsewhere with methods getName() and getPossiblePaths()

class Cell
{
private:
  ChessPiece *piece;
  int x;
  int y;
  Chessboard *chessboard; // Assuming Chessboard is a class defined elsewhere

public:
  Cell(int x, int y, Chessboard *chessboard) : x(x), y(y), chessboard(chessboard), piece(nullptr)
  {
    // Constructor logic
    // Note: C++ does not have a direct equivalent of JavaScript's DOM manipulation.
    // You would need to use a library for GUI elements or graphics, like Qt or SFML.
  }

  ChessPiece *putPiece(ChessPiece *piece)
  {
    ChessPiece *prevPiece = this->piece;
    this->piece = piece;
    // Update the GUI element with the piece's name
    // element.innerText = this->piece->getName();
    return prevPiece;
  }

  void select()
  {
    if (this->piece)
    {
      // element.classList.add(STATE::Selected);
      chessboard->highlightCells(this->piece->getPossiblePaths());
    }
  }

  void highlight()
  {
    if (this->piece)
    {
      // element.classList.add(STATE::HighlightedOccupied);
    }
    else
    {
      // element.classList.add(STATE::HighlightedFree);
    }
  }

  void clear()
  {
    // element.innerText = "";
    this->piece = nullptr;
  }
};

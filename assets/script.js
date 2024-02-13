window.addEventListener("load", () => {
  chessBoard = document.getElementById("chess-board");

  if (chessBoard) {
    for (let i = 7; i >= 0; i--) {
      for (let j = 0; j < 8; j++) {
        const cell = new Cell(i, j);
        chessBoard.appendChild(cell.element);
      }
    }
  }
});

class Cell {
  piece = null;
  element = null;

  constructor(x, y) {
    this.element = document.createElement("div");
    this.element.addEventListener("click", () => console.log(x, y));
    if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1)) {
      this.element.classList.add("white");
    } else {
      this.element.classList.add("black");
    }
    console.log(this.element);
  }

  putPiece(piece) {
    const prevPiece = this.piece;
    this.piece = piece;
    return prevPiece;
  }
}

class Chessboard {
  clearCell(x, y) {}

  putPiece(x, y, pice) {}
}

class ChessPiece {
  x;
  y;

  ChessFigure(x, y) {
    this.x = x;
    this.y = y;
  }

  moveTo(x, y) {
    if (!this.canMoveTo(x, y)) {
      console.log("Cannot move to these coordinates");
    } else {
      this.x = x;
      this.y = y;
    }
  }

  canMoveTo(x, y) {
    return false;
  }

  select() {}
}

/*
King - Moves one square in any direction.
Queen - Moves any number of squares diagonally, horizontally, or vertically.
Rook - Moves any number of squares horizontally or vertically.
Bishop - Moves any number of squares diagonally.
Knight - Moves in an ‘L-shape,’ two squares in a straight direction, and then one square perpendicular to that.
Pawn - Moves one square forward, but on its first move, it can move two squares forward. It captures diagonally one square forward.

*/

class King extends ChessPiece {
  canMoveTo(x, y) {
    return Math.abs(this.x - x) > 1 || Math.abs(this.y - y) > 1;
  }
}

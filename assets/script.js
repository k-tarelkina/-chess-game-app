window.addEventListener("load", () => {
  const chessBoard = new Chessboard();
  chessBoard.initializeBoard();
  chessBoard.initializePieces();
});

const COLOR = {
  Black: "Black",
  White: "White",
};

class Cell {
  piece = null;
  element = null;
  x = 0;
  y = 0;

  constructor(x, y, chessBoard) {
    this.x = x;
    this.y = y;
    this.chessBoard = chessBoard;
    this.element = document.createElement("div");

    this.element.addEventListener("click", () => {
      this.select();
    });

    if ((x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1)) {
      this.element.classList.add("white");
    } else {
      this.element.classList.add("black");
    }
  }

  putPiece(piece) {
    const prevPiece = this.piece;
    this.piece = piece;
    this.element.innerText = this.piece.getName();
    return prevPiece;
  }

  select() {
    this.chessBoard.clearSelectedCells();
    if (this.piece) {
      this.element.classList.add("selected");
      this.chessBoard.setSelectedCell(this.x, this.y);
    }
  }

  clear() {
    this.element.innerText = "";
    // remove piece
  }
}

class Chessboard {
  cells = [[], [], [], [], [], [], [], []];

  peviouslySelectedCells = [];

  setBlackPiecesUser(username) {}
  setWhitePiecesUser(username) {}

  startGame() {}

  clearSelectedCells() {
    for (const cell of this.peviouslySelectedCells) {
      cell.element.classList.remove("selected");
    }
    this.peviouslySelectedCells = [];
  }

  setSelectedCell(x, y) {
    this.peviouslySelectedCells.push(this.cells[x][y]);
  }

  clearCell(x, y) {
    this.cells[x][y].clear();
  }

  putPiece(x, y, piece) {
    console.log(this.cells);
    this.cells[x][y].putPiece(piece);
  }

  disableColor() {}
  enableColor() {}

  addDeadPiece(piece) {
    // Render new piece
  }

  initializeBoard() {
    const chessBoard = document.getElementById("chess-board");

    if (chessBoard) {
      for (let i = 7; i >= 0; i--) {
        for (let j = 0; j < 8; j++) {
          const cell = new Cell(i, j, this);
          this.cells[i].push(cell);
          chessBoard.appendChild(cell.element);
        }
      }
    }
  }

  initializePieces() {
    /*
King - Moves one square in any direction.
Queen - Moves any number of squares diagonally, horizontally, or vertically.
Rook - Moves any number of squares horizontally or vertically.
Bishop - Moves any number of squares diagonally.
Knight - Moves in an ‘L-shape,’ two squares in a straight direction, and then one square perpendicular to that.
Pawn - Moves one square forward, but on its first move, it can move two squares forward. It captures diagonally one square forward.

*/
    const piecesConfig = [
      {
        create: () => King(),
        config: {
          x: 0,
          y: 0,
        },
      },
    ];

    const king = new King(0, 0, this);
  }
}

class ChessPiece {
  x;
  y;

  constructor(x, y, chessBoard) {
    this.x = x;
    this.y = y;
    this.chessBoard = chessBoard;
    this.image = "image";
    this.chessBoard.putPiece(x, y, this);
  }

  moveTo(x, y) {
    if (!this.canMoveTo(x, y)) {
      console.log("Cannot move to these coordinates");
    } else {
      this.x = x;
      this.y = y;
      this.chessBoard.clearCell(x, y);
      const prevPiece = this.chessBoard.putPiece(x, y, this);
      prevPiece?.die();
    }
  }

  die() {
    this.chessBoard.addDeadPiece(this);
  }

  canMoveTo(x, y) {
    return false;
  }

  getName() {
    return "Chess piece";
  }
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

  getName() {
    return "King";
  }
}

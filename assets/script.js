window.addEventListener("load", () => {
  const chessBoard = new Chessboard();
  chessBoard.initializeBoard();
  chessBoard.initializePieces();
});

const COLOR = {
  Black: "Black",
  White: "White",
};

const STATE = {
  Selected: "selected",
  HighlightedFree: "highlighted-free",
  HighlightedOccupied: "highlighted-occupied",
};

class Cell {
  piece;
  element;
  x = 0;
  y = 0;

  constructor(x, y, chessBoard) {
    this.x = x;
    this.y = y;

    this.chessBoard = chessBoard;
    this.element = document.createElement("div");

    this.element.addEventListener("click", () => {
      this.chessBoard.onCellClicked(x, y);
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
    if (this.piece) {
      this.element.classList.add(STATE.Selected);
      this.chessBoard.highlightCells(this.piece.getPossiblePaths());
    }
  }

  highlight() {
    if (this.piece) {
      this.element.classList.add(STATE.HighlightedOccupied);
    } else {
      this.element.classList.add(STATE.HighlightedFree);
    }
  }

  clear() {
    this.element.innerText = "";
    this.piece = undefined;
  }
}

class Chessboard {
  cells = [[], [], [], [], [], [], [], []];

  markedCells = [];
  selectedCell = undefined;

  setBlackPiecesUser(username) {}
  setWhitePiecesUser(username) {}
  startGame() {}

  onCellClicked(x, y) {
    const piece = this.selectedCell?.piece;
    if (piece) {
      piece.moveTo(x, y);
      this.clearCellsStyles();
      this.selectedCell = undefined;
      this.markedCells = [];
    } else {
      this.selectedCell = this.cells[x][y];
      this.cells[x][y].select();
    }
  }

  clearCellsStyles() {
    for (const cell of this.markedCells) {
      cell.element.classList.remove(STATE.HighlightedOccupied);
      cell.element.classList.remove(STATE.HighlightedFree);
    }
    this.selectedCell?.element.classList.remove(STATE.Selected);
  }

  highlightCells(coordinates) {
    for (const c of coordinates) {
      this.cells[c[0]][c[1]].highlight();
      this.markedCells.push(this.cells[c[0]][c[1]]);
    }
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
      return;
    }
    this.chessBoard.clearCell(this.x, this.y);
    this.x = x;
    this.y = y;
    const prevPiece = this.chessBoard.putPiece(x, y, this);
    prevPiece?.die();
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

  getPossiblePaths() {
    return [];
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
    return Math.abs(this.x - x) <= 1 && Math.abs(this.y - y) <= 1;
  }

  getName() {
    return "King";
  }

  getPossiblePaths() {
    return [
      [this.x - 1, this.y + 1],
      [this.x + 1, this.y + 1],
      [this.x + 1, this.y - 1],
      [this.x - 1, this.y - 1],
      [this.x - 1, this.y],
      [this.x + 1, this.y],
      [this.x, this.y - 1],
      [this.x, this.y + 1],
    ].filter((c) => c[0] >= 0 && c[1] >= 0 && c[0] < 8 && c[1] < 8);
  }
}

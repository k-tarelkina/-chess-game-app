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

  constructor(x, y, chessboard) {
    this.x = x;
    this.y = y;

    this.chessboard = chessboard;
    this.element = document.createElement("div");

    this.element.addEventListener("click", () => {
      this.chessboard.onCellClicked(x, y);
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
      this.chessboard.highlightCells(this.piece.getPossiblePaths());
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

  clearSelection() {
    this.clearCellsStyles();
    this.selectedCell = undefined;
    this.markedCells = [];
  }

  onCellClicked(x, y) {
    const piece = this.selectedCell?.piece;
    if (piece) {
      piece.moveTo(x, y);
      this.clearSelection();
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
    return this.cells[x][y].putPiece(piece);
  }

  getPiece(x, y) {
    return this.cells[x][y].piece;
  }

  disableColor() {}
  enableColor() {}

  addDeadPiece(piece) {
    // Render new piece
  }

  initializeBoard() {
    const chessboard = document.getElementById("chessboard");

    if (chessboard) {
      for (let i = 7; i >= 0; i--) {
        for (let j = 0; j < 8; j++) {
          const cell = new Cell(i, j, this);
          this.cells[i].push(cell);
          chessboard.appendChild(cell.element);
        }
      }
    }
  }

  initializePieces() {
    const piecesConfig = [
      {
        create: () => King(),
        config: {
          x: 0,
          y: 0,
        },
      },
    ];

    const king = new King(0, 0, COLOR.White, this);
    const queen = new Queen(0, 1, COLOR.White, this);
    const queen2 = new Queen(0, 2, COLOR.Black, this);

    console.log(this.cells);
  }
}

class ChessPiece {
  x;
  y;
  color;

  constructor(x, y, color, chessboard) {
    this.x = x;
    this.y = y;
    this.color = color;
    this.chessboard = chessboard;
    this.image = "image";
    this.chessboard.putPiece(x, y, this);
  }

  moveTo(x, y) {
    if (!this.canMoveTo(x, y)) {
      console.log("Cannot move to these coordinates");
      return;
    }
    this.chessboard.clearCell(this.x, this.y);
    this.x = x;
    this.y = y;
    const prevPiece = this.chessboard.putPiece(x, y, this);
    prevPiece?.die();
  }

  die() {
    this.chessboard.addDeadPiece(this);
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
    return !!this.getPossiblePaths().find((c) => c[0] === x && c[1] === y);
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
    ].filter((c) => {
      if (c[0] >= 0 && c[1] >= 0 && c[0] < 8 && c[1] < 8) {
        console.log(this.chessboard.getPiece(c[0], c[1]));

        console.log(this.chessboard.getPiece(c[0], c[1])?.color);
      }

      return (
        c[0] >= 0 &&
        c[1] >= 0 &&
        c[0] < 8 &&
        c[1] < 8 &&
        this.chessboard.getPiece(c[0], c[1])?.color !== this.color
      );
    });
  }
}

class Queen extends ChessPiece {
  canMoveTo(x, y) {
    return !!this.getPossiblePaths().find((c) => c[0] === x && c[1] === y);
  }

  getName() {
    return "Queen";
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
    ].filter((c) => {
      if (c[0] >= 0 && c[1] >= 0 && c[0] < 8 && c[1] < 8) {
        console.log(this.chessboard.getPiece(c[0], c[1]));

        console.log(this.chessboard.getPiece(c[0], c[1])?.color);
      }

      return (
        c[0] >= 0 &&
        c[1] >= 0 &&
        c[0] < 8 &&
        c[1] < 8 &&
        this.chessboard.getPiece(c[0], c[1])?.color !== this.color
      );
    });
  }
}

const chessboard = new Chessboard();

window.addEventListener("load", () => {
  chessboard.initializeBoard();
  chessboard.initializePieces();
});

function parentOrChildIs(element, id) {
  console.log(element);
  if (!element) {
    return false;
  }
  if (element.id == id) {
    return true;
  }
  return parentOrChildIs(element.parentNode, id);
}

window.addEventListener("click", (e) => {
  if (!parentOrChildIs(e.target, "chessboard")) {
    chessboard.clearSelection();
  }
});

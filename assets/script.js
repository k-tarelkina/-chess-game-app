const cells = [[], [], [], [], [], [], [], []];

const COLOR = {
  Black: "Black",
  White: "White",
};

const STATE = {
  Selected: "selected",
  HighlightedFree: "highlighted-free",
  HighlightedOccupied: "highlighted-occupied",
};

function initializeBoard() {
  const chessboard = document.getElementById("chessboard");

  if (!chessboard) {
    return;
  }

  for (let i = 7; i >= 0; i--) {
    for (let j = 0; j < 8; j++) {
      chessboard.appendChild(cells[i][j]);
    }
  }
}

function highlightSelectedCell(x, y) {
  cells[x][y].classList.add("selected");
}

function highlightCells(coordinates) {
  for (let c of coordinates) {
    cells[c[0]][c[1]].classList.add("highlighted-free"); // TODO change highlight depending on wether there is a piece
  }
}

function clearCellsHighlight() {
  for (let row of cells) {
    for (let element of row) {
      element.classList.remove("highlighted-free");
      element.classList.remove("selected");
    }
  }
}

function putPiece(x, y, pieceName, pieceColor) {
  cells[x][y].innerHTML =
    "<img class='piece-image' " + `src='${pieceName}_${pieceColor}.svg'>`;
}

function removePiece(x, y) {
  cells[x][y].innerHTML = "";
}

function addDeadPiece(pieceName, pieceColor) {
  const element = document.createElement("img");
  element.src = `${pieceName}_${pieceColor}.svg`;
  element.classList.add("dead-piece-image");
  document.getElementById("test").innerText = `${pieceName}_${pieceColor}.svg`;

  if (pieceColor == COLOR.White) {
    document.getElementById("whitePiecesContainer").append(element);
  } else {
    document.getElementById("blackPiecesContainer").append(element);
  }
}

for (let x = 7; x >= 0; x--) {
  for (let y = 0; y < 8; y++) {
    const element = document.createElement("div");

    element.addEventListener("click", () => {
      onCellClicked(x, y);
    });

    if ((x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1)) {
      element.classList.add("white");
    } else {
      element.classList.add("black");
    }

    cells[x].push(element);
  }
}

initializeBoard();

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
  cells[x][y].classList.add(STATE.Selected);
}

function highlightCells(coordinates) {
  for (let c of coordinates) {
    const element = cells[c[0]][c[1]];
    if (element.getElementsByTagName("img").length > 0) {
      element.classList.add(STATE.HighlightedOccupied);
    } else {
      element.classList.add(STATE.HighlightedFree);
    }
  }
}

function clearCellsHighlight() {
  for (let row of cells) {
    for (let element of row) {
      element.classList.remove(STATE.HighlightedOccupied);
      element.classList.remove(STATE.HighlightedFree);
      element.classList.remove(STATE.Selected);
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

  if (pieceColor == COLOR.White) {
    document.getElementById("whitePiecesContainer").append(element);
  } else {
    document.getElementById("blackPiecesContainer").append(element);
  }
}

function showMessage(message) {
  document.getElementById("message").innerText = message;
}

function clearMessage() {
  document.getElementById("message").innerText = "";
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

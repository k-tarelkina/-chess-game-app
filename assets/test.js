const cells = [[], [], [], [], [], [], [], []];

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

function onCellClicked(x, y) {}

function highlightCells() {}
function clearHighlightedCells() {}

function putPiece(x, y, pieceName, pieceColor) {}
function removePiece(x, y) {}

function addDeadPiece(pieceName, pieceColor) {}

document.getElementById("test").addEventListener("click", () => OnTest());

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

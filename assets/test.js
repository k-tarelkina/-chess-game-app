const cells = [[], [], [], [], [], [], [], []];

function testJsEmpty() {
  document.getElementById("test").innerText = "message";
}
function testJs(message) {
  document.getElementById("test").innerText = message;
}
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
  document.getElementById("test").innerText = "highlightCells";

  for (let c of coordinates) {
    cells[c[0]][c[1]].classList.add("highlighted-free"); // TODO change highlight depending on wether there is a piece
  }
}
function clearHighlightedCells() {}

function putPiece(x, y, pieceName, pieceColor) {
  cells[x][y].innerHTML =
    "<img class='piece-image' " + `src='${pieceName}_${pieceColor}.svg'>`;
}

function removePiece(x, y) {
  cells[x][y].innerText = "";
}

function addDeadPiece(pieceName, pieceColor) {}

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

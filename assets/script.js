function getPlotConfig(pointsCoordinates) {
  mapped = [];

  for (let i = 0; i < pointsCoordinates.length - 1; i++) {
    mapped.push({
      x: pointsCoordinates[i][0],
      y: pointsCoordinates[i][1],
    });
  }
  return {
    type: "scatter",
    data: {
      datasets: [
        {
          label: "Scatter Dataset",
          data: mapped,
          backgroundColor: "rgb(255, 99, 132)",
        },
      ],
    },
    options: {
      scales: {
        x: {
          type: "linear",
          position: "bottom",
        },
      },
    },
  };
}

function plotPoints(pointsCoordinates) {
  const ctx = document.getElementById("chart");

  new Chart(ctx, getPlotConfig(pointsCoordinates));
}

function setInput(input) {
  const fReader = new FileReader();

  fReader.readAsDataURL(input.files[0]);

  fReader.onloadend = (event) => {
    const image = document.getElementById("inputImage");
    image.src = event.target.result;
    result = window.pywebview.api
      .getPointsCoordinates(event.target.result)
      .then(plotPoints);
  };
}

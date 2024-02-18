#pragma once

#include <stdexcept>

enum Color
{
  Black,
  White,
};

enum CellState
{
  Selected,
  HighlightedFree,
  HighlightedOccupied,
};

const char *colorToString(Color c);
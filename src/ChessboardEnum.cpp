#include "ChessboardEnum.h"

const char *colorToString(Color c)
{
  switch (c)
  {
  case Color::Black:
    return "Black";
  case Color::White:
    return "White";
  default:
    throw std::invalid_argument("Unimplemented item");
  }
}
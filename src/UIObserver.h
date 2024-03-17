#pragma once

#include <string.h>

class UIObserver
{
public:
  virtual void onCellClicked(int x, int y) = 0;
  virtual void onUiReady() = 0;
  virtual void onStartGame() = 0;
  virtual void onStartGameOver() = 0;
  virtual void onAddWhitePiecesUser(const std::string &username) = 0;
  virtual void onAddBlackPiecesUser(const std::string &username) = 0;
};
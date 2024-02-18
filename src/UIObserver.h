#pragma once

class UIObserver
{
public:
  virtual void onCellClicked(int x, int y) = 0;
  virtual void onUiReady() = 0;
};
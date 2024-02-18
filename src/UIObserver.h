#pragma once

class UIObserver
{
public:
  virtual void onCellClicked(int x, int y) = 0;
};
#pragma once
#include <AppCore/AppCore.h>
#include <stdio.h>
#include <iostream>
#include "UI.h"
#include "Chessboard.h"

using namespace ultralight;

class MyApp : public AppListener,
              public WindowListener
{
public:
  MyApp();
  virtual ~MyApp();

  virtual void Run();
  virtual void OnClose(ultralight::Window *window) override;

protected:
  RefPtr<App> app_;
  std::unique_ptr<UI> ui_;
  RefPtr<Window> window_;
  Chessboard *chessboard_;
};
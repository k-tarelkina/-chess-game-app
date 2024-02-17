#pragma once
#include <AppCore/AppCore.h>
#include <stdio.h>
#include <iostream>
#include "UI.h"

using namespace ultralight;

class MyApp : public AppListener,
              public WindowListener,
              public LoadListener,
              public ViewListener
{
public:
  MyApp();

  virtual ~MyApp();

  // Start the run loop.
  virtual void Run();

  // This is called continuously from the app's main loop.
  // virtual void OnUpdate() override;

  // This is called when the window is closing.
  virtual void OnClose(ultralight::Window *window) override;

  // This is called whenever the window resizes.
  // virtual void OnResize(ultralight::Window *window, uint32_t width, uint32_t height) override;

  // // This is called when the page finishes a load in one of its frames.
  // virtual void OnFinishLoading(ultralight::View *caller,
  //                              uint64_t frame_id,
  //                              bool is_main_frame,
  //                              const String &url) override;

protected:
  RefPtr<App> app_;
  std::unique_ptr<UI> ui_;
  RefPtr<Window> window_;
  // RefPtr<Overlay> overlay_;
};
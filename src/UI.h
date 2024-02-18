
#pragma once
#include <AppCore/AppCore.h>
#include <stdio.h>
#include <iostream>

using ultralight::JSFunction;
using namespace ultralight;

class UI : public WindowListener,
           public LoadListener,
           public ViewListener
{
public:
  UI(RefPtr<Window> window);
  ~UI();

  virtual void OnDOMReady(ultralight::View *caller,
                          uint64_t frame_id,
                          bool is_main_frame,
                          const String &url) override;

  void OnTest(const JSObject &obj, const JSArgs &args);
  void OnResize(ultralight::Window *window, uint32_t width, uint32_t height);

protected:
  RefPtr<Window> window_;
  RefPtr<Overlay> overlay_;
  JSFunction testJs;
};
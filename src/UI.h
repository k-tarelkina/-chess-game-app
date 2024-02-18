
#pragma once

#include <AppCore/AppCore.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "UIObserver.h"

using ultralight::JSFunction;
using namespace ultralight;

class UI : public WindowListener,
           public LoadListener,
           public ViewListener
{
public:
  explicit UI(RefPtr<Window> window);
  ~UI();

  virtual void OnDOMReady(ultralight::View *caller,
                          uint64_t frame_id,
                          bool is_main_frame,
                          const String &url) override;

  void onCellClicked(const JSObject &obj, const JSArgs &args);
  void OnResize(ultralight::Window *window, uint32_t width, uint32_t height);
  RefPtr<View> view() { return overlay_->view(); }

  void attachObserver(UIObserver *observer);

protected:
  RefPtr<Window> window_;
  RefPtr<Overlay> overlay_;

private:
  std::vector<UIObserver *> uiObservers_;
};
#include "UI.h"

UI::UI(RefPtr<Window> window) : window_(window)
{
  overlay_ = Overlay::Create(window_, 1, 1, 0, 0);
  view()->LoadURL("file:///app.html");

  // Force view to resize to match the window
  OnResize(window_.get(), window_->width(), window_->height());

  view()->set_load_listener(this);
}

UI::~UI()
{
  view()->set_load_listener(nullptr);
  view()->set_view_listener(nullptr);
}

void UI::OnDOMReady(ultralight::View *caller,
                    uint64_t frame_id,
                    bool is_main_frame,
                    const String &url)
{
  std::cout << "OnDOMReady" << std::endl;

  RefPtr<JSContext> locked_context = view()->LockJSContext();
  SetJSContext(locked_context->ctx());

  JSObject global = JSGlobalObject();

  global["OnTest"] = BindJSCallback(&UI::OnTest);
}

void UI::OnTest(const JSObject &obj, const JSArgs &args)
{
  std::cout << "test" << std::endl;
  view()->EvaluateScript("testJs('Howdy!')");
}

void UI::OnResize(ultralight::Window *window, uint32_t width, uint32_t height)
{
  overlay_->Resize(width, height);
}
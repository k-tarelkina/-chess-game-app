#include "UI.h"

UI::UI(RefPtr<Window> window) : window_(window)
{

  overlay_ = Overlay::Create(window_, 1, 1, 0, 0);
  overlay_->view()->LoadURL("file:///app.html");

  OnResize(window_.get(), window_->width(), window_->height());

  ///
  /// Register our MyApp instance as a LoadListener so we can handle the
  /// View's OnFinishLoading and OnDOMReady events below.
  ///
  overlay_->view()->set_load_listener(this);

  ///
  /// Register our MyApp instance as a ViewListener so we can handle the
  /// View's OnChangeCursor and OnChangeTitle events below.
  ///
  overlay_->view()->set_view_listener(this);
}

UI::~UI()
{
  overlay_->view()->set_load_listener(nullptr);
  overlay_->view()->set_view_listener(nullptr);
}

void UI::OnDOMReady(ultralight::View *caller,
                    uint64_t frame_id,
                    bool is_main_frame,
                    const String &url)
{
  std::cout << "OnDOMReady" << std::endl;

  RefPtr<JSContext> locked_context = overlay_->view()->LockJSContext();
  SetJSContext(locked_context->ctx());

  JSObject global = JSGlobalObject();
  testJs = global["testJs"];
  std::cout << testJs.IsValid() << std::endl;

  global["OnTest"] = BindJSCallback(&UI::OnTest);
}

void UI::OnTest(const JSObject &obj, const JSArgs &args)
{
  std::cout << "test" << std::endl;
  overlay_->view()->EvaluateScript("testJs('Howdy!')");

  // JSValue arg = new JSValue("message");
  // RefPtr<JSContext> lock(overlay_->view()->LockJSContext());
  // testJs(new JSArgs(arg));
}

void UI::OnResize(ultralight::Window *window, uint32_t width, uint32_t height)
{
  /// We resize our overlay here to take up the entire window.
  overlay_->Resize(width, height);
}
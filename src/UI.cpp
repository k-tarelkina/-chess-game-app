#include "UI.h"

UI::UI(RefPtr<Window> window) : window_(window), uiObservers_(std::vector<UIObserver *>(0))
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

  global["onCellClicked"] = BindJSCallback(&UI::onCellClicked);

  for (auto observer : uiObservers_)
  {
    observer->onUiReady();
  }
}

void UI::OnResize(ultralight::Window *window, uint32_t width, uint32_t height)
{
  overlay_->Resize(width, height);
}

void UI::attachObserver(UIObserver *observer)
{
  uiObservers_.push_back(observer);
}

void UI::onCellClicked(const JSObject &obj, const JSArgs &args)
{
  std::cout << "test" << std::endl;

  std::cout << args[0].IsNumber() << std::endl;

  for (auto observer : uiObservers_)
  {
    observer->onCellClicked(args[0], args[1]);
  }

  view()->EvaluateScript("testJs('Howdy!')");
}

void UI::putPiece(int x, int y, const std::string &pieceName, Color color)
{
  std::string command = "putPiece(" +
                        std::to_string(x) + ", " +
                        std::to_string(y) + ", \"" +
                        pieceName + "\", \"" +
                        colorToString(color) + "\")";
  std::cout << command << std::endl;

  view()->EvaluateScript(command.c_str());
}
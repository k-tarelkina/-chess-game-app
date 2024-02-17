#include "MyApp.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

MyApp::MyApp()
{
  app_ = App::Create();

  window_ = Window::Create(app_->main_monitor(), WINDOW_WIDTH, WINDOW_HEIGHT,
                           false, kWindowFlags_Titled | kWindowFlags_Resizable);

  /// OnUpdate
  app_->set_listener(this);

  // Create the UI
  ui_.reset(new UI(window_));
  /// OnResize
  window_->set_listener(ui_.get());
}

MyApp::~MyApp()
{
  ui_.reset();
}

void MyApp::Run()
{
  app_->Run();
}

void MyApp::OnClose(ultralight::Window *window)
{
  app_->Quit();
}

// void MyApp::OnChangeCursor(ultralight::View *caller,
//                            Cursor cursor)
// {
//   ///
//   /// This is called whenever the page requests to change the cursor.
//   ///
//   /// We update the main window's cursor here.
//   ///
//   window_->SetCursor(cursor);
// }

// void MyApp::OnChangeTitle(ultralight::View *caller,
//                           const String &title)
// {
//   ///
//   /// This is called whenever the page requests to change the title.
//   ///
//   /// We update the main window's title here.
//   ///
//   window_->SetTitle(title.utf8().data());
// }

#include "MyApp.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

MyApp::MyApp() : app_(App::Create())
{
  window_ = Window::Create(app_->main_monitor(), WINDOW_WIDTH, WINDOW_HEIGHT,
                           false, kWindowFlags_Titled | kWindowFlags_Resizable);

  // OnUpdate
  app_->set_listener(this);

  // Create the UI
  ui_.reset(new UI(window_));
  // OnResize
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

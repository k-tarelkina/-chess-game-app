
#pragma once

#include <AppCore/AppCore.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

#include "UIObserver.h"
#include "ChessboardEnum.h"
#include "ChessCustomTypes.h"

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
  void OnResize(ultralight::Window *window, uint32_t width, uint32_t height);

  void onCellClicked(const JSObject &obj, const JSArgs &args);
  void onStartGameOver(const JSObject &obj, const JSArgs &args);
  void onAddWhitePiecesUser(const JSObject &obj, const JSArgs &args);
  void onAddBlackPiecesUser(const JSObject &obj, const JSArgs &args);

  void attachObserver(UIObserver *observer);

  void putPiece(int x, int y, const std::string &pieceName, Color color);
  void removePiece(int x, int y);
  void clearCellsHighlight();
  void addDeadPiece(const std::string &pieceName, Color color);
  void highlightSelectedCell(int x, int y);
  void highlightCells(const std::vector<Coordinates> &coordinates);
  void showMessage(const std::string &message);
  void clearMessage();

  void enableStartGameOverButton();
  void disableStartGameOverButton();
  void clearBoard();
  void clearUserNames();

protected:
  RefPtr<Window> window_;
  RefPtr<Overlay> overlay_;

private:
  std::vector<UIObserver *> uiObservers_;
  RefPtr<View> view() { return overlay_->view(); }
};
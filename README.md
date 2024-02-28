# Chess Game App

## Set up & Run

### 1. Install the Prerequisites

Before you build and run, you'll need to [install the prerequisites](https://docs.ultralig.ht/docs/installing-prerequisites) for your platform.

### 2. Build the app

To build the app, run the following commands:

```shell
rm -rf build
cmake -B build
cmake --build build --config Release
```

### 3. Run the app

#### On macOS and Linux

Navigate to `ultralight-quick-start/build` and run `MyApp` to launch the program.

#### On Windows

Navigate to `ultralight-quick-start/build/Release` and run `MyApp` to launch the program.

_Note:_ on macOS and Linux you can use the following script to **build and run the app in one line**:

```
./start.sh
```

## Architecture

### 1. Project structure

UI is written in HTML, CSS and JavaScript. All files related to the UI are placed inside `assets` folder.

Game logic is written in C++, all related files are in `src` folder.

_Note:_ if you add any new C++ files, make sure to list them in `CMakeLists.txt` sources:

```
set(SOURCES "src/MyApp.h"
            "src/MyApp.cpp"
            // ...
)
```

### 2. Communication between front-end and back-end

The class used for frontend-backend communication is `UI` (`src/UI.h` and `src/UI.cpp`).

All JS scripts are placed in one file `assets/script.js`.

#### Envoke C++ event from JS

JS:

```js
element.addEventListener("click", () => {
  onCellClicked(x, y);
});
```

C++:

```cpp
class UIObserver
{
public:
  virtual void onCellClicked(int x, int y) = 0;
}

// UI class
void UI::OnDOMReady(ultralight::View *caller,
                    uint64_t frame_id,
                    bool is_main_frame,
                    const String &url)
{
  // ...
  global["onCellClicked"] = BindJSCallback(&UI::onCellClicked);
}

void UI::onCellClicked(const JSObject &obj, const JSArgs &args)
{
  for (auto observer : uiObservers_)
  {
    observer->onCellClicked(args[0], args[1]);
  }
}
```

`UI` class communicates the event to all the subscribed observers.

- **Create a new observer?** To create a new observer, implement a `UIObserver` interface and attach a new observer to `UI` using `void attachObserver(UIObserver *observer)` method. In general you **do not** need to do it, as `Chessboard` class is the only observer in the app.

- **Create a new event?** If you need to add new events, just add a new method to `UIObserver` interface and implement it in derived classes.

#### Call JS function from C++

JS:

```js
function test(value) {
  document.getElementById("id").innerText = value;
}
```

C++:

```cpp
void UI::clearMessage()
{
  view()->EvaluateScript("test('Hello World')");
}
```

### 3. Main components

#### UI class

Responsible for UI-backend communication. For more details see Section 2.

#### Chessboard class

The "manager" of the game. Is responsible for moving pieces, determining check criteria and updating UI.

#### ChessPiece class

Base class for all chess pieces. Each chess piece should implement its own rules of choosing the path.

`getAllPaths()` method must be implemented in each child class and should return all possible coordinates that the piece can reach from its current cell.

## Further Reading

Initial repo used to create this project:

```
git clone https://github.com/ultralight-ux/ultralight-quick-start
```

Follow the [Writing Your First App](https://docs.ultralig.ht/docs/writing-your-first-app) guide and other tutorials in the documentation for more info.

## TODO

- Add possibility to start game over (add button on UI + corresponding functionality)
- Add timer (reset on each turn)
- Add possibility to enter user names at the beginning of each game
- Add possibility to save current game and return to it later
- Add web server to connect to the same game from different computers

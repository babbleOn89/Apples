Thanks for checking out Apples!

A small C++/raylib arcade game where you catch falling apples before time runs out.

## Features
- Falling apples
- Score + high score saving
- Timer system
- Background music + sound effects
- Restart system
- Player movement + collision

## Screenshots
![Gameplay Screenshot](Screenshot1.png)
![Gameplay Screenshot](Screenshot2.png)

# Apple Catcher

A simple 2D apple-catching game made in C++ using raylib.

This project was created as part of my journey learning:
- C++
- raylib
- game loops
- collision detection
- object-oriented programming
- Linux terminal workflows
- Neovim

The game currently features:
- Red apples (+1 score)
- Green apples (+2 score)
- Rotten apples (-1 score)
- Score tracking
- High score saving
- Music and sound support
- Restart functionality

---

## Screenshot

![Gameplay Screenshot](Screenshot1.png)

![Gameplay Screenshot](Screenshot2.png)

---

## Controls

| Key | Action |
|---|---|
| Left Arrow | Move Left |
| Right Arrow | Move Right |
| ESC | Quit |

---

## Download and Run

### Linux

Make sure `g++` and `raylib` are installed.
Compile:
```bash
g++ main.cpp game.cpp apple.cpp player.cpp tree.cpp -o apples -lraylib
## Run With
./apples

### Windows

Install:
- MinGW-w64 or MSYS2
- raylib
- Download the full project from this repository
Compile:
```bash
g++ main.cpp game.cpp apple.cpp player.cpp tree.cpp -o apples.exe -lraylib
```
Run:
```bash
./apples.exe
```

### macOS

Install:
- Xcode Command Line Tools
- Homebrew
- raylib
Install raylib:
```bash
brew install raylib
```
Compile:
```bash
g++ main.cpp game.cpp apple.cpp player.cpp tree.cpp -o apples -lraylib
```
Run:
```bash
./apples
```

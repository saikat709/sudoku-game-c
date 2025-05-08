## Commands 

We can use either gcc or g++ for a .c file.  must use g++ to compile .cpp code..

## Files in the root dir
```bash
g++ solve-sudoku.cpp && ./a.out
g++ check-terminal-command.c && ./a.out
g++ sudoku-generator.cpp && ./a.out

```

## Terminal Game 
```bash
cd terminal-game
g++ main.cpp sudoku.cpp && ./a.out
// or
g++ *.cpp && ./a.out

```


## Gui Game using sdl

```bash
// make sure sdl2 is installed on your system. to install
sudo apt install sdl2-dev

// After that
cd gui-game-sdl
g++ main.cpp comp/*.cpp -lsdl2 && ./a.out

// or
shopt -s globstar # Enable globstar for recursive globbing
g++ *.cpp **/*.cpp -lncurses && ./a.out

// Alternatively, explicitly list subdirectories:
g++ *.cpp comp/*.cpp -lncurses && ./a.out

```

# This direcotry contains file and structure for setting up a sdl c++ project and compilation command

# Command to compile and run
```bash
g++ -std=c++17 main.cpp lib/*.cpp -Iincludes -lSDL2 -lSDL2main -lSDL2_ttf -o game
```

For MingW on windows:
```bash
g++ main.cpp lib/*.cpp -Iincludes -IC:/SDL2/include -LC:/SDL2/lib -lC:/SDL2_ttf -lmingw32 -lSDL2main -lSDL2 -o game.exe
```


## installations
```bash
sudo apt-get install libsdl-ttf2.0-dev
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

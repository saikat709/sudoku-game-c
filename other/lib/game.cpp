#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"
using namespace std;


Game::Game(){
    SDL_Init(SDL_INIT_VIDEO);
    this->window = SDL_CreateWindow("Sudoku Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    } else {
        SDL_Delay(5000); // Show the window for 2 seconds
        SDL_DestroyWindow(window);
    }
    cout << "Game constructor called" << endl;
}

Game::~Game(){
    SDL_Quit();
    cout << "Game destructor called" << endl;
}


void Game::render(){
    while( 1 ){
        SDL_RenderClear(renderer);
        // Render game objects here
        SDL_RenderPresent(renderer);
    }
}

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game {

    public:
        Game();
        ~Game();
        
        void init();
        void render();
    
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool running;
};
#endif
#include <stdio.h>
//#include </usr/include/SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <stdio.h>


// Compiler options: -lSDL2 -lSDL2main
// Command line:  gcc main.c -lSDL2 -lSDL2main -o main

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Рисование линии", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Белый цвет фона
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Красный цвет линии
    SDL_RenderDrawLine(renderer, 100, 100, 700, 500);

    SDL_RenderPresent(renderer);

    SDL_Delay(5000); // Задержка на 5 секунд

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
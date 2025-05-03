#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL2/SDL.h>
#include <SDL3/SDL_main.h>
#include <time.h>
#define _TTT_GAME_WINDOW_SIZE 600
#define SQUARES_IN_LINE 3
const int SQUARE_SIZE = _TTT_GAME_WINDOW_SIZE / SQUARES_IN_LINE;

// Compiler options: -lSDL3
int main(int argc, char *argv[]) {
    const int GAME_WINDOW_SIZE = _TTT_GAME_WINDOW_SIZE;
    printf("Hello World!\n");
    int flags[] = {SDL_WINDOW_OCCLUDED, SDL_WINDOW_METAL, SDL_WINDOW_MOUSE_FOCUS};
    int *f = &flags;
    SDL_Window *window = SDL_CreateWindow("Hello SDL3", GAME_WINDOW_SIZE, GAME_WINDOW_SIZE, SDL_WINDOW_OCCLUDED);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_UpdateWindowSurface(window);
    SDL_Rect rect = {0, 0, screenSurface->w, screenSurface->h};
    Uint32 color = 0xf0dc82;
    SDL_FillSurfaceRect(screenSurface, &rect, color);
    SDL_SetRenderDrawColor(renderer, 255, 203, 92, SDL_ALPHA_TRANSPARENT);
    SDL_RenderRect(renderer, NULL);
    SDL_RenderClear(renderer);
    SDL_UpdateWindowSurface(window);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0,SDL_ALPHA_TRANSPARENT); // Красный цвет линии
    for (float i = SQUARE_SIZE; i < GAME_WINDOW_SIZE; i+= SQUARE_SIZE) {
        bool vertical = SDL_RenderLine(renderer, i, 0, i, _TTT_GAME_WINDOW_SIZE);
        bool horizontal = SDL_RenderLine(renderer, 0, i, _TTT_GAME_WINDOW_SIZE, i);
    }

    SDL_RenderPresent(renderer);
    SDL_GetError();

    SDL_UpdateWindowSurface(screenSurface);
    SDL_Event event;
    while (1) {
        //if (!SDL_PollEvent(&event)) continue;
        SDL_WaitEvent(&event);
        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                float x_coord = event.button.x;
                float y_coord = event.button.y;
                printf("%s %f %f\n", "Левая кнопка мыши нажата:", x_coord, y_coord);
            }
        }
        //if (event.type == SDL_EVENT_MOUSE_MOTION) printf("Mouse moved\n");
    }
}

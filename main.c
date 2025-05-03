#include <stdio.h>
//#include </usr/include/SDL2/SDL.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <time.h>

// Compiler options: -lSDL3

void SDL_FillRect_renamed_SDL_FillSurfaceRect(SDL_Surface * sdl_surface, void * p, Uint32 uint32);

int main(int argc, char *argv[]) {
    printf("Hello World!\n");
    int flags[] = {SDL_WINDOW_OCCLUDED, SDL_WINDOW_METAL, SDL_WINDOW_MOUSE_FOCUS};
    int *f = &flags;
    SDL_Window *window = SDL_CreateWindow("Hello SDL3", 300, 600, *f);
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {0, 0, screenSurface->w, screenSurface->h};
    Uint32 color = 220898888;
    SDL_FillSurfaceRect(screenSurface, &rect, color);
    SDL_UpdateWindowSurface(window);
    SDL_Event event;
    while (1) {
        SDL_WaitEvent(&event);
        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                float x_coord = event.button.x;
                float y_coord = event.button.y;
                printf("%s %f %f\n", "Левая кнопка мыши нажата:", x_coord, y_coord);
            }
        }
        if (event.type == SDL_EVENT_MOUSE_MOTION) printf("Mouse moved\n");
    }

}

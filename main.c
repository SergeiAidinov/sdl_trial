#include <stdio.h>
//#include </usr/include/SDL2/SDL.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


// Compiler options: -lSDL2 -lSDL2main
// Command line:  gcc main.c -lSDL2 -lSDL2main -o main

int main(int argc, char *argv[]) {
    printf("Hello World!\n");
    //SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Hello SDL3", 300, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, "qq");
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);
    SDL_Event event;
    while (1) {
        SDL_WaitEvent(&event);
        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                printf("Левая кнопка мыши нажата\n");
            }
        }
        if (event.type == SDL_EVENT_MOUSE_MOTION)

                printf("Mouse moved\n");

        }
       // if (event.type != SDL_EVENT_FIRST) printf("Event: %d\n", event.type);


    //SDL_SetRenderDrawColor(renderer, 255, 0, 0, 1); // Красный цвет линии
    //SDL_RenderLine(renderer, 100, 100, 300, 200);
    //SDL_RenderClear(renderer);

    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1); // Белый цвет фона
    //SDL_RenderClear(renderer);

    //SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Красный цвет линии
    //SDL_RenderDrawLine(renderer, 100, 100, 700, 500);

    //SDL_RenderPresent(renderer);

    SDL_Delay(5000);

    //SDL_DestroyRenderer(renderer);
    //SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

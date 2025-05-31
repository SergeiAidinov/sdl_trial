#include <stdio.h>
#include <SDL3/SDL.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
#define _TTT_GAME_WINDOW_SIZE 600
#define SQUARES_IN_LINE 3
struct color_rgb {
    int red, green, blue;
};
struct color_rgb background_color = {240, 220, 130};
const int SQUARE_SIZE = _TTT_GAME_WINDOW_SIZE / SQUARES_IN_LINE;

// Compiler options: -lSDL3

SDL_FRect createFRect(int x, int y, int width, int height);

int main(int argc, char *argv[]) {
    printf("Hello World!\n");
    SDL_Window *window = SDL_CreateWindow("Hello SDL3", _TTT_GAME_WINDOW_SIZE, _TTT_GAME_WINDOW_SIZE, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderDrawColor(renderer, background_color.red, background_color.green, background_color.blue, 0);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Surface *car = SDL_LoadBMP("/home/sergei/CLionProjects/sdl_trial/resources/cross.bmp");
    SDL_Surface *plane = SDL_LoadBMP("/home/sergei/CLionProjects/sdl_trial/resources/nought.bmp");
    SDL_Texture *car_texture = SDL_CreateTextureFromSurface(renderer, car);
    SDL_Texture *plane_texture = SDL_CreateTextureFromSurface(renderer, plane);
    SDL_FRect car_frect = createFRect(0, 0, SQUARE_SIZE, SQUARE_SIZE);
    SDL_FRect plane_frect = createFRect(SQUARE_SIZE + 1, SQUARE_SIZE + 1, SQUARE_SIZE, SQUARE_SIZE);
    SDL_RenderTexture(renderer, car_texture, NULL, &car_frect);
    SDL_RenderTexture(renderer, plane_texture, NULL, &plane_frect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0,SDL_ALPHA_TRANSPARENT); // Красный цвет линии
    for (float i = SQUARE_SIZE; i < _TTT_GAME_WINDOW_SIZE; i+= SQUARE_SIZE) {
        SDL_RenderLine(renderer, i, 0, i, _TTT_GAME_WINDOW_SIZE);
        SDL_RenderLine(renderer, 0, i, _TTT_GAME_WINDOW_SIZE, i);
    }
    SDL_RenderPresent(renderer);
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
        //if (event.type == SDL_EVENT_MOUSE_MOTION) printf("Mouse moved\n");
    }
}

SDL_FRect createFRect(int x, int y, int width, int height) {
    SDL_FRect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    return rect;
}

#include <iostream>
#include "SDL.h"

const int WIDTH = 450, HEIGHT = 400;

void SDL_DrawCircle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if (NULL == window)
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    if (NULL == renderer)
    {
        std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_DrawCircle(renderer, 430, 250, 200);
    SDL_DrawCircle(renderer, 320, 250, 45);
    SDL_DrawCircle(renderer, 470, 270, 45);

    SDL_RenderDrawLine(renderer, 360, 140, 280, 40);
    SDL_RenderDrawLine(renderer, 280, 40, 210, 90);

    SDL_RenderDrawLine(renderer, 520, 140, 560, 40);
    SDL_RenderDrawLine(renderer, 560, 40, 620, 80);

    SDL_RenderDrawLine(renderer, 290, 350, 372, 410);
    SDL_RenderDrawLine(renderer, 372, 410, 490, 400);

    SDL_RenderPresent(renderer);

    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (SDL_QUIT == windowEvent.type)
            {
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
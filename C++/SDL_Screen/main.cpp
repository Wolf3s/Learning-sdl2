/******************************************************
*******************************************************
** Copyright(c) 2022 André Guilherme                 **
** Made with C++ and SDL2                            **
**                                                   **
** Description: It just shows a white screen         **
**                                                   **
*******************************************************
*******************************************************/

#include <SDL/SDL.h>
#include <iostream>

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char* argv[])
{
  SDL_Window *window;
  SDL_Surface *surface;

  int ret = SDL_Init(SDL_INIT_EVERYTHING);
  if(ret)
  {
    std::cout << "Could not initialize SDL" << SDL_GetError();
  }

  window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  surface = SDL_GetWindowSurface(window);

  if (window)
  {
    std::cout << "Starting ";
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(5000);
    SDL_Quit();
  }

  else
  {
    std::cout << "Error";
  }
  return 0;
}

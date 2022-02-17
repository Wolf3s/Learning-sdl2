/******************************************************
*******************************************************
** Copyright André Guilherme Mendes Da Luz Bastos    **
** Made with C++ 20 and tested on code::blocks 20.03 **
**                                                   **
** Description of the example: It just shows a white **
** screen                                            **
**                                                   **
*******************************************************
*******************************************************/

#include <SDL.h>
#include <iostream>

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char* args[])
{
  SDL_Window *window;

  SDL_Surface *surface;

  //SDL1 Old Function
  // window = SDL_SetVideoMode(WIDTH, HEIGHT, BITS, SDL_RWSURFACE);

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
    return 0;
  }
}

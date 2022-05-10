/******************************************************
*******************************************************
** Copyright André Guilherme Mendes da Luz Bastos    **
** Made with C++ and SDL2                            **
** Description: SDL2 Console hello world             **
*******************************************************
*******************************************************/

//iostream and sdl libraries
#include <SDL/SDL.h>
#include <iostream>

//Normal main declaration
int main(int argv, char* args[])
{
  std::cout << "Initializing console";
  SDL_Init(SDL_INIT_EVERYTHING);
  std::cout << "\nExiting";
  SDL_Delay(6000);
  SDL_Quit();
  return 0;
}

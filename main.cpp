/******************************************************
** SDL2 Console message                              **
** Copyright André Guilherme Mendes da Luz Bastos    **
** Made with C++ 20 and tested on code::blocks 20.03 **
*******************************************************/

//iostream and sdl libraries
#include <SDL.h>
#include <iostream>

//Definitions of screen
#define WIDTH 640
#define HEIGHT 480

//Normal main declaration
int main(int argv, char* args[])
{
  std::cout << "init video";
  //inits video and then creates the screen
  SDL_Init( SDL_INIT_VIDEO );
  SDL_CreateWindow("Init", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOWEVENT);
  std::cout << "\nExiting";
  //exits
  SDL_Quit();
  return 0;
}



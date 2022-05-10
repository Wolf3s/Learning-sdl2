/*******************************************************
********************************************************
** Copyright Andr� Guilherme Mendes da Luz Bastos    **
** Rewritten in C and SDL2                            **
** Description: It just shows a white screen          **
********************************************************
********************************************************/

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define WIDTH 640
#define HEIGHT 448

SDL_Window* window;
SDL_Surface* surface;

int main(int args, char* argv[])
{
	bool success;
	int ret = SDL_Init(SDL_INIT_EVERYTHING);
	if(ret)
	{	
		printf("could not initialize SDL2 %s\n", SDL_GetError);
		return success = false;
	}

	window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	
	surface = SDL_GetWindowSurface(window);

	if(window)
	{
		SDL_UpdateWindowSurface(window);
		SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
		SDL_Delay(1000);
		SDL_Quit();
	}
	
	else
	{
		printf("could not start window %s\n", SDL_GetError);
		return success = false;
	}
	return 0;
}
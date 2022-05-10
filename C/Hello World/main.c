/*******************************************************
********************************************************
** Copyright Andr� Guilherme Mendes da Luz Bastos     **
** Rewritten in C and SDL2                            **
** Description: Hello world console                   **
********************************************************
********************************************************/

#include <stdio.h>
#include <SDL/SDL.h>

int main(int args, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	printf("initializing sdl");
	SDL_Delay(1000);
	SDL_Quit();
	printf("Exiting");
	return 0;
}
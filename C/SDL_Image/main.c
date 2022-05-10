/*******************************************************
********************************************************
** Copyright Andr� Guilherme Mendes da Luz Bastos     **
** Rewritten in C and SDL2                            **
** Description: Loads a bmp image                     **
********************************************************
********************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <SDL/SDL.h>

#define WIDTH 640
#define HEIGHT 448

SDL_Window* window;
SDL_Surface* surface;
SDL_Surface* image;
bool success;

bool create_screen()
{
	//init everything
	int ret = SDL_Init(SDL_INIT_EVERYTHING);
	if(ret)
	{
		printf("Could not start SDL", SDL_GetError);
		return success = false;
	}
	//creates a window 
	window = SDL_CreateWindow("SDL_Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	return success;
}


bool load_image()
{
	image = SDL_LoadBMP("hello_world.bmp");
	if(image == NULL)
	{
		printf("could not load the image %s\n", SDL_GetError);
		return success = false;
	}
	return success;
}


void shutdown()
{
	SDL_FreeSurface(image);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


int main(int args, char* argv[])
{
   if(create_screen())
   {
	   printf("could not load the screen %s \n", SDL_GetError());
   }
   else
   {
	   if(load_image())
	   {
		   printf("could not load the image %s \n", SDL_GetError);
	   }
	    SDL_BlitSurface(image, NULL, surface, NULL);
	    SDL_UpdateWindowSurface(window);
	    SDL_Delay(6000);
   }  
   shutdown();  
   return 0;
}


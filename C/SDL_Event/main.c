/***************************************************
****************************************************
** Copyright Andr� Guilherme Mendes da Luz Bastos **
** Rewritten with C and SDL2                      **
** Description: Loops an event using SDL_Event    **
****************************************************
****************************************************/

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define WIDTH 640
#define HEIGHT 448

SDL_Window* window;
SDL_Surface* surface;
SDL_Surface* image;

bool success;

bool load_screen()
{
	int ret;
	ret = SDL_Init(SDL_INIT_EVERYTHING);
	if(ret < 0)
	{
		printf("could not load SDL2 %s\n", SDL_GetError);
	}
	window = SDL_CreateWindow("SDL_Event", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (window)
	{
		surface = SDL_GetWindowSurface(window);
	}
	return success;
}

bool load_image()
{
	image = SDL_LoadBMP("hello_world.bmp");
	if(image)
	{
		printf("image loaded");
	}
	return success;
}

void close()
{
	SDL_DestroyWindow(window);
	SDL_FreeSurface(surface);
	SDL_Quit();
}

int main(int args, char* argv[])
{
   if(load_screen())
   {
	   printf("could not load screen %s\n", SDL_GetError());
   }
   else
   {
         if(load_image())
	 {
            printf("could not load the image %s\n", SDL_GetError);
	 }
	 
	 bool quit = false;
	 while(!quit)
	 {
	   SDL_Event event;
	   while(SDL_PollEvent(&event) != 0)
	   {
		  if (event.type == SDL_QUIT)
		  {
		    quit = true;
		  }		 
		  SDL_BlitSurface(image, NULL, surface, NULL);
		  SDL_UpdateWindowSurface(window);
		  SDL_Delay(9000);
	   }		 
	 }
   }
   close();
   return 0;
}

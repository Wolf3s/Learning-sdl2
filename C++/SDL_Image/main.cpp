/***************************************************
****************************************************
** Copyright Andr� Guilherme Mendes da Luz Bastos**
** Made with C++ and SDL2                        **
** Description: Loads a bmp image                 **
****************************************************
****************************************************/

#include <SDL/SDL.h>
#include <iostream>

#define WIDTH 640
#define HEIGHT 480

SDL_Window* window;
SDL_Surface* surface;
SDL_Surface* image;
bool success;

bool initialize_screen()
{
	int ret = SDL_Init(SDL_INIT_EVERYTHING);	
	if(ret)
	{
		std::cout << "could not start SDL: " << SDL_GetError();
		return success = false;
	}

	window = SDL_CreateWindow("SDL_Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	return success;
}

bool loadmedia()
{
	image = SDL_LoadBMP("hello_world.bmp");
	if(image == NULL)
	{
		std::cout << "failed to load a image: " << SDL_GetError();
		return success = false;
	}
	return success;
}

void close(void)
{
	SDL_FreeSurface(image);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int args, char* argv[])
{
	if(initialize_screen())
	{
		std::cout << "Failed to init screen";
	}
	
	else
	{
		if(loadmedia())
		{
			std::cout << "could not load the media";
		}
		SDL_BlitSurface(image, NULL, surface, NULL);
		SDL_UpdateWindowSurface(window);
		SDL_Delay(1000);
	}
	close();
	return 0;
}

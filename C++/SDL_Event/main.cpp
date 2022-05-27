/***************************************************
****************************************************
** Copyright Andr� Guilherme Mendes da Luz Bastos **
** Written with C++ and SDL2                      **
** Description: Loops an event using SDL_Event    **
****************************************************
****************************************************/

#include <SDL/SDL.h>
#include <iostream>

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
       std::cout << "could not load SDL2";
   }
   window =	SDL_CreateWindow("SDL_Event", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
   if(window)
   {
       surface = SDL_GetWindowSurface(window);
       
   }
   else
   {
       std::cout << "could not load the screen";
       return success = false;
   }
 
   return success;
}

bool load_img()
{
  image = SDL_LoadBMP("hello_world.bmp");
  if(image)
  {
      std::cout << "Loaded the bmp";
  }
  return success;
}

void close()
{
    SDL_DestroyWindow(window);
    SDL_FreeSurface(image);
    SDL_Quit();
}

int main(int args, char* argv[])
{
     if(load_screen())
     {
         std::cout << "could not load the whole thing";
     }
     else
     {
        if(load_img())
        {
            std::cout << "Could not load the image";
        }
        bool quit = false;
        
        while(!quit)
        {
            SDL_Event event; //event  
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
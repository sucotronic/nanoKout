#include "SDL.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SCREEN_DEPTH 8
#define FPS 40

int main(int argc, char *argv[]) {
     // Main loop
     Uint32 waittime = 1000.0f/FPS;
    Uint32 framestarttime = 0;
    Sint32 delaytime;
     SDL_Event event;
     SDL_Surface *screen;
     Uint8       *p;
     int         x = 10; //x coordinate of our pixel
     int         y = 20; //y coordinate of our pixel
     
     /* Initialize SDL */
     SDL_Init(SDL_INIT_VIDEO);
     
     /* Initialize the screen / window */
     screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, SDL_SWSURFACE);
     
     /* Make p point to the place we want to draw the pixel */
     p = (Uint8 *)screen->pixels + y * screen->pitch + x * screen->format->BytesPerPixel;
     
     /* Draw the pixel! */
     *p=0xff;
     
     /* update the screen (aka double buffering) */
     SDL_Flip(screen);
     while(1){
         if (SDL_PollEvent(&event))
         {
             // Check for the quit message
	         if (event.type == SDL_QUIT)
	         {
	           // Quit the program
	           break;
	         }
	         if (event.type == SDL_KEYDOWN)
	         {
	            switch(event.key.keysym.sym) {
	                case SDLK_UP:
	                    y++;
	                    break;
	                case SDLK_DOWN:
	                    y--;
	                    break;
	                case SDLK_LEFT:
	                    x--;
	                    break;
	                case SDLK_RIGHT:
	                    x++;
	                    break;
	            }
	            p = (Uint8 *)screen->pixels + y * screen->pitch + x * screen->format->BytesPerPixel;
	            *p=0xff;
	         }
	     }
	    SDL_Flip(screen);
	    delaytime = waittime - (SDL_GetTicks() - framestarttime);
        if(delaytime > 0)
            SDL_Delay((Uint32)delaytime);
        framestarttime = SDL_GetTicks();
     }

}

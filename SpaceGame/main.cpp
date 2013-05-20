#ifdef OS_WINDOWS
    #include "SDL.h"
#else
    #include <SDL/SDL.h>
#endif

int main( int argc, char* args[] )
{
    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );


    //Quit SDL
    SDL_Quit();

    return 0;
}

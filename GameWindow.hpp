#ifndef WINDOW_HEADER
#define WINDOW_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class GameWindow 
{
	private:
		int width;
		int height;
		bool quit = false;

		Uint8 red= 0xFF;
		Uint8 green = 0xFF;
		Uint8 blue = 0xFF;
		Uint8 alpha = 0xFF;

		SDL_Window* win;
		SDL_Renderer* ren;
		SDL_Event e;

		int SendError(const char* type);
		int HandleEvents(bool events(SDL_Window* win, SDL_Renderer* ren)); 


	public:
		int InitWindow(const char* title, int width, int height);
		void runWindow(bool sequence(SDL_Window* win, SDL_Renderer* ren), bool events(SDL_Window* win, SDL_Renderer* ren));
		void QuitWindow();

		void setBackgroundColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
};

#endif

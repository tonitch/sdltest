#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Character{
	private:	
		int x, y; 
		int w, h; 

		bool player;
		SDL_Texture* avatar = nullptr;
		SDL_Renderer* ren;
	public:
		Character(SDL_Renderer* iren);
		Character(SDL_Renderer* iren, const char* avatar);
		void render();
		void keyIO(SDL_Event* e);

		void moveUp(int dist);
		void moveDown(int dist);
		void moveRight(int dist);
		void moveLeft(int dist);
		
		SDL_Rect getPlayerRect();
};

#endif

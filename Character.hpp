#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Vector2.hpp"

class Character{
	private:	
		void init(SDL_Renderer* iren);

		Vector2 direction;
		Vector2 velocity;
		Vector2 position;
		int w, h; 
		int speed;

		SDL_Texture* avatar = nullptr;
		SDL_Renderer* ren;
	public:
		Character(SDL_Renderer* iren);
		Character(SDL_Renderer* iren, const char* avatar);

		void render();
		void keyIO(SDL_Event* e);

		void moveUp();
		void moveDown();
		void moveRight();
		void moveLeft();

		void updateVelocity();
		void updatePosition();
		
		SDL_Rect getPlayerRect();
};

#endif

#include "GameWindow.hpp"

bool event(SDL_Window* win, SDL_Renderer* ren){
	return 0;
}

bool draw(SDL_Window* win, SDL_Renderer* ren){
	SDL_Texture* img = IMG_LoadTexture(ren, "tonitch.png");
	SDL_Rect dstrect;
	dstrect.x = 0;
	dstrect.y = 0;
	dstrect.w = 50;
	dstrect.h = 50;
	SDL_RenderCopy(ren, img, NULL, &dstrect);
	return 0;
}

int main(void){
	GameWindow Gwin;
	if(Gwin.InitWindow("test", 750,750)){
		return 1;
	}
	Gwin.runWindow(draw, event);
}

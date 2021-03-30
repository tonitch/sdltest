#include "GameWindow.hpp"
#include <iostream>
#include <math.h>

bool drawFirstRun = true;
SDL_Texture* img;
double i = 0;

bool event(SDL_Window* win, SDL_Renderer* ren){
	return 0;
}

bool draw(SDL_Window* win, SDL_Renderer* ren){
	if(drawFirstRun){
		drawFirstRun = false;
		img = IMG_LoadTexture(ren, "tonitch.png");
	}
	i = i + 0.05;
	SDL_Rect dstrect;
	dstrect.x = sin(i) * 200 + 400;
	dstrect.y = cos(i) * 200 + 400;
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

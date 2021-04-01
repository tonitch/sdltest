#include "GameWindow.hpp"
#include <iostream>
#include <math.h>

bool drawFirstRun = true;
SDL_Texture* img;
SDL_Rect fillRect;
SDL_Rect OutlineRect;


bool event(GameWindow* GW){
	return 0;
}

bool draw(GameWindow* GW){
	if(drawFirstRun){
		drawFirstRun = false;
		img = IMG_LoadTexture(GW->getRenderer(), "tonitch.png");
		fillRect = {GW->getWidth()/4,GW->getHeight()/4, GW->getWidth()/2, GW->getHeight()/2 };
		OutlineRect = {GW->getWidth()/6,GW->getHeight()/6, GW->getWidth()*2/3, GW->getHeight()*2/3 };
	}
	SDL_RenderCopy(GW->getRenderer(), img, NULL, NULL);
	SDL_SetRenderDrawColor(GW->getRenderer(), 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(GW->getRenderer(), &fillRect);
	SDL_SetRenderDrawColor(GW->getRenderer(), 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderDrawRect(GW->getRenderer(), &OutlineRect);
	SDL_SetRenderDrawColor(GW->getRenderer(), 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawLine(GW->getRenderer(), 0, GW->getHeight()/2, GW->getWidth(), GW->getHeight()/2);



	return 0;
}

int main(void){
	GameWindow Gwin;
	if(Gwin.InitWindow("test", 750,750)){
		return 1;
	}
	Gwin.runWindow(draw, event);
}

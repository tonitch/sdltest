#include <iostream>
#include <math.h>

#include "GameWindow.hpp"
#include "Character.hpp"

bool drawFirstRun = true;
Character* ply;


bool event(GameWindow* GW){
	SDL_Event e = GW->getEvent();
	if(e.type == SDL_KEYDOWN | e.type == SDL_KEYUP){
		ply->keyIO(&e);
	}
	return 0;
}

bool draw(GameWindow* GW){
	if(drawFirstRun){
		drawFirstRun = false;
		ply = new Character(GW->getRenderer(), "tonitch.png");
	}
	ply->render();
	/* GW->drawText("test",TTF_OpenFont("FiraCode-Medium.ttf", 24), {255,0,0}, {0,0,600,100}); */
	return 0;
}

int main(void){
	GameWindow Gwin;
	if(Gwin.InitWindow("test", 750,750)){
		return 1;
	}
	Gwin.runWindow(draw, event);
	return 0;
}

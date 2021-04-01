#include "GameWindow.hpp"

#include <SDL2/SDL.h>
#include <iostream>

int GameWindow::SendError(const char* type){
	std::cout << type << " Error: " << SDL_GetError() << std::endl;
	return 1;
}

int GameWindow::HandleEvents(bool events(GameWindow* GW)){
	while(SDL_PollEvent(&e)){
		if(e.type == SDL_QUIT){
			QuitWindow();
			return 1;
		}
		events(this);
	}
	return 0;
}

int GameWindow::InitWindow(const char* title ,int nwidth, int nheight){
	width = nwidth;
	height = nheight;
	
	// Init SDL
	if(SDL_Init(SDL_INIT_VIDEO)){
		return SendError("Init");
	}
	
	//Create Window
	win = SDL_CreateWindow(title, 0, 0, width, height, SDL_WINDOW_SHOWN);
	if(win == NULL){
		SDL_Quit();
		return SendError("Window");
	}

	//Create Renderer
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
	if(ren == NULL){
		SDL_Quit();
		SDL_DestroyWindow(win);
		return SendError("Renderer");
	}
	return 0;
}

void GameWindow::runWindow(bool sequence(GameWindow* GW), bool events(GameWindow* GW)){
	while(!quit){
		SDL_SetRenderDrawColor(ren, red, green, blue ,alpha);
		SDL_RenderClear(ren);

		HandleEvents(events);
		
		sequence(this);

		SDL_RenderPresent(ren);
	}
	QuitWindow();
}

void GameWindow::QuitWindow(){
	quit = true;
	SDL_Quit();
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
}

void GameWindow::setBackgroundColor(Uint8 nred, Uint8 ngreen, Uint8 nblue, Uint8 nalpha){
	red = nred;
	green = ngreen;
	blue = nblue;
	alpha = nalpha;
}

SDL_Window* GameWindow::getWindow(){
	return win;
}

SDL_Renderer* GameWindow::getRenderer(){
	return ren;
}

int GameWindow::getWidth(){
	return width;
}

int GameWindow::getHeight(){
	return height;
}

SDL_Event GameWindow::getEvent(){
	return e;
}

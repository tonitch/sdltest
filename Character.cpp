#include "Character.hpp"

Character::Character(SDL_Renderer* iren){
	ren = iren;
	x = 0;
	y = 0; 
	w = 50;
	h = 50;
}

Character::Character(SDL_Renderer* iren, const char* fileavatar){
	ren = iren;
	avatar = IMG_LoadTexture(ren, fileavatar);
	x = 0;
	y = 0; 
}

void Character::render(){
	//TODO
}


void Character::keyIO(SDL_Event* e){
	switch (e->key.keysym.sym){
		case SDLK_z:
			moveUp(10);
		case SDLK_q:
			moveLeft(10);
		case SDLK_s:
			moveDown(10);
		case SDLK_d:
			moveRight(10);
	}
}

void Character::render(){
	return;
}

void Character::moveUp(int dist){x--;}
void Character::moveDown(int dist){x++;}
void Character::moveRight(int dist){y++;}
void Character::moveLeft(int dist){y--;}

SDL_Rect Character::getPlayerRect(){ return {x, y, w, h};}

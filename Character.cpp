#include "Character.hpp"
#include <iostream>
#include <math.h>

void Character::init(SDL_Renderer* iren){
	ren = iren;
	position = Vector2(400,400);
	w = 50;
	h = 50;
	speed = 10;
}
Character::Character(SDL_Renderer* iren){
	init(iren);
}
Character::Character(SDL_Renderer* iren, const char* fileavatar){
	init(iren);
	avatar = IMG_LoadTexture(ren, fileavatar);
}

void Character::render(){

	direction.Normalize();
	updateVelocity();
	updatePosition();

	SDL_Rect playerRect = getPlayerRect();
	if(avatar){
		SDL_RenderCopy(ren, avatar, NULL, &playerRect);
	}else{
		SDL_SetRenderDrawColor(ren, 255,0,0,255);
		SDL_RenderFillRect(ren, &playerRect);
	}
}


void Character::keyIO(SDL_Event* e){
	if(e->type == SDL_KEYDOWN){
		switch (e->key.keysym.sym){
			case SDLK_z:
				moveUp();
				break;
			case SDLK_q:
				moveLeft();
				break;
			case SDLK_s:
				moveDown();
				break;
			case SDLK_d:
				moveRight();
				break;
		}
	}else if(e->type == SDL_KEYUP){
		direction = Vector2();
	}
}

void Character::moveUp(){direction.y = direction.y = -1;};
void Character::moveDown(){direction.y = direction.y = 1;};
void Character::moveLeft(){direction.x = direction.x = -1;};
void Character::moveRight(){direction.x = direction.x = 1;};

void Character::updateVelocity(){
	velocity = direction.mult(Vector2(speed, speed));
}

void Character::updatePosition(){
	position = position.add(velocity);
}

SDL_Rect Character::getPlayerRect(){ return {position.x, position.y, w, h};}

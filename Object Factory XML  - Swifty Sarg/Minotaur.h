#ifndef MINOTAUR_H
#define MINOTAUR_H
#include<iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "Object.h"
#include "Constants.h"

class Texture;

class Minotaur : public Object {
public:
	Minotaur();
	~Minotaur();
	bool Initialize(SDL_Renderer*, std::string);
	void HandleEvent(SDL_Event*);
	void Update();
	void Draw();
protected:
	SDL_Renderer* renderer;
	Texture* texture;
	SDL_Rect clipArray[NUM_SPRITES]; //emily hasnt done her stuff but to get
	//clip array we use art library i am p sure???

	float xPosition;
	float yPosition;
	float angle;

	float rotationAngle;
	float xVelocity;
	float yVelocity;

	Uint32 stepLagCount;
	Uint32 stepCount;
	Uint32 spriteID;
	std::string command;
	TTF_Font* font; //will get fixed if i can figure out why ttf isnt working



};


#endif
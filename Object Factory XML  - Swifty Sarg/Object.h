#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <memory>
#include "SDL.h"

class Texture;

using namespace std;

class Object {
public:
	Object();
	~Object();
	virtual unique_ptr<Object> update() = 0;
	virtual void draw() = 0;
private:
	float x;
	float y;
	float angle;
	float rotationAngle;
	bool inPlay = false;
	SDL_Renderer* renderer;
	Texture* texture;
};
#endif